//Created by Edgar Gonzalez
//For CIS17B 48597
//This program shows a Qlabel with a 2D array printed.

#include <QApplication>
#include <QLabel>
#include "derivedArray.h"

int main(int argc, char *argv[])
{
    int row = 10;
    int col = 5;
    Array arry(row, col);

    char* string = arry.toString();

    QApplication app(argc, argv);
    QLabel *label = new QLabel(string);
    label->setWordWrap(true);
    label->show();
    return app.exec();
}
