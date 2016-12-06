#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <stdlib.h>


class Player
{
    public:

    int farmers, soldiers, knights, money, turn;
    QChar name[80];
    Player();
public:
    void buy(int, int, int);
    void endTurn();
    void saveGame();
    void barbInvasion();

    int show(QString);
};

#endif // PLAYER_H
