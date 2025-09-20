#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "aboutme.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , InputTraffic(new IncommingConnection(this))
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->massge_line, &QLineEdit::returnPressed, this, &MainWindow::on_returnkey_Pressed);
    InputTraffic->startListening();
    myid = QRandomGenerator::global()->generate();
    ui->username_show->showMessage(QString::number(myid));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_Developer_triggered()
{
    AboutMe *about = new AboutMe(this);
    about->showNormal();
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionConnect_with_Ip_triggered()
{
    conn = new ConnectToComputer(this);
    conn->showNormal();
}

void MainWindow::on_returnkey_Pressed()
{
    send_massage();
}

void MainWindow::on_send_btn_clicked()
{
    send_massage();
}

void MainWindow::send_massage()
{
    QString msg_line = ui->massge_line->text();
    conn->outconn->send_massage_to_host(msg_line);
}
