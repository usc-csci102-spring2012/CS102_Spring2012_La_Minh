#include "Game.h"
#include <QPainter>
#include <QApplication>
#include <iostream>

Game::Game(QWidget *parent)
    : QWidget(parent)
{
  //srand(time(NULL));

  timerId = startTimer(100);
  lives = 3;
  scores = 0;
  level = 1;
  Frogger_Speed = 20;
  w = rand() % 400; // random spawn for car
  z = rand() % 400; // random spawn for truck
  c = rand() % 359; // random spawn for clover
  gameStarted = FALSE;
  gameOver = FALSE;
  gameWon = FALSE;
  frogger = new Frogger();
  frogger->movePositioning(200,380);
  clover = new Clover();
  clover->movePositioning(c,30);
  car1 = new Car();
  car2 = new Car();
  car3 = new Car();
  car4 = new Car();
  truck1 = new Truck();
  truck2 = new Truck();
  car11 = new Car();
  car12 = new Car();
  car13 = new Car();
  L2dog1 = new Dog(-25);
  L2dog2 = new Dog(25);
  L2dog3 = new Dog(20);
  L2dog4 = new Dog(-25);
  L2dog5 = new Dog(35);
  heart = new Heart();
  L3fire1 = new Fire();
  L3fire2 = new Fire();
  L3speed = new Speed();
  L3slow = new Slow();
  L3angrydog[0] = new AngryDog(4);
  L3angrydog[1] = new AngryDog(-4);
  L3angrydog[2] = new AngryDog(4);
  L3angrydog[3] = new AngryDog(-4);
  L3angrydog[4] = new AngryDog(4);
  L3angrydog[5] = new AngryDog(-4);
  L4tiger = new Tiger();
  L4lion = new Lion();
  spawnLevel1();
  spawnLevel2();
  spawnLevel3();
  spawnLevel4();
}

Game::~Game() {
}

void Game::paintEvent(QPaintEvent *event){ // paint screen depending on if game is over
  QPainter painter(this);
  if (gameOver) {//if game is over, print screen
    QFont font("Courier", 9, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over. Press space to restart.");

    painter.setFont(font);
    int h = height();
    int w = width();

    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2, 0, "Game Over. Press space to restart.");
  }
  else if(gameWon){
      QFont font("Courier", 9, QFont::DemiBold);
      QFontMetrics fm(font);
      int textWidth = fm.width("YOU WIN. Press space to restart.");

      painter.setFont(font);
      int h = height();
      int w = width();

      painter.translate(QPoint(w/2, h/2));
      painter.drawText(-textWidth/2, 0, "YOU WIN. Press space to restart.");
  }
  else{
      if(level == 1){
    painter.drawImage(frogger->getRect(),frogger->getImage());
    painter.drawImage(car1->getRect(),car1->getImage());
    painter.drawImage(car2->getRect(),car2->getImage());
    painter.drawImage(car3->getRect(),car3->getImage());
    painter.drawImage(car4->getRect(),car4->getImage());
    painter.drawImage(truck1->getRect(),truck1->getImage());
    painter.drawImage(truck2->getRect(),truck2->getImage());
    painter.drawImage(clover->getRect(),clover->getImage());
    painter.drawImage(car11->getRect(),car11->getImage());
    painter.drawImage(car12->getRect(),car12->getImage());
    painter.drawImage(car13->getRect(),car13->getImage());
      }
      else if(level == 2){
          painter.drawImage(frogger->getRect(),frogger->getImage());
          painter.drawImage(clover->getRect(),clover->getImage());
          painter.drawImage(L2dog1->getRect(),L2dog1->getImage());
          painter.drawImage(L2dog2->getRect(),L2dog2->getImage());
          painter.drawImage(L2dog3->getRect(),L2dog3->getImage());
          painter.drawImage(L2dog4->getRect(),L2dog4->getImage());
          painter.drawImage(L2dog5->getRect(),L2dog5->getImage());
          painter.drawImage(heart->getRect(),heart->getImage());
      }
      else if(level == 3){
          painter.drawImage(frogger->getRect(),frogger->getImage());
          painter.drawImage(clover->getRect(),clover->getImage());
          painter.drawImage(L3angrydog[0]->getRect(),L3angrydog[0]->getImage());
          painter.drawImage(L3angrydog[1]->getRect(),L3angrydog[1]->getImage());
          painter.drawImage(L3angrydog[2]->getRect(),L3angrydog[2]->getImage());
          painter.drawImage(L3angrydog[3]->getRect(),L3angrydog[3]->getImage());
          painter.drawImage(L3angrydog[4]->getRect(),L3angrydog[4]->getImage());
          painter.drawImage(L3angrydog[5]->getRect(),L3angrydog[5]->getImage());
          painter.drawImage(L3fire1->getRect(),L3fire1->getImage());
          painter.drawImage(L3fire2->getRect(),L3fire2->getImage());
          painter.drawImage(L3speed->getRect(),L3speed->getImage());
          painter.drawImage(L3slow->getRect(),L3slow->getImage());
      }
      else if(level == 4){
          painter.drawImage(frogger->getRect(),frogger->getImage());
          painter.drawImage(clover->getRect(),clover->getImage());
          painter.drawImage(L4tiger->getRect(),L4tiger->getImage());
          painter.drawImage(L4lion->getRect(),L4lion->getImage());
      }

    QFont font("Courier", 10, QFont::DemiBold);//fonts being set.

    QFontMetrics fm(font);

    int textWidth = fm.width("Points");
    painter.setFont(font);

    int h = height();

    int w = width();

    QString livesLeft;// string for lives
    QString currentScores; // strings for scores
    QString round;
    currentScores.append(QString("%1").arg(scores));
    livesLeft.append(QString("%1").arg(lives));
    round.append(QString("%1").arg(level));
    QString str="Lives: " + livesLeft + "\nScores: " + currentScores + "\nLevel: " + round;
    painter.translate(QPoint(w/10, h/20));//location of where to print the string.
    painter.drawText(-textWidth/2, 0, str);
  }
}

