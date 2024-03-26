
#include "win.h"

win::win(QWidget *parent): QWidget{parent}
{
    setWindowTitle("Power of 2"); // свойство окна
    frame = new QFrame(this); // создаем рамку
    frame->setFrameShadow(QFrame::Raised); //устанавливаем тень
    frame->setFrameShape(QFrame::Panel); //вид окна
    inputLabel = new QLabel("Enter Number:", this);
    inputEdit = new QLineEdit("",this); //строчный редактор ввода
    StrValidator *v=new StrValidator(inputEdit);
    inputEdit->setValidator(v); //устанавливаем валидатор на ввод
    outputLabel = new QLabel("Result:", this); //метка
    outputEdit = new QLineEdit("",this); // строчный редактор вывода
    nextButton = new QPushButton("Next", this); //кнопки
    exitButton = new QPushButton("Exit", this);
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //разметки сверху вниз
    vLayout1->addWidget(inputLabel);
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch(); //растянуть
    QVBoxLayout *vLayout2 = new QVBoxLayout(); //сверху вниз кнопки
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this); // разметки слева направо
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin();
    connect(exitButton,SIGNAL(clicked(bool)),
            this,SLOT(close()));
    connect(nextButton,SIGNAL(clicked(bool)),
            this,SLOT(begin()));
    connect(inputEdit,SIGNAL(returnPressed()),
            this,SLOT(calc()));
}

void win::begin()
{
    inputEdit->clear(); //при начале очищаем ввод
    nextButton->setEnabled(false);//отключаем кнопку
    nextButton->setDefault(false); //отрубили кнопку
    inputEdit->setEnabled(true); //включаем ввод
    outputLabel->setVisible(false);//скрываем вывод
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);
    inputEdit->setFocus();//устанавлен фокус на ввод
}
void win::calc()
{
    bool Ok=true; float r,a;
    QString str=inputEdit->text();
    a=str.toDouble(&Ok);
    if (Ok)
    {
        r=a*a;
        str.setNum(r);
        outputEdit->setText(str); //устанавливаем в текст
        inputEdit->setEnabled(false);//отключаем кнопку
        outputLabel->setVisible(true);//включаем кнопки и вывод
        outputEdit->setVisible(true);
        nextButton->setDefault(true); // включаем кнопку
        nextButton->setEnabled(true);
        nextButton->setFocus();
    }
    else
        if (!str.isEmpty()) //если строка пустая
        {
            QMessageBox msgBox(QMessageBox::Information, ("Возведение в квадрат."), ("Введено неверное значение."),
                               QMessageBox::Ok);
            msgBox.exec(); //показать
        }
}

