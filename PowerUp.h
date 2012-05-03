#ifndef POWERUP_H
#define POWERUP_H
#include <QImage>
#include <QRect>
class PowerUp
{

  public:
    PowerUp();//Constructor
    virtual ~PowerUp();//Destructor

    QRect getRect();
    QImage & getImage();
    void movePositioning(int, int);

  protected:
    QImage image;
    QRect rect;

};

#endif
