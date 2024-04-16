#include "area.h"
Area::Area(QWidget *parent):QWidget(parent)
{
    setFixedSize(QSize(300,200));
    myline=new MyLine(80,100,50);
    myrect=new MyRect(220,100,50);
    alpha=0;
}
void Area::showEvent(QShowEvent *)
{
    myTimer=startTimer(50); // создать таймер
}
void Area::paintEvent(QPaintEvent *)//Определение функции paintEvent, которая вызывается при необходимости перерисовки виджета.
{
    QPainter painter(this);
    painter.setPen(Qt::red);
    myline->move(alpha,&painter);
    myrect->move(alpha*(-0.5),&painter);
}
void Area::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == myTimer) // проверем номер таймера, чтобы быть увереным, что событие от нужного тамера
    {
        alpha=alpha+0.2;
        update(); // обновить внешний вид, перерисовку окна. Метод сам определяет целесообразность немедленной перерисовки, приспосабливаясь к скорости изменения рисунка
    }
    else
        QWidget::timerEvent(event); // иначе передать для стандартной обработки
}
void Area::hideEvent(QHideEvent *)
{
    killTimer(myTimer); // уничтожить таймер
}
Area::~Area()
{
    delete myline;
    delete myrect;
}
