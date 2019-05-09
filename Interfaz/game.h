#ifndef GAME_H
#define GAME_H
#include <QGraphicsScene>
#include <QGraphicsView>
#include <myplayer.h>
#include <QTimer>
#include "myplayer.h"
#include <QObject>
#include <QWidget>

#include "stadistics.h"
#include<QKeyEvent>
class Game:public QGraphicsView
{
  Q_OBJECT
public:
  Game();
  QGraphicsView *view;
  QGraphicsScene *scene;
  MyPlayer *player;
  Stadistics *vida,*id,*edad,*prob,*gen,*emocion,*superior,*inferior,*resistencia,*fisica,*time_in;
  QTimer *timer;
  int i=0;
  void mainButtons();
  void endgame();

public slots:
  void spawn();
  void start();
  void close();
};

#endif // GAME_H
