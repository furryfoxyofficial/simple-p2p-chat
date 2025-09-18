#include "outgoingconnection.h"

OutGoingConnection::OutGoingConnection(QObject *parent)
    : QObject{parent},
    _socket(new QTcpSocket(this))
{
    connect(_socket, &QTcpSocket::readyRead, this, &OutGoingConnection::onReadyRead);
    connect(_socket, &QTcpSocket::connected, this, &OutGoingConnection::onNewConnection);
    connect(_socket, &QTcpSocket::disconnected, this, &OutGoingConnection::onDisconnected);
}

void OutGoingConnection::connect_to_host(const QString& IpAddress, quint16 port) // host = destination
{
    _socket->connectToHost(IpAddress, port);
}

void OutGoingConnection::send_massage_to_host(QString &massage_text) // host = destination
{
    if (_socket->state() == QAbstractSocket::ConnectedState)
        _socket->write(massage_text.toUtf8());
}

QTcpSocket *OutGoingConnection::socket() const // return socket and make it global in app
{
    return _socket;
}

void OutGoingConnection::onReadyRead()
{
    QByteArray data = _socket->readAll();
    emit massage_recieved(QString::fromUtf8(data));
}

void OutGoingConnection::onNewConnection()
{
    emit connected();
}

void OutGoingConnection::onDisconnected()
{
    emit disconnected();
}
