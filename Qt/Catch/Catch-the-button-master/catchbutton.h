#ifndef CATCHBUTTON_H
#define CATCHBUTTON_H

#include <QWidget>
#include <QEvent>
#include <QSize>

class QPushButton;

class CatchButton : public QWidget
{
    Q_OBJECT
public:
    explicit CatchButton(QWidget *parent = nullptr);

protected:
    virtual void mouseMoveEvent(QMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent(QMouseEvent *mouseEvent);

private:
    void init();
    bool hasButton(int mouseX, int mouseY);
    void moveButton();
    QSize sizeHint() const;
 public slots:
    void handleButton();
  signals:
    void kill();



public:
    QPushButton* mButton;
};

#endif // CATCHBUTTON_H
