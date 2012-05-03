#ifndef TIGER_H
#define TIGER_H
#include "Enemy.h"
class Tiger: public Enemy
{

  public:
    Tiger();//Constructor
    ~Tiger();//Destructor

  public:
    void autoMove();

};

#endif
