#include "save.h"
#include "ui_save.h"

Save::Save(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save)
{
    ui->setupUi(this);
}

Save::~Save()
{
    delete ui;
}

void Save::on_savePushButton_clicked()
{
    ui->saveLineWidget->addItem("1");
}

void Save::on_cancelPushButton_clicked()
{
    close();
}
