#ifndef ABSTRACTGEOM_H
#define ABSTRACTGEOM_H
//QT
#include <QPainter>

#include "db.h"

class Point3D;
class Box3D;


class WkbType{};
class WkbPtr;

typedef QVector<Point3D> PointSeq;
typedef QVector<PointSeq> PartSeq;


class DB_LIB_API AbstractGeom
{
public:
    AbstractGeom() = default;
    virtual ~AbstractGeom() = default;
    AbstractGeom( const AbstractGeom &geom );
    AbstractGeom &operator=( const AbstractGeom &geom );

    virtual bool operator==( const AbstractGeom &other ) const = 0;
    virtual bool operator!=( const AbstractGeom &other ) const = 0;

    virtual AbstractGeom *clone() const = 0;

    virtual void clear() = 0;

    virtual Box3D boundingBox() const;

    virtual QString geometryType() const = 0;
    inline WkbType wkbType() const  { return mWkbType; };

    virtual bool fromWkt( const QString &wkt ) = 0;
    virtual bool fromWkb( WkbPtr &wkb ) = 0;

    enum WkbFlag
    {
      FlagExportTrianglesAsPolygons = 1 << 0, 
      FlagExportNanAsDoubleMin = 1 << 1,
    };
    Q_DECLARE_FLAGS( WkbFlags, WkbFlag )

    virtual QByteArray asWkb( WkbFlags flags = AbstractGeom::WkbFlags() ) const = 0;

    virtual QString asWkt( int precision = 17 ) const = 0;
    virtual void draw( QPainter &p ) const = 0;

    virtual bool nextVertex( int &id, Point3D &vertex ) const = 0;
    virtual Point3D vertexAt( int id ) const = 0;
    virtual int vertexCount( int part = 0, int ring = 0 ) const = 0;
    virtual PartSeq getParts() const = 0;
    virtual PointSeq getPoint3Ds( ) const = 0;
    virtual int nPoints() const;

    virtual bool insertVertex( int position, const Point3D &vertex ) = 0;
    virtual bool moveVertex( int position, const Point3D &newPos ) = 0;
    virtual bool deleteVertex( int position ) = 0;

    virtual double area() const;
    virtual double length() const;

    virtual Point3D centroid() const;

    virtual bool isEmpty() const;
private:
    WkbType mWkbType;
    Box3D mBBox;
};






























#endif