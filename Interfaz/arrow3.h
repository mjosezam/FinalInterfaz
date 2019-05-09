#ifndef ARROW3_H
#define ARROW3_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Arrow3: public QObject,public QGraphicsPixmapItem
{
  Q_OBJECT
public:
  Arrow3(QGraphicsItem *parent=0);
public slots:
  void move();

};

#endif // ARROW3_H
