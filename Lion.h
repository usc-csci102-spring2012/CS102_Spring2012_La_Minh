#ifndef LION_H
#define LION_H
#include "Enemy.h"
class Lion: public Enemy
{

  public:
    Lion();//Constructor
    ~Lion();//Destructor

  public:
    void autoMove();

};

#endif