void Game::timerEvent(QTimerEvent *event){//update all movements
  checkCollision();
  if(level == 1){
      car1->autoMove();
  car2->autoMove();
  car3->autoMove();
  car4->autoMove();
  truck1->autoMove();
  truck2->autoMove();
  car11->autoMove();
  car12->autoMove();
  car13->autoMove();
  }
  else if(level == 2){
      L2dog1->autoMove();
      L2dog2->autoMove();
      L2dog3->autoMove();
      L2dog4->autoMove();
      L2dog5->autoMove();
  }
  else if(level == 3){
      for(int i =0;i<6;i++){
          if(frogger->getRect().x() > L3angrydog[i]->getRect().x())
             L3angrydog[i]->xdir = 3;
          else if (frogger->getRect().x() < L3angrydog[i]->getRect().x())
              L3angrydog[i]->xdir = -3;
          else
              L3angrydog[i]->xdir = -0;
          if(frogger->getRect().y() < L3angrydog[i]->getRect().y())
             L3angrydog[i]->ydir = -3;
          else if(frogger->getRect().y() > L3angrydog[i]->getRect().y())
              L3angrydog[i]->ydir = 3;
          else
              L3angrydog[i]->ydir = 0;
          L3angrydog[i]->autoMove();
      }
  }
  else if(level == 4){
     // int temp, temp2, temp3,temp4;
      if(frogger->getRect().x() > L4tiger->getRect().x()){
         L4tiger->xdir = 12;
         /*if(L4tiger->xdir < 15 && L4tiger -> xdir > -15)
             L4tiger->xdir = 15;*/
      }
      else if (frogger->getRect().x() < L4tiger->getRect().x()){
         L4tiger->xdir = -12;
         /* if(L4tiger->xdir < 15 && L4tiger -> xdir > -15)
              L4tiger->xdir = -15;*/
       }
      else{
          //temp = L4tiger->xdir;
          L4tiger->xdir = 0;
      }
      if(frogger->getRect().y() < L4tiger->getRect().y()){
        L4tiger->ydir = -12;
        /* if(L4tiger->xdir < 15 && L4tiger -> xdir > -15)
             L4tiger->ydir = -15;*/
      }
      else if(frogger->getRect().y() > L4tiger->getRect().y()){
          L4tiger->ydir = 12;
          /*if(L4tiger->xdir < 15 && L4tiger -> xdir > -15)
              L4tiger->ydir = 15;*/
       }
      else{
        // temp2 = L4tiger->ydir;
         L4tiger->ydir = 0;
      }
      L4tiger->autoMove();
     /* if(L4tiger->xdir == 0)
         L4tiger->xdir = temp;
      if(L4tiger->ydir == 0)
         L4tiger->ydir = temp2;*/

      if(frogger->getRect().x() > L4lion->getRect().x()){
         L4lion->xdir = 7;
         /*if(L4lion->xdir > 30 || L4lion->xdir < -30)
             L4lion->xdir = -30;*/
      }
      else if (frogger->getRect().x() <L4lion->getRect().x()){
          L4lion->xdir = -7;
       /*   if(L4lion->xdir > 30 || L4lion->xdir < -30)
              L4lion->xdir = 30;*/
      }
      else{
          //temp3 = L4lion->xdir;
          L4lion->xdir = 0;
      }
      if(frogger->getRect().y() < L4lion->getRect().y()){
         L4lion->ydir = -7;
         /*if(L4lion->ydir > 30)
             L4lion->ydir = 30;*/
      }
      else if(frogger->getRect().y() > L4lion->getRect().y()){
          L4lion->ydir = 7;
       /*   if(L4lion->xdir > 30 || L4lion->xdir < -30)
              L4lion->ydir = -30;*/
      }
      else{
         //temp4 = L4lion->ydir;
         L4lion->ydir = 0;
      }
      L4lion->autoMove();
     /* if(L4lion->xdir == 0)
          L4lion->xdir = temp3;
      if(L4lion->ydir == 0)
          L4lion->ydir = temp4;*/
  }
  checkCollision();
  repaint();
}



