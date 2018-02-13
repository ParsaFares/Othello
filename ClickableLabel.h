#ifndef OTHELLO_CLICKABLELABEL_H
#define OTHELLO_CLICKABLELABEL_H

#include <QLabel>
#define CHIP_SIZE 50

//derived class from qlabel with click signal and coordinates
class ClickableLabel : public QLabel{
Q_OBJECT
public:
    ClickableLabel(int x, int y, QWidget * parent = 0);
    ~ClickableLabel();

signals:
    void clicked(int x, int y);

protected:
    int xAssis;
    int yAssis;
    void mousePressEvent(QMouseEvent * event);
};

#endif //OTHELLO_CLICKABLELABEL_H
