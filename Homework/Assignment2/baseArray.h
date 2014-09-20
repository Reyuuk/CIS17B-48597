#ifndef BASEARRAY_H
#define BASEARRAY_H

#include <abstractArray.h>
#include <ctime>    //for random seed
using namespace std;

class BaseArray: public AbstractArray
{
public:
    char* toString();
    BaseArray(int, int);
    ~BaseArray();
    virtual void fillArray(int, int);
};

BaseArray::BaseArray(int row, int col){
    fillArray(row, col);
}

BaseArray::~BaseArray(){
    for(int row=0; row<nRows; row++){
        delete []array[row];
    }
    delete []array;
}

char* BaseArray::toString(){

    //Allocates space for the char array
    //3* is for 2 digits, and one whitespace
    //nCols + 1 is to leave a newline at the end of each col
    //+1 for null terminator
    char* chArry = new char[((3*nRows*(nCols+1))+1)];

    //begin with null char array, concatenate array to it.
    chArry[0] = '\0';
    for(int row=0; row<nRows; row++){
        for(int col=0; col<nCols;col++){
            char buffer[3];
            sprintf_s(buffer, "%d",array[row][col]);
            strcat(chArry, buffer);
            strcat(chArry, " ");
        }
        strcat(chArry, "\n");
    }

    return chArry;
}


void BaseArray::fillArray(int rows, int cols){
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



#endif // BASEARRAY_H
