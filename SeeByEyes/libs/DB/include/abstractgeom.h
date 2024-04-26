#ifndef ABSTRACTGEOM_H
#define ABSTRACTGEOM_H
//QT
#include <QPainter>

#include "db.h"
#include "box3d.h"

class WkbType{};
class WkbPtr;
class Point{};
class VertexId{};
typedef QVector<Point> PointSeq;

Box3D a = Box3D();
Box3D b = Box3D();
if (a == b)
  return;

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

    virtual bool nextVertex( VertexId &id, Point &vertex ) const = 0;
    virtual Point vertexAt( VertexId id ) const = 0;
    virtual PointSeq getPoints( ) const = 0;
    virtual int nPoints() const;

    virtual bool insertVertex( VertexId position, const Point &vertex ) = 0;
    virtual bool moveVertex( VertexId position, const Point &newPos ) = 0;
    virtual bool deleteVertex( VertexId position ) = 0;

    virtual double area() const;
    virtual double length() const;

    virtual Point centroid() const;

    virtual bool isEmpty() const;
private:
    WkbType mWkbType;
};






























#endif