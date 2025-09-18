#ifndef CONNECT_TO_COMPUTER_H
#define CONNECT_TO_COMPUTER_H

#include <QDialog>

#include "outgoingconnection.h"

namespace Ui {
class ConnectToComputer;
}

class ConnectToComputer : public QDialog
{
    Q_OBJECT

public:
    explicit ConnectToComputer(QWidget *parent = nullptr);
    ~ConnectToComputer();

private slots:
    void on_CancelBtn_clicked();

private:
    Ui::ConnectToComputer *ui;
};

#endif // CONNECT_TO_COMPUTER_H
