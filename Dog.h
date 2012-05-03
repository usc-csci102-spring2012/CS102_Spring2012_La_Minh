#ifndef DOG_H
#define DOG_H
#include "Enemy.h"
class Dog: public Enemy
{

  public:
    Dog();//Constructor
    Dog(int);
    ~Dog();//Destructor

  public:
    void autoMove();

};

#endif
