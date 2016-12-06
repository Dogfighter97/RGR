#ifndef DATAOPS_H
#define DATAOPS_H

#include "player.h"
#include <QDataStream>
#include <QIODevice>
#include <QFile>

void dataOperat(Player* player, QChar func)
{
    QFile data("datafile.dat");
    if (func == 'r')
    {
        if (data.open(QIODevice::ReadOnly))
        {
            QDataStream stream(&data);
            stream.readRawData((char*)player, sizeof(Player));
        }
        data.close();
    }
    else if (func == 'w')
    {
        if (data.open(QIODevice::WriteOnly))
        {
            QDataStream stream(&data);
            stream.writeRawData((char*)player, sizeof(Player));
        }
        data.close();
    }

}

//void dataWrite(Player* player)
//{
//    QFile data("datafile.dat");
//    if (data.open(QIODevice::WriteOnly))
//    {
//        QDataStream stream(&data);
//        stream.writeRawData((char*)player, sizeof(Player));
//    }
//    data.close();
//}


#endif // DATAOPS_H
