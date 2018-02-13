#ifndef OTHELLO_OTHELLOUI_H
#define OTHELLO_OTHELLOUI_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QHeaderView>
#include <QLabel>
#include <QWidget>

QT_BEGIN_NAMESPACE

class OthelloUI {
public:
    QLabel *gameStatus;
    QLabel *gameScore;
    QLabel *lscore;

    void setupUi(QWidget *OthelloUI){
        if (OthelloUI->objectName().isEmpty())
            OthelloUI->setObjectName(QString::fromUtf8("OthelloUI"));
        OthelloUI->setEnabled(true);
        OthelloUI->resize(474, 466);
        gameStatus = new QLabel(OthelloUI);
        gameStatus->setObjectName(QString::fromUtf8("gameStatus"));
        gameStatus->setGeometry(QRect(40, 20, 160, 30));
        gameScore = new QLabel(OthelloUI);
        gameScore->setObjectName(QString::fromUtf8("gameScore"));
        gameScore->setGeometry(QRect(410, 20, 160, 30));
        lscore = new QLabel(OthelloUI);
        lscore->setObjectName(QString::fromUtf8("lscore"));
        lscore->setGeometry(QRect(350, 20, 160, 30));

        retranslateUi(OthelloUI);

        QMetaObject::connectSlotsByName(OthelloUI);
    };

    void retranslateUi(QWidget *OthelloUI){
        OthelloUI->setWindowTitle(QApplication::translate("OthelloUI", "Othello", 0));
        gameStatus->setText(QApplication::translate("OthelloUI", "Black player's turn", 0));
        gameScore->setText(QString());
        lscore->setText(QApplication::translate("OthelloUI", "Score:", 0));
    };
};

QT_END_NAMESPACE

#endif //OTHELLO_OTHELLOUI_H
