#ifndef ENEMY_H
#define ENEMY_H
#include <QImage>
#include <QRect>
class Enemy
{

  public:
    Enemy();//Constructor
    virtual ~Enemy();//Destructor

    void moveBottom(int);
    void moveTop(int);
    void moveLeft(int);
    void moveRight(int);
    QRect getRect();
    QImage & getImage();
    void movePositioning(int, int);
    virtual void autoMove() = 0;

    int xdir;
    int ydir;

  protected:
    QImage image;
    QRect rect;

};

#endif
