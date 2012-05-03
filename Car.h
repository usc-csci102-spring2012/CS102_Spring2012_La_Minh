#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
class Car:public Vehicle
{
  public:
    Car();//Constructor
    Car(int xSpeed,int ySpeed);//Constructor with movement speeds
    ~Car();//Destructor

  public:
    void autoMove();

};

#endif