void Game::keyPressEvent(QKeyEvent *event)//move objects with inputs
{
    switch (event->key()) {
    case Qt::Key_Left: // move left
       {
         int x = frogger->getRect().x();//returns the current x position of the frogger object.

        //for (int i=1; i<=20; i++)
          frogger->moveLeft(x - Frogger_Speed);
        break;
       }
    case Qt::Key_Right:
        {
          int x = frogger->getRect().x();
         // for (int i=1; i<=20; i++)
            frogger->moveRight(x + Frogger_Speed);
        }
        break;

case Qt::Key_Up:
       {
         int y = frogger->getRect().y();//returns the y position of where the frogger object is.
       // for (int i=1; i<=20; i++)
          frogger->moveTop(y - Frogger_Speed);
        break;
       }
    case Qt::Key_Down:
        {
          int y = frogger->getRect().y();
         // for (int i=1; i<=20; i++)
            frogger->moveBottom(y + Frogger_Speed);
        }
        break;
    case Qt::Key_Space:
        {
        if(gameOver || gameWon){
          lives = 3;
          scores = 0;
          w = rand() % 400; // random spawn for car
          z = rand() % 400; // random spawn for truck
          c = rand() % 359; // random spawn for clover
          gameOver = FALSE;
          gameWon = FALSE;
          level = 1;
          startGame();
        }
    }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();//exits the game entirely.
        }
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}



void Game::startGame()//starts the game.
{
 //srand(time(NULL));

    //timerId = startTimer(100);
   if ((!gameStarted) || level == 1) {
    gameOver = FALSE;
    gameStarted = TRUE;
    //roundWon = FALSE;
  frogger->movePositioning(200,380);
  clover->movePositioning(c,30);
  spawnLevel1();
  Frogger_Speed = 20;

  }
   else if(level == 2){
       gameOver = FALSE;
       gameStarted = TRUE;
       spawnLevel2();
   }
   else if (level == 3){
       gameOver = FALSE;
       gameStarted = TRUE;
       spawnLevel3();
   }
   else if (level == 4){
       gameOver = FALSE;
       gameStarted = TRUE;
       spawnLevel4();
   }
}

void Game::stopGame() // stop the game, changes gameOver to true
{
  //killTimer(timerId);
  level = 1;
  gameOver = TRUE;
  gameStarted = FALSE;
}

void Game::endGame(){

    gameOver = TRUE;
  gameWon = true;
 gameStarted = FALSE;
}

