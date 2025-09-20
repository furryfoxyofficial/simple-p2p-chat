#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <QDebug>
#include <QRandomGenerator>

#include "connect_to_computer.h"
#include "incommingconnection.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct IpAndPort
{
    QString IpAddress;
    quint16 PortNumber;
};

struct MassageStorage
{
    QString Username;
    QString Massage_text;
};

typedef int USER_ID;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    IncommingConnection *InputTraffic;
    ConnectToComputer *conn;
    USER_ID myid{};

private slots:
    void on_actionAbout_Developer_triggered();
    void on_actionExit_triggered();
    void on_actionConnect_with_Ip_triggered();
    void on_returnkey_Pressed();
    void on_send_btn_clicked();

signals:

private: // methods
    void send_massage();

private:
    Ui::MainWindow *ui;
    QVector<MassageStorage> massage_storage;
};
#endif // MAINWINDOW_H
