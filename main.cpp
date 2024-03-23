
#include "mainwindow.h"

#include <QApplication>

#include <QLocale>
#include <QTranslator>
#include "win.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "lab0_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    win win(0); //схдание объекта управления окном
    win.show();
    return a.exec();
}
