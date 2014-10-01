#include "mainwindow.h"
#include "client.h"
#include "server.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    Client client;
    client.start("127.0.0.1", 8888);

    Server server;

    return a.exec();
}
