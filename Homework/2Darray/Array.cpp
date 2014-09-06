//Created by Edgar Gonzalez
//For CIS17B 48597
//Implementation of Array class

#include "Array.h"

#include <ctime> //for random seed

//constructor which takes in only positive rows and columns and
//creates random 2D array with two digit integers
Array::Array(int rows, int cols){

    //validate rows and columns input
    if(rows > 0){
        nRows = rows;}
    else nRows = 1;
    if(cols > 0){
        nCols = cols;}
    else nCols = 1;

    //set random seed for filling array
    srand(static_cast<unsigned int>(time(0)));

    //Declare and allocate 2D array
    array = new int*[nRows];
    for(int row=0; row < nRows; row++){
        array[row] = new int[nCols];
    }

    //fill the array
    for(int row=0; row < nRows; row++){
        for(int col=0; col < nCols; col++){
            array[row][col] = rand()%90+10;
        }
    }
}

//Convert the integer array to formatted char array
char* Array::toString(){

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

//Deallocates memory
Array::~Array(){
    for(int row=0; row<nRows; row++){
        delete []array[row];
    }
    delete []array;
}
