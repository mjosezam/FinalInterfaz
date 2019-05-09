#include "arrow2.h"
#include <QPixelFormat>
#include <QTimer>
#include <qmath.h>
#include "myplayer.h"
#include "qlist.h"
#include "game.h"
#include <QGraphicsScene>
extern  Game* g;
Arrow2::Arrow2(QGraphicsItem *parent)
{
  setPixmap(QPixmap(":images/FireArrow.png"));

  QTimer *move_timer = new QTimer(this);
  connect(move_timer,SIGNAL(timeout()),this,SLOT(move()));
  move_timer->start(30);
}

void Arrow2::move(){
    /**
  QList<QGraphicsItem *> colliding_items = collidingItems();
  for(int i=0,n=colliding_items.size();i<n;i++){
      if(typeid(*(colliding_items[i]))==typeid (MyPlayer)){
          g->life_points->setPlainText(QString::number(g->player->life_points-2));
          g->player->life_points=g->player->life_points-2;
          scene()->removeItem(this);
          if (g->player->life_points<=0){
              delete g->player;
              MyPlayer *p = new MyPlayer();
              g->player = p;
              g->scene->addItem(p);
              g->life_points->setPlainText(QString::number(g->player->life_points));
              p->setPos(71,32);
              p->setFlag(QGraphicsItem::ItemIsFocusable);
              p->setFocus();
              g->cont=0;
              g->timer->stop();
              g->timer->start(1000);
            }
          delete this;
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
**/
}
