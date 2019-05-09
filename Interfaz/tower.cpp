#include "tower.h"
#include <stdlib.h>
#include <QPolygonF>
#include <QVector>
#include <QPointF>
#include  <QDebug>
#include <string>
#include <QApplication>
#include "arrow.h"
#include "game.h"
#include "myplayer.h"
#include <iostream>
using namespace std;

extern Game * g;

Tower::Tower(QGraphicsItem *parent):QObject(), QGraphicsPixmapItem (){
   setPixmap(QPixmap(":/images/TorreSimple.png"));
   int randwidth = rand()%10; //Random cambiarlos por server
   int randheight = rand()%10;
   int posx=randwidth*66.5+72;
   int posy=randheight*64+29;
   cout << posx << "  " << posy << endl;
   setPos(posx,posy);


   QVector<QPoint> points;
   points << QPoint(-1,-1) << QPoint(-1,2) << QPoint(3,2) << QPoint(3,- 1);


   int SCALE_FACTORX = 44;
   int SCALE_FACTORY = 60;
   for (size_t i =0,n=points.size();i<n;i++){
       qApp->processEvents();
       points[i].rx()*=SCALE_FACTORX;
       points[i].ry()*=SCALE_FACTORY;
     }
   attack_area = new QGraphicsPolygonItem(QPolygonF(points),this); //cambiar por array
   attack_area->hide();
   QTimer *timer = new QTimer();
   QObject::connect(timer,SIGNAL(timeout()),this,SLOT(kill()));
   timer->start(0.1);
}

void Tower::attack()
{
  Arrow * arrow  = new Arrow();
  arrow->setPos(this->x()+33.5,this->y()+33.5);
  QLineF ln(QPointF(this->x(),this->y()),attack_point);
  int angle =  -1 * ln.angle();
  arrow->setRotation(angle);
  g->scene->addItem(arrow);
}

void Tower::kill()
{
  collide_items=attack_area->collidingItems();
  if (collide_items.size()==1){
      has_target=false;
      return;
    }
  double closest=100;
  QPointF enemy=QPointF(0,0);
  for(size_t i =0,n = collide_items.size();i<n;i++){
      qApp->processEvents();
      MyPlayer * player = dynamic_cast<MyPlayer *>(collide_items[i]);
      if (player){
          double this_dist = distanceTo(player);
          if (this_dist<closest){
              closest=this_dist;
              enemy=collide_items[i]->pos();
              has_target=true;
              attack_point= enemy;
              qApp->processEvents();
              attack();
            }
        }
    }
}

double Tower::distanceTo(QGraphicsItem *player)
{
  QLineF ln(this->pos(),player->pos());
  return ln.length();
}



