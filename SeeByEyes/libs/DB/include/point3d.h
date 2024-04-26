
#ifndef POINT_H
#define POINT_H



#include "db.h"
#include <limits>

class Point3D
{

public:
    Point3D(/* args */);
    double x() const;
    double y() const;
    double z() const;
    bool isEmpty() const;
    ~Point3D();
};





#endif