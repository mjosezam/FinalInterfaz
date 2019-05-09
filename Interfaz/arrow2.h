#ifndef ARROW2_H
#define ARROW2_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Arrow2: public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Arrow2(QGraphicsItem *parent=0);
public slots:
  void move();

};

#endif // ARROW2_H
