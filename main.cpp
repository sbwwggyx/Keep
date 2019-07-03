#include "maps.h"
#include "begindialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Maps w;
    w.resize(1024,768);
    w.setMinimumSize(1024,768);
    w.setMaximumSize(1024,768);
    w.move(400,100);
    w.setWindowTitle("Peace Game Pro");
    w.show();
    return a.exec();
}
