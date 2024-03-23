
#include "win.h"

win::win(QWidget *parent): QWidget{parent}
{
    setWindowTitle("Power of 2");
    frame = new QFrame(this); // создаем рамку
    frame->setFrameShadow(QFrame::Raised); //устанавдиваем тень
    frame->setFrameShape(QFrame::Panel); //вид
    inputLabel = new QLabel("Enter Number:", this); //метка
    inputEdit = new QLineEdit("",this); //строчный редактор ввода
    StrValidator *v=new StrValidator(inputEdit); //валидатор
    inputEdit->setValidator(v); //устанавливаем валидатор на ввод
    outputLabel = new QLabel("Result:", this); //метка
    outputEdit = new QLineEdit("",this); // строчный редактор вывода
    nextButton = new QPushButton("Next", this); //кнопки
    exitButton = new QPushButton("Exit", this);
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //рзаметки
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();
    connect(exitButton,SIGNAL(clicked(bool)), //когда нажата кнопка вызода закрываем окно
            this,SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)), // когда нажата кнопка возведения в квадрат
            this,SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()), // когда изменен инпут
            this,SLOT(calc()));
}

void win::begin()
{
    inputEdit->clear(); //при начале очищаем ввод
    nextButton->setEnabled(false);//отключаем кнопку
    nextButton->setDefault(false);
    inputEdit->setEnabled(true);//включаем ввод
    outputLabel->setVisible(false);//скрываем вывод
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();//устанавлен фокус на ввод
}
void win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();//получаем строку
    a=str.toDouble(&Ok);// преобразуем в double
    if (Ok)
    {
        r=a*a;//возводим в квадрат
        str.setNum(r); //устанавливаем в строку
        outputEdit->setText(str); //устанавливаем в текст
        inputEdit->setEnabled(false);//отключаем кнопку
        outputLabel->setVisible(true);//включаем кнопки и вывод
        outputEdit->setVisible(true);
        nextButton->setDefault(true);
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty())
        {
            QMessageBox msgBox(QMessageBox::Information, ("Возведение в квадрат."), ("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec();
        }
}

