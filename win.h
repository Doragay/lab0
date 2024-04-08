#ifndef win_h
#define win_h
#include <QtGui>
#include <QWidget>
#include <QString>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class Counter: public QLineEdit
{
    Q_OBJECT
public:
    Counter(const QString &contents, QWidget *parent=0):
        QLineEdit(contents,parent){}//конструктор

signals:
    void tick_signal();
public slots:
    void add_one()
    {
        QString str=text();// получаем текст
        int r=str.toInt();// преобразуем строку в целое число
        r++;
        if (r!=0 && r%5 ==0) emit tick_signal(); //если r не равно нулю и остаток от деления r на 5 равен нулю, то генерируется


        str.setNum(r); //преобразуем число в строку
        setText(str); //устанавливаем текст в строку
    }
};
class win: public QWidget
{
    Q_OBJECT
public:
    win(QWidget *parent = 0);
protected:
    QLabel *label1,*label2;
    Counter *edit1,*edit2;
    QPushButton *calcButton;
    QPushButton *exitButton;
};
#endif
