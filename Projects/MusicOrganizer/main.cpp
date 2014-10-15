#include "musicorganizer.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MusicOrganizer w;
    w.show();



    return a.exec();
}
