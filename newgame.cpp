#include "newgame.h"
#include "ui_newgame.h"
#include <QMessageBox>
#include <fstream>
#include "dataops.h"


NewGame::NewGame(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGame)
{
    ui->setupUi(this);

}

NewGame::~NewGame()
{
    delete ui;
}

void NewGame::on_okPushButton_clicked()
{    
    //Player* player = new Player;
    Player player;
    Player* pl = &player;

    for(int i = 0; i < ui->nameLineEdit->text().length(); i++)
    {
        player.name[i] = ui->nameLineEdit->text().at(i);
    }

//    QFile data("datafile.dat");
//    if (data.open(QIODevice::WriteOnly))
//    {
//        QDataStream stream(&data);
//        stream.writeRawData((char*)&player, sizeof(Player));
//    }
//    data.close();

    dataOperat(pl, 'w');
    //delete pl;
    QMessageBox *msg = new QMessageBox(this);
    msg->setText("New game is created");
    close();

    msg->show();
    emit sendData();
}
