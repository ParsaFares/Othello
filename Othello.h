#ifndef OTHELLO_OTHELLO_H
#define OTHELLO_OTHELLO_H

#include <QWidget>
#include <qthread.h>

#include "MainWindow.h"
#include "ClickableLabel.h"
#include "AI/AI.h"
#include "AI/Point.h"
#include "AI/Board.h"
#include "AI/LineChecker.h"

class Othello : public QWidget {
Q_OBJECT
public:
    Othello(MainWindow *parent = 0);
    ~Othello();
    void newGame();
    void changeShowHint();

private:
    MainWindow *main;
    Board *map;

    void configureInterface();
    bool checkForLegalTurns();
    void changePlayer(int skippedTurns);
    void refreshField();

    bool gameOver;
    bool showHints;
    int gameStatus;
    ClickableLabel ***gamingField;
    QString *gameScore;

    QImage *whiteImg;
    QImage *blackImg;
    QImage *blankImg;
    QImage *activeImg;

public slots:
    void cellClicked(int x, int y);
};

#endif //OTHELLO_OTHELLO_H
