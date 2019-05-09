#include "myplayer.h"
#include <QDebug>
#include <QKeyEvent>
#include <QThread>
#include "game.h"
#include <unistd.h>
#include <stdlib.h>
#include <QApplication>
#include <iostream>
using namespace std;
extern Game *g;
MyPlayer::MyPlayer(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem ()
{
  setPixmap(QPixmap(":/images/try.png"));

}

void MyPlayer::moveArr(int arr[7][2]){
    for (int i=0; i<7; i++){
        qApp->processEvents();
        int x = arr[i][0]*60;
        int y = arr[i][1]*60;
        setPos(x,y);
        sleep(2);
    }
}
