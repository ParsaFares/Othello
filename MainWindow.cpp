#include <QtWidgets>

#include "MainWindow.h"
#include "Othello.h"

MainWindow::MainWindow() : QMainWindow()
{
    centralWidget = new Othello(this);
    setCentralWidget(centralWidget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    createActions();
    createMenus();

    QString message = tr("Game Started!");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Othello"));
    this->setFixedSize(470, 500);
}

void MainWindow::setStatusBar (QString *string){
    statusBar()->showMessage(*string);
}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.exec(event->globalPos());
}

void MainWindow::newGame()
{
    Othello *othello = (Othello *)centralWidget;
    othello->newGame();
}

void MainWindow::disableTips()
{
    Othello *othello = (Othello *)centralWidget;
    othello->changeShowHint();
}

void MainWindow::createActions()
{
    newG = new QAction(tr("&NewGame"), this);
    newG->setShortcuts(QKeySequence::New);
    newG->setStatusTip(tr("Start a new game"));
    connect(newG, &QAction::triggered, this, &MainWindow::newGame);

    exitGame = new QAction(tr("E&xit"), this);
    exitGame->setShortcuts(QKeySequence::Quit);
    exitGame->setStatusTip(tr("Exit the game"));
    connect(exitGame, &QAction::triggered, this, &QWidget::close);

    tip = new QAction(tr("&Disable/Enable tips"), this);
    tip->setStatusTip(tr("Disable game tips"));
    connect(tip, SIGNAL(triggered()), this, SLOT(disableTips()));
}

void MainWindow::createMenus()
{
    options = menuBar()->addMenu(tr("&Settings"));
    options->addAction(newG);
    options->addSeparator();
    options->addAction(tip);
    options->addSeparator();
    options->addAction(exitGame);
}