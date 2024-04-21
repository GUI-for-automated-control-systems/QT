#include "servicewindow.h"
#include "general.h"
#include "rpcbridge.h"

#include <QApplication>
#include <QCommandLineParser>
#include <QtRemoteObjects/QRemoteObjectHost>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    RPCBridge bridge;
    QRemoteObjectHost roHost(QUrl("tcp://localhost:8888"));
    if (!roHost.enableRemoting(&bridge)){
        qDebug() << "Failed to start hosting";
        return -1;
    }
    w.setBridge(&bridge);
    w.show();
    return a.exec();
}
