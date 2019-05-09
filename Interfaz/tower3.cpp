#include "tower3.h"
#include "arrow3.h"
#include "game.h"
#include <QApplication>
#include "myplayer.h"
extern Game * g;
Tower3::Tower3()
{
  setPixmap(QPixmap(":/images/TorreExplosiva.png"));
  srand(time(NULL));
  int randwidth = rand()%10;
  int randheight = rand()%10;
  int posx=randwidth*66.5+72;
  int posy=randheight*64+29;
  setPos(posx,posy);
  QVector<QPoint> points;
  points << QPoint(-3,-2) << QPoint(-3,3) << QPoint(4,3) << QPoint(4,- 2);


  int SCALE_FACTORX = 44;
  int SCALE_FACTORY = 60;
  for (size_t i =0,n=points.size();i<n;i++){
      points[i].rx()*=SCALE_FACTORX;
      points[i].ry()*=SCALE_FACTORY;
    }
  attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
  collide_items=attack_area->collidingItems();
  attack_area->hide();
  QTimer *timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(kill()));
  timer->start(1000);
}



void Tower3::attack()
{
  Arrow3 * arrow  = new Arrow3();
  arrow->setPos(this->x()+33.5,this->y()+33.5);
  QLineF ln(QPointF(x(),y()),attack_point);
  qApp->processEvents();
  int angle = -1 * ln.angle();
  arrow->setRotation(angle);
  qApp->processEvents();
  g->scene->addItem(arrow);
}

void Tower3::kill()
{
  collide_items=attack_area->collidingItems();
  if (collide_items.size()==1){
      has_target=false;
      return;
    }
  double closest=190;
  QPointF enemy=QPointF(0,0);
  for(size_t i =0,n = collide_items.size();i<n;i++){
      MyPlayer * player = dynamic_cast<MyPlayer *>(collide_items[i]);
        qApp->processEvents();
      if (player){
          qApp->processEvents();
          double this_dist = distanceTo(player);
          if (this_dist<closest){
              qApp->processEvents();
              closest=this_dist;
              enemy=collide_items[i]->pos();
              has_target=true;
              attack_point= enemy;
              attack();
            }
        }
    }


}

double Tower3::distanceTo(QGraphicsItem *player)
{
  QLineF ln(this->pos(),player->pos());
  return ln.length();
}
