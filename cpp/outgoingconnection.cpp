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

void OutGoingConnection::send_ping()
{
    if (!_socket || _socket->state() == QAbstractSocket::ConnectedState)
        return;

    _socket->write("PING\n");
    _socket->flush();
}

void OutGoingConnection::onReadyRead()
{
    QByteArray data = _socket->readAll();
    QString msg = QString::fromUtf8(data).trimmed();

    if (msg == "ACCEPT")
    {
        qDebug() << "peer accepted connection";
        emit connected();
    }
    else if (msg == "REJECT")
    {
        qDebug() << "peer rejected connection";
        emit disconnected();
    }
    else
    {
        emit massage_recieved(msg);
    }
}

void OutGoingConnection::onNewConnection()
{
    emit connected();
}

void OutGoingConnection::onDisconnected()
{
    emit disconnected();
}