void Game::checkCollision()//checks all the collisions of the game.
{
    if(lives<=0)//when live hits zero, game is over.
    {
      stopGame();
    }
    if(level == 1){
  if((frogger->getRect()).intersects(car1->getRect()) ||(frogger->getRect()).intersects(car2->getRect()) || (frogger->getRect()).intersects(car3->getRect()) || (frogger->getRect()).intersects(car4->getRect()) || (frogger->getRect()).intersects(truck1->getRect()) || (frogger->getRect()).intersects(truck2->getRect()) || (frogger->getRect()).intersects(car11->getRect()) ||(frogger->getRect()).intersects(car12->getRect()) || (frogger->getRect()).intersects(car13->getRect()) ){ // collision with any of the car or trucks
    lives--;
    frogger->movePositioning(200, 380);
}
    }
    else if(level == 2){
        if((frogger->getRect()).intersects(L2dog1->getRect()) || (frogger->getRect()).intersects(L2dog2->getRect()) || (frogger->getRect()).intersects(L2dog3->getRect()) || (frogger->getRect()).intersects(L2dog4->getRect()) || (frogger->getRect()).intersects(L2dog5->getRect())){
            lives--;
            frogger->movePositioning(200,380);
        }
    }
    else if(level == 3){
        if((frogger->getRect()).intersects(L3angrydog[0]->getRect()) || (frogger->getRect()).intersects(L3angrydog[1]->getRect()) || (frogger->getRect()).intersects(L3angrydog[2]->getRect()) || (frogger->getRect()).intersects(L3angrydog[3]->getRect()) || (frogger->getRect()).intersects(L3angrydog[4]->getRect()) || (frogger->getRect()).intersects(L3angrydog[5]->getRect())){
            lives--;
            spawnLevel3();
        }
        if((frogger->getRect()).intersects(L3fire1->getRect()) || (frogger->getRect()).intersects(L3fire2->getRect())){
            lives--;
            spawnLevel3();
        }
        if(frogger->getRect().intersects(L3speed->getRect())){
            Frogger_Speed+=20;
            L3speed->movePositioning(400,400);
        }
        if(frogger->getRect().intersects(L3slow->getRect())){
            Frogger_Speed-=10;
            L3slow->movePositioning(400,400);
        }
    }
    else if(level == 4){
        if(frogger->getRect().intersects(L4tiger->getRect()) || frogger->getRect().intersects(L4lion->getRect())){
            lives--;
            frogger->movePositioning(200,380);
            L4tiger->movePositioning(0,40);
            L4lion->movePositioning(340,40);
            L4tiger->xdir = 15;
            L4tiger->ydir = 15;
            L4lion->xdir = 2;
            L4lion->ydir = 2;
        }
    }
    else if(level == 5)
        endGame();
 if((frogger->getRect()).intersects(clover->getRect())){ // lands on clover, wins round
    w = rand() % 400; // random spawn for car
    z = rand() % 400; // random spawn for truck
    c = rand() % 359; // random spawn for clover
   // roundWon = TRUE;
    level++;
    startGame();
    scores += 100;
}
 if((frogger->getRect()).intersects(heart->getRect())){
     lives++;
     heart->movePositioning(400,400);
 }
}

void Game::spawnLevel1(){
    car1->movePositioning(w % 460, 80 - 5); // ROW 1 ENEMIES
    car2->movePositioning((w + 115) % 460, 80 - 5);
    car3->movePositioning((w + 230) % 460, 80 - 5);
    car4->movePositioning((w + 345) % 460, 80 - 5);
    truck1->movePositioning(z % 600,160 - 5); // ROW 2 ENEMIES
    truck2->movePositioning((z + 285) % 600,160 - 5);
    car11->movePositioning(w % 460, 300 - 5); // ROW 3 ENEMIES
    car12->movePositioning((w + 150) % 460, 300 - 5);
    car13->movePositioning((w + 300) % 460, 300 - 5);
}

void Game::spawnLevel2(){
    frogger->movePositioning(200,380);
    clover->movePositioning(c,30);
    L2dog1->movePositioning(320,321);
    L2dog2->movePositioning(120,281);
    L2dog3->movePositioning(260,241);
    L2dog4->movePositioning(120,201);
    L2dog5->movePositioning(20,161);
    heart->movePositioning(w,260);
}

void Game::spawnLevel3(){
    frogger->movePositioning(200,380);
    clover->movePositioning(c,30);
    L3angrydog[0]->movePositioning(0,360);
    L3angrydog[1]->movePositioning(400,360);
    L3angrydog[2]->movePositioning(40,260);
    L3angrydog[3]->movePositioning(360,260);
    L3angrydog[4]->movePositioning(80,160);
    L3angrydog[5]->movePositioning(320,160);
    L3fire1->movePositioning(140,180);
    L3fire2->movePositioning(200,180);
    L3speed->movePositioning(270,120);
    L3slow->movePositioning(100,120);
}

void Game::spawnLevel4(){
    frogger->movePositioning(200,380);
    clover->movePositioning(c,30);
    L4tiger->movePositioning(0,40);
    L4lion->movePositioning(360,40);
}
