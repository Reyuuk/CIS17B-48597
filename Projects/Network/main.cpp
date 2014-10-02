#include "client.h"
#include "server.h"
#include "networkdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    NetworkDialog diag;
    diag.show();

    Client client;
    client.start("127.0.0.1", 8888);

    Server server;

    return a.exec();
}
