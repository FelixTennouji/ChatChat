#include "mini.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Mini w;
    w.show();
    return a.exec();
}
