//Created by Edgar Gonzalez
//For CIS17B 48597

#ifndef ABSTRACTARRAY_H
#define ABSTRACTARRAY_H

class AbstractArray
{
protected:
    int nRows;
    int nCols;
    int **array;
public:
    virtual void fillArray(int, int)=0;
};


#endif // ABSTRACTARRAY_H
