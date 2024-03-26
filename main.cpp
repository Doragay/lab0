
#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "win.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    win win(0);
    win.show();
    return a.exec();
}
