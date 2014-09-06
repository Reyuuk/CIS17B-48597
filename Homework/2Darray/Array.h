//Created by Edgar Gonzalez
//For CIS17B 48597
//Specification file for array class

#ifndef ARRAY_H
#define ARRAY_H

using namespace std;

class Array
{

private:
    int nRows;
    int nCols;
    int **array;

public:
    Array(int rows, int cols);
    char* toString();
    ~Array();
};

#endif // ARRAY_H
