#include "arrow.h"
#include <QPixelFormat>
#include <QTimer>
#include <qmath.h>
#include "myplayer.h"
#include "qlist.h"
#include <QApplication>
#include "game.h"
#include <QGraphicsScene>
#include <iostream>
using namespace std;
extern  Game* g;
Arrow::Arrow(QGraphicsItem *parent)
{
  setPixmap(QPixmap(":images/SimpleArrow.png"));
  QTimer *move_timer = new QTimer(this);
  connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
  move_timer->start(0.1);
}

void Arrow::move(){
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for(int i=0,n=colliding_items.size();i<n;i++){
      qApp->processEvents();
      if(typeid(*(colliding_items[i]))==typeid (MyPlayer)){
          cout << "tres" << endl;
          qApp->processEvents();
          g->vida->setPlainText(QString::number(g->player->vida-1));
          g->player->vida--;
          scene()->removeItem(this);
          if (g->player->vida<=0){
              qApp->processEvents();
              delete g->player;
              MyPlayer *p = new MyPlayer();
              g->player = p;
              g->scene->addItem(p);
              g->vida->setPlainText(QString::number(g->player->vida));
              p->setPos(71,32);
              p->setFlag(QGraphicsItem::ItemIsFocusable);
              p->setFocus();
              g->i=0;
              g->timer->start(1);
            }
          return;
        }
   }
  if (pos().y()<0||pos().x()<0||pos().x()>g->scene->width()||pos().y()>g->scene->height()){
      delete  this;
      return;
    }
  int mov = 20;
  double cita = rotation();
  double dy = mov * qSin(qDegreesToRadians(cita));
  double dx = mov * cos(qDegreesToRadians(cita));
  setPos(x()+dx,y()+dy);
}
