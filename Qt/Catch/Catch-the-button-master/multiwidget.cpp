#include "multiwidget.h"
#include <QVBoxLayout>

MultiWidget::MultiWidget(QWidget *parent)
 : QWidget(parent) {
   combo = new QComboBox();
   list  = new QListWidget();
   // create the appropriate layout
   // add the widgets to it
   QVBoxLayout *layout = new QVBoxLayout;

   setLayout(layout);
}
