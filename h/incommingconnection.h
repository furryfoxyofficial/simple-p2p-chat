#ifndef INCOMMINGCONNECTION_H
#define INCOMMINGCONNECTION_H

#include <QObject>

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#include <QtNetwork/QHostAddress>

class IncommingConnection : public QObject
{
    Q_OBJECT
public:
    explicit IncommingConnection(QObject *parent = nullptr);
    void startListening(quint16 port = 12345);
    QTcpSocket* socket() const;

signals:
    void onMassageReceived(const QString &massage_txt);
    void clientConnected();
    void clientDisonnected();

private: //fields
    QTcpServer *_server;
    QTcpSocket *_clientSocket;

private slots:
    void onNewConnection();
    void onReadyRead();
    void onDisconnected();
};

#endif // INCOMMINGCONNECTION_H
