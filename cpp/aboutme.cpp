#include "aboutme.h"
#include "ui_aboutme.h"

AboutMe::AboutMe(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AboutMe)
{
    ui->setupUi(this);
    setWindowTitle("About furry foxy");
    setFixedSize(427,348);
}

AboutMe::~AboutMe()
{
    delete ui;
}
