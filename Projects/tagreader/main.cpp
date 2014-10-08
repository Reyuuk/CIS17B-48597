#include "tagreader.h"
#include <QApplication>
#define ID3LIB_LINKOPTION LINKOPTION_STATIC
#include "iostream"
#include <id3/tag.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    tagreader w;
    w.show();


    /*ID3_Tag mytag(fileName);

    ID3_Frame *title = mytag.Find(ID3FID_TITLE);
    if(title != NULL){
        std::cout << title;
    }*/

    return a.exec();
}


