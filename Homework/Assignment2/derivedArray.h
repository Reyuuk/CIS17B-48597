#ifndef DERIVEDARRAY_H
#define DERIVEDARRAY_H

#include <baseArray.h>
#include <QApplication>
#include <QLabel>

using namespace std;

class DerivedArray: public BaseArray
{
public:
    DerivedArray(int row, int col) : BaseArray(row, col){}
    int toPrint();
};

int DerivedArray::toPrint(){
    char* string = this->toString();
    int argc=1;
    char *argv[1]={"1"};

    QApplication app(argc, argv);
    QLabel *label = new QLabel(string);
    label->setWordWrap(true);
    label->show();
    return app.exec();

}

#endif // DERIVEDARRAY_H
