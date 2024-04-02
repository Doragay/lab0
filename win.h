#ifndef WIN_H
#define WIN_H

#include <QTWidgets>
#include <QValidator>

class win: public QWidget
{
    Q_OBJECT
public:
    win(QWidget *parent = 0);  //конструктор
private:
    QFrame *frame; // рамка
    QLabel *inputLabel; // метка ввода
    QLineEdit *inputEdit; // строчный редактор ввода
    QLabel *outputLabel; // метка вывода
    QLineEdit *outputEdit; // строчный редактор вывода
    QPushButton *nextButton; // кнопка Следующее
    QPushButton *exitButton; // кнопка Выход

public slots:
    void begin(); //метод начальной настройки интерфейса(окошки)
    void calc(); //метод реализации вычислений
};

class StrValidator:public QValidator { //класс компонента проверки ввода
public:
    StrValidator(QObject *parent):QValidator(parent) {}
    virtual State validate(QString &str, int &pos) const {
        qDebug () << "Метод валидэйт вызван";
        return Acceptable; //метод всегда принимает вводимую строку
    }
};
#endif
