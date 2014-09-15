//Created by Edgar Gonzalez
//For CIS17B 48597

#ifndef ABSTRACTARRAY_H
#define ABSTRACTARRAY_H

#include <ctime>    //for random seed
using namespace std;

class AbstractArray
{
protected:
    int nRows;
    int nCols;
    int **array;
public:
    void fillArray(int, int);
    virtual char* toString()=0;
};

void AbstractArray::fillArray(int rows, int cols){
    //validate rows and cols input
    if(rows > 0){
        nRows = rows;
    }
    else nRows = 1;
    if(cols > 0){
        nCols = cols;
    }
    else nCols = 1;

    srand(static_cast<unsigned int>(time(0)));

    array = new int*[nRows];
    for(int row=0; row < nRows; row++){
        array[row] = new int[nCols];
    }

    for(int row=0; row < nRows; row++){
        for(int col=0;col < nCols; col++){
            array[row][col] = rand()%90+10;
        }
    }
}


#endif // ABSTRACTARRAY_H
