#ifndef WIN_H
#define WIN_H
#include <QtGui>
#include "area.h"
class win : public QWidget
{
protected:
    Area * area; // область отображения рисунка
    QPushButton * btn;
public:
   win();
};
#endif
