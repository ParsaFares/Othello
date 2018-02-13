#include "Othello.h"

#include <qmessagebox.h>

#define WHITE_PLAYER_TURN -1
#define BLACK_PLAYER_TURN 1

Othello::Othello(MainWindow *parent) : QWidget() {
    main = parent;
    gameStatus = WHITE_PLAYER_TURN;
    showHints = true;
    gameOver = false;

    configureInterface();
    newGame();
}

void Othello::newGame(){
    map = new Board();

    gameOver = false;
    gameStatus = WHITE_PLAYER_TURN;
    refreshField();
    changePlayer(0);
}

void Othello::configureInterface() {
    //some changes happen with this obj :D
    ui.setupUi(this);
    this->setFixedSize(470, 470);
    gameScore = new QString("");


    whiteImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
    whiteImg->load("/Users/parsa/Desktop/UTAPProj./Othello/resources/white.png");

    blackImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
    blackImg->load("/Users/parsa/Desktop/UTAPProj./Othello/resources/black.png");

    blankImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
    blankImg->load("/Users/parsa/Desktop/UTAPProj./Othello/resources/blank.png");

    activeImg = new QImage(QSize(50, 50), QImage::Format_RGB16);
    activeImg->load("/Users/parsa/Desktop/UTAPProj./Othello/resources/active.png");

    gamingField = new ClickableLabel**[8];
    for (int i = 0; i < 8; i++) {
        gamingField[i] = new ClickableLabel*[8];
        for (int j = 0; j < 8; j++) {
            gamingField[i][j] = new ClickableLabel(i, j, this);
            gamingField[i][j]->setStyleSheet("background-color:QColor(107 , 170 , 250) ; border: 0.5px solid black");
            QObject::connect(gamingField[i][j], SIGNAL (clicked(int, int)),
                             this, SLOT (cellClicked(int, int)));
        }
    }
}

void Othello::refreshField() {
    QImage *figure;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            switch (map->fieldStatus[i][j]) {
                case WHITE_PLAYER_TURN:
                    figure = whiteImg;
                    break;
                case BLACK_PLAYER_TURN:
                    figure = blackImg;
                    break;
                default:
                    figure = blankImg;
                    break;
            }
            gamingField[i][j]->setPixmap(QPixmap::fromImage(*figure));
        }
    }

    map->setScore();
    *gameScore = QString(" Black: %1 | White: %2").arg(map->blackChipCount).arg(map->whiteChipCount);
    ui.gameScore->setText(QString::number(map->blackChipCount-map->whiteChipCount));
}

bool Othello::checkForLegalTurns() {
    bool noLegalTurns = map->noLegalTurns(gameStatus);
    if(noLegalTurns || !showHints){
        return noLegalTurns;
    }

    QList<Point> hintList = map->getActiveTiles(gameStatus);
    for (int t = 0; showHints && t < hintList.size(); t++) {
        int x = hintList.at(t).x;
        int y = hintList.at(t).y;
        if(!map->fieldStatus[x][y]){
            gamingField[x][y]->setPixmap(QPixmap::fromImage(*activeImg));
        }
    }
    return noLegalTurns;
}

void Othello::changePlayer(int skippedTurns) {
    switch (gameStatus *= -1/*change turn*/) {
        case WHITE_PLAYER_TURN:
        {
            QString result1 = QString("White player\'s turn");
            result1.append(gameScore);
            main->setStatusBar(&result1);
            break;
        }
        case BLACK_PLAYER_TURN:
        {
            QString result2 = QString("Black player\'s turn");
            result2.append(gameScore);
            main->setStatusBar(&result2);
            break;
        }
    }
    if (checkForLegalTurns() && skippedTurns < 1) {
        changePlayer(1);
    } else if (checkForLegalTurns() && skippedTurns > 0) {
        QString result3 = QString("Game over");
        result3.append(gameScore);
        main->setStatusBar(&result3);
        skippedTurns++;
    }

    switch (skippedTurns) {
        case 1:{
            QMessageBox msgBox1;
            switch(gameStatus*(-1)){
                case WHITE_PLAYER_TURN:
                    msgBox1.setText("White player skips a turn");
                    break;
                case BLACK_PLAYER_TURN:
                    msgBox1.setText("Black player skips a turn");
                    break;
            }
            msgBox1.exec();
            return;
        }
        case 2:{
            QMessageBox msgBox2;
            if((map->blackChipCount-map->whiteChipCount)< 0){
                msgBox2.setText("White player wins");
            }
            else if((map->blackChipCount-map->whiteChipCount)>0){
                msgBox2.setText("Black player wins");
            }
            else {
                msgBox2.setText("Its a draw");
            }

            msgBox2.setInformativeText(*gameScore);
            msgBox2.exec();
            gameOver = true;
            return;
        }
    }

    //AI makes a turn and call this func with 0
    if(gameStatus==WHITE_PLAYER_TURN && !gameOver){
        AI *bot = new AI(gameStatus);
        bot->makeTurn(map);
        refreshField();
        changePlayer(0);
    }
}

void Othello::cellClicked(int x, int y) {
    LineChecker lines(gameStatus, Point(x, y), map->fieldStatus);
    if (map->fieldStatus[x][y] == 0) {
        QList<Point> modifiedCells = lines.getActiveTiles();
        if ((modifiedCells.size() > 0)) {
            for (int i = 0; i < modifiedCells.size(); i++) {
                map->fieldStatus[modifiedCells.at(i).x][modifiedCells.at(i).y] =
                        gameStatus;
            }
            refreshField();
            changePlayer(0);
        }
    }
}

void Othello::changeShowHint(){
    showHints = !showHints;
    refreshField();
    if(showHints){
        checkForLegalTurns();
    }
}

Othello::~Othello() {
    for (int i = 0; i < 8; i++) {
        delete[] gamingField[i];
    }
    delete[] gamingField;

    delete map;
    delete gameScore;

    delete whiteImg;
    delete blackImg;
    delete blankImg;
}