
#ifndef POINT3D_H
#define POINT3D_H



#include "db.h"
#include <limits>

class Point3D
{

public:
    Point3D(/* args */);
    double x() const;
    double y() const;
    double z() const;
    //返回引用
    double &rx() {return mX;};
    double &ry() {return mY;};
    double &rz() {return mZ;};

    bool isEmpty() const;
    ~Point3D();
private:
    double mX;
    double mY;
    double mZ;
};





#endif