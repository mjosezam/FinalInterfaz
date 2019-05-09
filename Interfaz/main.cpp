#include <QApplication>
#include <mythread.h>
#include <game.h>
#include <myplayer.h>
#include <stdlib.h>
#include <QDebug>
#include <iostream>
#include <thread>
#include <unistd.h>
#include "sockets.h"
#include "serial.h"

using namespace std;
Game *g;
int gameStart(int argc, char *argv[]){
  QApplication a(argc,argv);
  g=new Game();
  g->mainButtons();
  return a.exec();
}



int main(int argc, char *argv[])
{
  srand(time(NULL));
  std::thread gameThread (gameStart,argc,argv);
  gameThread.join();
  /**string json = "";
  int edad;
  int edadBack;
  int emocional;
  int emocionalBack;
  int condicionFisica;
  int condicionFisicaBack;
  int resistencia;
  int resistenciaBack;
  int velocidad;
  int velocidadBack;
  int generacion;
  int generacionBack;
  int id;
  int idBack;
  int vida;
  int vidaBack;
  int fitness;
  int fitnessBack;
  int probabilidad;
  int probabilidadBack;
  int troncoSuperior;
  int troncoSuperiorBack;
  int troncoInferior;
  int troncoInferiorBack;
  int supervivenciaGen;
  int supervivenciaGenBack;
  int **aStar;
  int **backTrack;
  int matriz[10][10];
  string mensaje = serial::getInstance().serializarTurno(true,1,false);
  string recibido = Socket::getInstance().envioEscucho(mensaje, 8080, "192.168.0.111");
  qDebug()<<recibido.c_str();
  /**serial::getInstance().deserealizarTableroGladiador(recibido.c_str(), matriz, &edad,&edadBack,&emocional,&emocionalBack,&condicionFisica,&condicionFisicaBack
                                                              , &resistencia,&resistenciaBack,&velocidad,&velocidadBack,&generacion,&generacionBack,&id, &idBack,&vida,&vidaBack,&fitness,
                                                              &fitnessBack,&probabilidad,&probabilidadBack,&troncoSuperior, &troncoSuperiorBack, &troncoInferior,&troncoInferiorBack,
                                                              &supervivenciaGen,&supervivenciaGenBack,aStar,backTrack);2
  cout<<edad;**/
  return 0;
}

