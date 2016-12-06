#include "player.h"

Player::Player()
{
    farmers = 4;
    soldiers = 3;
    knights = 2;
    money = 1000;
    turn = 1;
    for(int i = 0; i < 80; i++)
        name[i] = '\0';
}

void Player::buy(int a, int b, int c)
{
    farmers += a;
    soldiers += b;
    knights += c;
    money -= a*500 + b*800 + c*1000;
}
void Player::barbInvasion()
{
    if ((1 - 0.05*knights)*(rand() % 1600 + 400) > 0)
        money -= (1 - 0.05*knights)*(rand() % 1600 + 400);
}

void Player::endTurn()
{
    money += 100 + 500*farmers - 10*soldiers - 15*knights;
    turn++;

}
void Player::saveGame()
{

}
int Player::show(QString str)
{
    if (str == "farmers") return Player::farmers;
    else if (str == "soldiers") return Player::soldiers;
    else if (str == "knights") return Player::knights;
    else if (str == "money") return Player::money;
    else if (str == "turn") return Player::turn;
}

