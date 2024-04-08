#include <win.h>
#include <QHBoxLayout>


win::win(QWidget *parent):QWidget(parent)// Конструктор создает и компанует виджеты
{
this->setWindowTitle("Счетчик");
label1 = new QLabel("Cчет по 1",this); // метка для сетчика edit1
label2 = new QLabel("Cчет по 5",this);
edit1 = new Counter("0",this);//счетчик
edit2 = new Counter("0",this);
calcButton=new QPushButton("+1",this); //кнопка
exitButton=new QPushButton("Выход",this);
edit1->setEnabled(false);
edit2->setEnabled(false);

QHBoxLayout *layout1 = new QHBoxLayout(); //горизонтальный компановщик
layout1->addWidget(label1);
layout1->addWidget(label2);
QHBoxLayout *layout2 = new QHBoxLayout();
layout2->addWidget(edit1);
layout2->addWidget(edit2);
QHBoxLayout *layout3 = new QHBoxLayout();
layout3->addWidget(calcButton);
layout3->addWidget(exitButton);
QVBoxLayout *layout4 = new QVBoxLayout(this); //вертикальный компановщик
layout4->addLayout(layout1);
layout4->addLayout(layout2);
layout4->addLayout(layout3);

// связь сигнала нажатия кнопки и слота закрытия окна
connect(calcButton,&QPushButton::clicked, edit1,&Counter::add_one);
connect(edit1,&Counter::tick_signal,edit2,&Counter::add_one);
connect(exitButton,&QPushButton::clicked,this,&win::close);
}

