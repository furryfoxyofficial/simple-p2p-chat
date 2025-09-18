#include "incommingconnection.h"

IncommingConnection::IncommingConnection(QObject *parent)
    : QObject{parent}
    , _server(new QTcpServer(this))
    , _clientSocket(nullptr)
{
    connect(_server, &QTcpServer::newConnection, this, &IncommingConnection::onNewConnection);
}

void IncommingConnection::startListening(quint16 port)
{
    if (!_server->listen(QHostAddress::AnyIPv4, port))
        qWarning() << "Server failed to start listening on port" << port << ":" << _server->errorString();
}

QTcpSocket *IncommingConnection::socket() const
{
    return _clientSocket;
}

void IncommingConnection::onNewConnection()
{
    _clientSocket = _server->nextPendingConnection();
    connect(_clientSocket, &QTcpSocket::readyRead, this, &IncommingConnection::onReadyRead);
    connect(_clientSocket, &QTcpSocket::disconnected, this, &IncommingConnection::onDisconnected);
    emit clientConnected();
}

void IncommingConnection::onReadyRead()
{
    QByteArray data = _clientSocket->readAll();
    emit onMassageReceived(QString::fromUtf8(data));
}

void IncommingConnection::onDisconnected()
{
    _clientSocket->deleteLater();
    _clientSocket = nullptr;
    emit clientDisonnected();
}
