#ifndef BASEARRAY_H
#define BASEARRAY_H

#include <abstractArray.h>
#include <ctime>    //for random seed
using namespace std;

class BaseArray: public AbstractArray
{
public:
    virtual char* toString();
    BaseArray(int, int);
    ~BaseArray();
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
            sprintf(buffer, "%d",array[row][col]);
            strcat(chArry, buffer);
            strcat(chArry, " ");
        }
        strcat(chArry, "\n");
    }

    return chArry;
}

#endif // BASEARRAY_H
