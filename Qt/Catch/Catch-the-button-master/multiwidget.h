#ifndef MULTIWIDGET_H
#define MULTIWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QListWidget>

class MultiWidget;

class MultiWidget: public QWidget
{
    Q_OBJECT

public:
    MultiWidget(QWidget *parent = nullptr);

private:
    QComboBox *combo;
    QListWidget *list;
};

#endif // MULTIWIDGET_H
