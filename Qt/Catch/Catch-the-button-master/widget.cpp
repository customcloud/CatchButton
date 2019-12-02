#include <QtGui>
#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    offset = 0; // Параметр отвечает за перемещение тек�та
    myTimerId = 0;
}

// Перегруженный метод, который позвол�ет у�танавливать тек�т на наш виджет
void Widget::setText(const QString &newText){
    myText = newText;
    update();
    updateGeometry();
}

//Возвращает идиальный размер виджета
QSize Widget::sizeHint() const
{
    //return QSize(300, 300); //check
    //return QSize(300, fontMetrics().height());
    return fontMetrics().size(0, text());
}

// Обработчик �обыти� ри�овани�
void Widget::paintEvent(QPaintEvent * /*event*/){
    QPainter painter(this);
    int textWidth = fontMetrics().width(text());
    if(textWidth < 1){
        return;
    }
    int x = -offset;
    while(x < width()){
        painter.drawText(x, 0, textWidth, height(), Qt::AlignLeft | Qt::AlignVCenter, text());
        x += textWidth;
    }
    //qDebug() << "Переменна� Х = " <<  QString::number(x) << "Переменна� offset = "
    //        << QString::number(-offset) << "X + OFFSET = " << QString::number(x+offset)
    //         << "textWidth = " << textWidth << "myTimerId = " << myTimerId <<  '\n';

}

// Обработчик метода show()
void Widget::showEvent(QShowEvent * /*event*/){
    myTimerId = startTimer(30);
}

// Обработчик таймера
void Widget::timerEvent(QTimerEvent *event){
    if(event->timerId() == myTimerId){
        ++offset;
        // Провер�ем, е�ли �тартова� позици� в пик�ел�х
        // больше ширины тек�та, то мы �тартовую позицию
        // �тарта передвижени� тек�та у�танавливаем на 0
        if(offset >= fontMetrics().width(text()))
            offset = 0;
        scroll(-1, 0);
        //update();
    } else {
        QWidget::timerEvent(event);
    }
}

// Обработчик �понтанного открыти� и �крыти� виджета пользователем
void Widget::hideEvent(QHideEvent */*event*/){
    killTimer(myTimerId);
    myTimerId = 0;
}

Widget::~Widget()
{

}
