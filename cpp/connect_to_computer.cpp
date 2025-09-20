#include "connect_to_computer.h"
#include "ui_connect_to_computer.h"

ConnectToComputer::ConnectToComputer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ConnectToComputer)
{
    ui->setupUi(this);
    setWindowTitle("Enter your IP Address and Port Number");
    setFixedSize(371,153);
}

ConnectToComputer::~ConnectToComputer()
{
    delete ui;
}

void ConnectToComputer::on_CancelBtn_clicked()
{
    this->close();
}


void ConnectToComputer::on_ConnectBtn_clicked()
{
    outconn = new OutGoingConnection(this);
    outconn->connect_to_host(ui->IpAddr_lnedt->text()); // port in this version is already defined
    outconn->send_ping();
}

