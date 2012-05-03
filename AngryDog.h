#ifndef ANGRYDOG_H
#define ANGRYDOG_H
#include "Enemy.h"
class AngryDog: public Enemy
{

  public:
    AngryDog();//Constructor
    AngryDog(int xSpeed);
    ~AngryDog();//Destructor

  public:
    void autoMove();

};

#endif
