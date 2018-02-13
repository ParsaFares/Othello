#include "AI.h"

AI::AI(int gameStatus) {
    player = gameStatus;
}

void AI::makeTurn(Board *map) {
    Point richestTile = getRichestTile(map);
    LineChecker lines(player, richestTile, map->fieldStatus);

    QList<Point> modifiedCells = lines.getActiveTiles();
    for (int i = 0; i < modifiedCells.size(); i++) {
        map->fieldStatus[modifiedCells.at(i).x][modifiedCells.at(i).y] = player;
    }
}

Point AI::getRichestTile(Board *map) {
    int richestTileCount = 0;
    Point richestTile = Point(0, 0);
    for (int i = 0; i < 8 ; i++) {
        for (int j = 0; j < 8 ; j++) {
            if (map->fieldStatus[i][j] == 0) {
                Point point(i, j);
                LineChecker test(player, Point(i, j), map->fieldStatus);
                if (test.getActiveTiles().size() > richestTileCount) {
                    //corner points are more important
                    if (point == Point(0, 0)
                        || point == Point(8, 0)
                        || point == Point(8, 8)
                        || point == Point(0, 8)) {
                        return point;
                    }
                    richestTileCount = test.getActiveTiles().size();
                    richestTile = Point(i, j);
                }
            }
        }
    }
    return richestTile;
}