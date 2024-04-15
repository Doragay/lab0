
#include "win.h"
int main(int argc, char *argv[])
{
    QApplication appl(argc, argv);
    win win;
    win.show();
    return appl.exec();
}
