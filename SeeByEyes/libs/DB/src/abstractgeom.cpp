

#include "abstractgeom.h"

AbstractGeom::AbstractGeom( const AbstractGeom &geom )
{
  mWkbType = geom.mWkbType;
}

AbstractGeom &AbstractGeom::operator=( const AbstractGeom &geom )
{
  if ( &geom != this )
  {
    clear();
    mWkbType = geom.mWkbType;
  }
  return *this;
}

Box3D AbstractGeom::boundingBox() const
{
    double xmin = std::numeric_limits<double>::max();
    double ymin = std::numeric_limits<double>::max();
    double zmin = std::numeric_limits<double>::max();
    double xmax = -std::numeric_limits<double>::max();
    double ymax = -std::numeric_limits<double>::max();
    double zmax = -std::numeric_limits<double>::max();

    VertexId id;
    Point vertex;
    double x, y, z;

    while ( nextVertex( id, vertex ) )
    {
        x = vertex.x();
        y = vertex.y();
        z = vertex.z();

        xmin = std::min( xmin, x );
        xmax = std::max( xmax, x );

        ymin = std::min( ymin, y );
        ymax = std::max( ymax, y );

        zmin = std::min( zmin, z );
        zmax = std::max( zmax, z );
    }
 

  return Box3D( xmin, ymin, zmin, xmax, ymax, zmax );
}

