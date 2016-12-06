#ifndef NEWGAME_H
#define NEWGAME_H

#include <QDialog>
#include "player.h"
#include "mainwindow.h"

namespace Ui {
class NewGame;
}



class NewGame : public QDialog
{
    Q_OBJECT

public:
    explicit NewGame(QWidget *parent = 0);
    ~NewGame();

private:
    Ui::NewGame *ui;
private slots:
    void on_okPushButton_clicked();
signals:
    void sendData();
};

#endif // NEWGAME_H
