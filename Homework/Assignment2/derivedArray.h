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
    void toPrint();
};

void DerivedArray::toPrint(){

}

#endif // DERIVEDARRAY_H
