#ifndef VEHICLE_H
#define VEHICLE_H
#include <QImage>
#include <QRect>
class Vehicle
{

  public:
    Vehicle();//Constructor
    Vehicle(int xSpeed, int ySpeed);
    virtual ~Vehicle();//Destructor

    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    QRect getRect();
    QImage & getImage();
    void movePositioning(int, int);

    virtual void autoMove() = 0;

  protected:
    int xdir;
    int ydir;
    QImage image;
    QRect rect;

};

#endif
