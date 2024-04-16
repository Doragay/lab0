
#include "win.h"
int main(int argc, char *argv[])//визуализирует окно и запускает цикл обработки сообщений
{
    QApplication appl(argc, argv);
    win win;
    win.show();
    return appl.exec();
}
