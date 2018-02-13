#ifndef OTHELLO_MAINWINDOW_H
#define OTHELLO_MAINWINDOW_H

#include <QMainWindow>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    MainWindow();
    ~MainWindow(){};
    void setStatusBar (QString *string);

protected:
    void contextMenuEvent(QContextMenuEvent *event);

private slots:
    void newGame();
    void disableTips();

private:
    void createActions();
    void createMenus();

    QWidget *centralWidget;
    QMenu *options;
    QAction *newG;
    QAction *exitGame;
    QAction *tip;
};

#endif //OTHELLO_MAINWINDOW_H
