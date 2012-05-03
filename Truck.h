#ifndef TRUCK_H
#define TRUCK_H
#include "Vehicle.h"
class Truck: public Vehicle
{

  public:
    Truck();//Constructor
    Truck(int xSpeed, int ySpeed);
    ~Truck();//Destructor

  public:
    void autoMove();

};

#endif
