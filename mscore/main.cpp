#include "mpmusepad.h"
#include "shortcut.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MusePad w;
    w.show();
    //tEST git

    return a.exec();
}
