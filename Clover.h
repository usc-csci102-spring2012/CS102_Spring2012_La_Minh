#ifndef CLOVER_H
#define CLOVER_H
#include <QImage>
#include <QRect>
class Clover
{

  public:
    Clover();//Constructor
    ~Clover();//Destructor

  public:
    QRect getRect();
    QImage & getImage();
    void movePositioning(int, int);

  private:
    QImage image;
    QRect rect;

};

#endif
