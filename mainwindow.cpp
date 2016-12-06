#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "market.h"
#include "newgame.h"
#include "load.h"
#include "save.h"
#include <fstream>
#include "dataops.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_marketButton_clicked()
{
    Market *mar = new Market(this);
    mar->show();
}

void MainWindow::on_actionNewGame_triggered()
{
    NewGame *ng = new NewGame(this);
    ng->show();
    connect(ng, SIGNAL(sendData()), this, SLOT(gameUpdate()));
}

void MainWindow::on_saveButton_clicked()
{
    Save *save = new Save(this);
    save->show();
}

void MainWindow::on_actionSave_triggered()
{
    MainWindow::on_saveButton_clicked();
}

void MainWindow::on_loadButton_clicked()
{
    auto load = new Load(this);
    load->show();
}

void MainWindow::gameUpdate()
{
    Player player;

    QFile data("datafile.dat");
    if (data.open(QIODevice::ReadOnly))
    {
        QDataStream stream(&data);
        stream.readRawData((char*)&player, sizeof(Player));
    }
    data.close();

    //player.dataRead(player);

    ui->nameLineEdit->setText("");
    ui->farmers_label->setText("F: "+ QString::number(player.show("farmers")));
    ui->soldiers_label->setText("S: "+ QString::number(player.show("soldiers")));
    ui->knights_label->setText("K: "+ QString::number(player.show("knights")));
    ui->money_label->setText("Money: "+ QString::number(player.show("money")));
    ui->turn_label->setText("<b>TURN: "+ QString::number(player.show("turn")));
    for (int i = 0; player.name[i] != '\0'; i++)
    {
        ui->nameLineEdit->setText(ui->nameLineEdit->text() + player.name[i]);
    }
}

void MainWindow::on_endTurnButton_clicked()
{
    Player* player = new Player;
    dataOperat(player, 'r');

//    QFile data("datafile.dat");
//    if (data.open(QIODevice::ReadOnly))
//    {
//        QDataStream stream(&data);
//        stream.readRawData((char*)&player, sizeof(Player));
//    }
//    data.close();

    player->endTurn();

    dataOperat(player, 'w');


//    if (data.open(QIODevice::WriteOnly))
//    {
//        QDataStream stream(&data);
//        stream.writeRawData((char*)&player, sizeof(Player));
//    }
//    data.close();

    gameUpdate();
    delete player;

}
