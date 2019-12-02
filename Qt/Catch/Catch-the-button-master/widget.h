#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QSize>
#include <QEvent>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT
    // У�танавливаем �вой�тва чтени� и запи�и
    Q_PROPERTY(QString text READ text WRITE setText)

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void setText(const QString &newText);
    QString text() const { return myText; }
    QSize sizeHint() const;

protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void showEvent(QShowEvent *event);
    void hideEvent(QHideEvent *event);

private:
    QString myText;
    int offset;
    int myTimerId;
};

#endif // WIDGET_H
