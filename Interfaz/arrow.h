#ifndef ARROW_H
#define ARROW_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Arrow: public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Arrow(QGraphicsItem *parent=0);
public slots:
  void move();

};

#endif // ARROW_H
