#include "catchbutton.h"
#include <QMouseEvent>
#include <QDebug>
#include <QPushButton>
#include <QRandomGenerator>

const int saveDistanceForCursor = 5;

CatchButton::CatchButton(QWidget *parent) : QWidget(parent)
{
    init();
}

void CatchButton::handleButton() {
    emit kill();
}

void CatchButton::mouseMoveEvent(QMouseEvent *mouseEvent)
{

    if(hasButton(mouseEvent->x(), mouseEvent->y()))
    {
        moveButton();
    }

}

void CatchButton::mouseReleaseEvent(QMouseEvent *mouseEvent) {
    if (mouseEvent->button() == Qt::LeftButton) {
        if(hasButton(mouseEvent->x(), mouseEvent->y()))
        {
            throw 1;
        }
    }
}

void CatchButton::init()
{
    setGeometry(x(), y(), 100, 100);
    setWindowTitle("CATCH !!!");
    setMouseTracking(true);

    mButton = new QPushButton(this);
    mButton-> move((this->width() - mButton->width()) / 2 , (this->height() - mButton->height()) / 2);
    mButton->setText("CATCH !!!");
    connect(mButton, SIGNAL (clicked()),this, SLOT (handleButton()));
}

void CatchButton::moveButton()
{
    int xRandomPos, yRandomPos;

    xRandomPos=QRandomGenerator::global()->bounded(this->width() - mButton->width());
    yRandomPos=QRandomGenerator::global()->bounded(this->height() - mButton->height());
    mButton->move(xRandomPos, yRandomPos);
    if(hasButton(this->cursor().pos().x(), this->cursor().pos().y()))
    {
        moveButton();
    }
}

bool CatchButton::hasButton(int mouseX, int mouseY)
{
    bool hasButton =(mouseX + saveDistanceForCursor) >= mButton->x() &&
            mouseX <= (mButton->x() + mButton->width()) &&
            (mouseY + saveDistanceForCursor) >= mButton->y() &&
            mouseY <= (mButton->y() + mButton->height());

    return hasButton;
}

//Возвращает идиальный размер виджета
QSize CatchButton::sizeHint() const
{
    return QSize(300, 300); //check
    //return QSize(300, fontMetrics().height());
}


