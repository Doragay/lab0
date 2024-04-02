
#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "win.h"

int main(int argc, char *argv[]) //визуализирует окно и запускает цикл обработки сообщений
{
    QApplication a(argc, argv); //Cоздаем объект

    win win(0);
    win.show();
    return a.exec();
}
