#include <QtGui/QApplication>
#include "glwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GLWindow w;
    w.setMinimumSize(1024, 800);
    w.show();

    return a.exec();
}
