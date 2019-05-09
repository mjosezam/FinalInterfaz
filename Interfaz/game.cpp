#include "game.h"
#include <QBrush>
#include <QImage>
#include "mainmenu.h"
#include "button.h"
#include <QDebug>
#include <tower.h>
#include <tower2.h>
#include <QGraphicsScene>
#include <tower3.h>
#include <QPalette>
#include <stadistics.h>
#include <arrow.h>
#include <QPushButton>
#include <stdlib.h>
#include <iostream>
#include <QApplication>
using namespace std;

Game::Game()
{
  scene=new QGraphicsScene();
  view = new QGraphicsView(scene);

  scene->setBackgroundBrush(QBrush(QImage(":images/inicio.png")));
  view->show();
  view->setFixedSize(1050,700);


  scene->setSceneRect(0,0,1050,700);

  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

}

void Game::mainButtons(){
   QPushButton* leave = new QPushButton();
   leave->setGeometry(QRect(500,500,100,50));
   leave->setText("Leave Game");

   QObject::connect(leave,SIGNAL(clicked()),this,SLOT(close()));
   scene->addWidget(leave);

   Button * button = new Button(QString("Play"));
     button->setPos(300,300);
     connect(button,SIGNAL(clicked()),this,SLOT(start()));
   scene->addItem(button);

}

void Game::endgame(){
  scene->clear();
  scene->setBackgroundBrush(QBrush(QImage(":images/inicio.png")));
}


void Game::start()
{
    qApp->processEvents();
  scene->clear();
  player = new MyPlayer();
  scene->addItem(player);
  player->vida=100;
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setPos(60,65);
  player->setFocus();

  timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
  timer->start(0.1);

  vida = new Stadistics();
  vida->set(player->vida,920,160,35);
  scene->addItem(vida);

  id = new Stadistics();
  id->set(player->id,920,223,20);
  scene->addItem(id);

  edad = new Stadistics();
  edad->set(player->edad,920,257,20);
  scene->addItem(edad);

  prob = new Stadistics();
  prob->set(player->probabilidad,920,300,20);
  scene->addItem(prob);

  gen = new Stadistics();
  gen->set(player->supervivenciaGen,920,338,20);
  scene->addItem(gen);

  emocion  = new Stadistics();
  emocion->set(player->emocional,920,385,20);
  scene->addItem(emocion);

  superior = new Stadistics();
  superior->set(player->troncoSuperior,920,425,20);
  scene->addItem(superior);

  inferior = new Stadistics();
  inferior->set(player->troncoInferior,920,475,20);
  scene->addItem(inferior);

  resistencia = new Stadistics();
  resistencia->set(player->resistencia,920,515,20);
  scene->addItem(resistencia);

  fisica = new Stadistics();
  fisica->set(player->condicionFisica,920,555,20);
  scene->addItem(fisica);

  time_in = new Stadistics();
  time_in->set(0,880,43,35);
  time_in->setPlainText(QString("0000"));
  scene->addItem(time_in);

  scene->setBackgroundBrush(QBrush(QImage(":images/game.png")));


  int arri[7][2]={{1,1},{1,2},{2,3},{3,4},{4,4},{5,6},{5,3}};
  player->moveArr(arri);
}

void Game::close(){
  view->close();
}

void Game::spawn(){
    if(i==10){
        timer->stop();
        return;
    }
  int t = 0;
  if (t==0){
      cout << i << endl;
      Tower * tower = new Tower();
      scene->addItem(tower);
      i++;
    }
  if (t==1){
      Tower2 * tower = new Tower2();
      scene->addItem(tower);
    }
  if (t==2){
      Tower3 * tower = new Tower3();
      scene->addItem(tower);
    }
}


