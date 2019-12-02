#include <QApplication>
#include "widget.h"
#include "catchbutton.h"

#include <QVBoxLayout>

int main(int lArgc, char *lArgv[])
{
    QApplication lApplication(lArgc, lArgv);
    CatchButton *button = new CatchButton;
    Widget *w = new Widget;
    Widget *w2 = new Widget;

    w->setText(" CATCH !!!");
    w2->setText(" CATCH !!!");
    //button.show();
    //w.show();
    QWidget *window = new QWidget;

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(w);
    layout->addWidget(button);
    layout->addWidget(w2);

    window->setLayout(layout);
    QObject::connect(button,SIGNAL(kill()),qApp,SLOT(quit()));

    window->show();

    return lApplication.exec();
}
