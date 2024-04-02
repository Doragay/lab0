
#include "win.h"

win::win(QWidget *parent): QWidget{parent} //конструктор создает все необходимые объекты и строит окно и компановку
{
    setWindowTitle("Power of 2"); // метод который устанавливает заголовок окна
    frame = new QFrame(this); // создаем рамку
    frame->setFrameShadow(QFrame::Raised); //устанавливаем тень
    frame->setFrameShape(QFrame::Panel); //вид окна
    inputLabel = new QLabel("Enter Number:", this); //метка ввода
    inputEdit = new QLineEdit("",this); //строчный редактор ввода
    StrValidator *v=new StrValidator(inputEdit); //создаем валидатор и, привязываем.
    inputEdit->setValidator(v); //устанавливаем валидатор на ввод
    outputLabel = new QLabel("Result:", this);
    outputEdit = new QLineEdit(" ",this);
    nextButton = new QPushButton("Next", this);
    exitButton = new QPushButton("Exit", this);
    QVBoxLayout *vLayout1 = new QVBoxLayout(frame); //Компановщик сверху вниз
    vLayout1->addWidget(inputLabel);//Добавляем метку ввода
    vLayout1->addWidget(inputEdit);
    vLayout1->addWidget(outputLabel);
    vLayout1->addWidget(outputEdit);
    vLayout1->addStretch();
    QVBoxLayout *vLayout2 = new QVBoxLayout();
    vLayout2->addWidget(nextButton);
    vLayout2->addWidget(exitButton);
    vLayout2->addStretch();
    QHBoxLayout *hLayout = new QHBoxLayout(this); //Компановщик слева направо
    hLayout->addWidget(frame);
    hLayout->addLayout(vLayout2);
    begin(); //вызываем начальный вид окна
    connect(exitButton, &QPushButton::clicked, this, &win::close);
    connect(nextButton, &QPushButton::clicked, this, &win::begin);
    connect(inputEdit, &QLineEdit::returnPressed, this, &win::calc);
}
void win::begin() //определяем начальный вид окна
{
    inputEdit->clear();
    nextButton->setEnabled(false);//отключаем кнопку
    nextButton->setDefault(false); //обрубили кнопку
    inputEdit->setEnabled(true);//включаем ввод
    outputLabel->setVisible(false); //скрываем вывод
    outputEdit->setVisible(false);
    outputEdit->setEnabled(false);//отключаем возможность редактирования поля вывода
    inputEdit->setFocus();
}
void win::calc()//определяем метод вычисление
{
    bool Ok=true; float r,a;// объявление переменных
    QString str=inputEdit->text();//преобразуем строку в число
    a=str.toDouble(&Ok);
    if (Ok)
    {
        r=a*a;
        str.setNum(r); //устанавливаем число в строку
        outputEdit->setText(str); //устанавливаем в текст ввывода
        inputEdit->setEnabled(false);//отключаем поле ввод
        outputLabel->setVisible(true);//Метку вывода делаем видимой
        outputEdit->setVisible(true); //Поле вывода делаем видимым
        nextButton->setDefault(true); // включаем кнопку
        nextButton->setEnabled(true); // можем тыкать на кнопку
        nextButton->setFocus(); //подсвечиваем кнопку
    }
    else
        if (!str.isEmpty()) //если строка не пустая, выводится сообщение об ошибке.
        {
            QMessageBox msgBox(QMessageBox::Information, ("Возведение в квадрат."), ("Введено неверное значение."),
                               QMessageBox::Ok);// кнопка
            msgBox.exec();

        }
}

