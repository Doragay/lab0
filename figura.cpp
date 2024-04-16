#include <math.h>
#include "figura.h"
void Figura::move(float Alpha,QPainter *Painter)
{
    dx=halflen*cos(Alpha);//вычисляем значения изменения движения
    dy=halflen*sin(Alpha);
    draw(Painter);//вызываем функцию рисования
}
void MyLine::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x-dx,y-dy);//Рисование линии между точками
}
void MyRect::draw(QPainter *Painter)
{
    Painter->drawLine(x+dx,y+dy,x+dy,y-dx);
    Painter->drawLine(x+dy,y-dx,x-dx,y-dy);
    Painter->drawLine(x-dx,y-dy,x-dy,y+dx);
    Painter->drawLine(x-dy,y+dx,x+dx,y+dy);
}
