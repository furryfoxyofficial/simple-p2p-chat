#ifndef OUTGOINGCONNECTION_H
#define OUTGOINGCONNECTION_H

#include <QObject>
#include <QtNetwork/QTcpSocket>

class OutGoingConnection : public QObject
{
    Q_OBJECT
public:
    explicit OutGoingConnection(QObject *parent = nullptr);
    void connect_to_host(const QString &IpAddress, quint16 port = 12345);
    void send_massage_to_host(QString &massage_text);
    void send_ping();
    QTcpSocket* _socket;

signals:
    void massage_recieved(const QString &message);
    void connected();
    void disconnected();

private:

private slots:
    void onReadyRead();
    void onNewConnection();
    void onDisconnected();
};

#endif // OUTGOINGCONNECTION_H
