#include <server.h>

Server::Server()
{
    if(this->listen(QHostAddress::Any, 2323))
    {
        qDebug() << "start";
    }
    else
    {
        qDebug() << "Server error";
    }
}

void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);
    connect(socket, &QTcpSocket::readyRead, this, &Server::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &QTcpSocket::deleteLater);

    Sockets.push_back(socket);
    qDebug() << "Client connected successfuly";
}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);     // работа с данными сокета
    in.setVersion(QDataStream::Qt_6_2);
    if (in.status() == QDataStream::Ok)
    {
        qDebug() << "Read data";
        QString string;
        in >> string;
        qDebug() << string;
        sendToClient(string);
    }
    else
    {
        qDebug() << "Stream error!";
    }
}

void Server::sendToClient(QString message)
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_2);
    out << message;
    for (int i = 0; i < Sockets.size(); i++){
        Sockets[i]->write(Data);
    }
}



