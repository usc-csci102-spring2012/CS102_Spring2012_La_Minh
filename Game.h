#ifndef GAME_H
#define GAME_H

#include "Frogger.h"
#include "Car.h"
#include "Enemy.h"
#include "Dog.h"
#include "AngryDog.h"
#include "Lion.h"
#include "Tiger.h"
#include "PowerUp.h"
#include "Heart.h"
#include "Fire.h"
#include "Speed.h"
#include "Slow.h"
#include "Vehicle.h"
#include "Truck.h"
#include "Clover.h"
#include <QWidget>
#include <QKeyEvent>
class Game : public QWidget
{
  Q_OBJECT

  public:
    Game(QWidget *parent = 0);
    ~Game();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void stopGame();
    void endGame();
    void startGame();
    void checkCollision();
    void spawnLevel1();
    void spawnLevel2();
    void spawnLevel3();
    void spawnLevel4();

  private:
    int timerId;
    Clover *clover;
    Vehicle *car1;
    Vehicle *car2;
    Vehicle *car3;
    Vehicle *car4;
    Vehicle *truck1;
    Vehicle *truck2;
    Vehicle *car11;
    Vehicle *car12;
    Vehicle *car13;
    Frogger *frogger;
    Enemy *L2dog1;
    Enemy *L2dog2;
    Enemy *L2dog3;
    Enemy *L2dog4;
    Enemy *L2dog5;
    PowerUp *heart;
    Enemy *L3angrydog[6];
    PowerUp *L3fire1;
    PowerUp *L3fire2;
    PowerUp *L3speed;
    PowerUp *L3slow;
    Enemy *L4tiger;
    Enemy *L4lion;
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool goHarder;
    bool paused;
    bool roundWon;
    bool inGame;
    int lives, scores;
    int w, z, c; // random holders
    int level; // contains level
    int Frogger_Speed; // how fast frogger moves

};

#endif
