#include "market.h"
#include "ui_market.h"

Market::Market(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Market)
{
    ui->setupUi(this);
}

Market::~Market()
{
    delete ui;
}

void Market::on_cancelPushButton_clicked()
{
    close();
}

void Market::on_buyPushButton_clicked()
{
    close();
}
