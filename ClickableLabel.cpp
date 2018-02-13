#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(int x, int y, QWidget * parent) :
        QLabel(parent) {
    this->xAssis = x;
    this->yAssis = y;
    //distance from left top point of parent widget
    int j = 65 + ((CHIP_SIZE)*x);
    int i = 35 + ((CHIP_SIZE)*y);
    this->setGeometry(i, j, CHIP_SIZE, CHIP_SIZE);
}

void ClickableLabel::mousePressEvent(QMouseEvent * event) {
    emit clicked(xAssis, yAssis);
}

ClickableLabel::~ClickableLabel(){
    this->hide();
}