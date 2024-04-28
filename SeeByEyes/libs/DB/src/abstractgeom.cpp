

#include "abstractgeom.h"
#include "point3d.h"
#include "box3d.h"


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
    Point3D vertex;
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

int AbstractGeom::nPoints() const
{
  int nPoints = 0;

  const PartSeq partSeq = getParts();
  for ( const PointSeq &r : partSeq )
  {
      nPoints += r.size();
  }

  return nPoints;
}

double AbstractGeom::area() const
{
    return 0.0;
}

double AbstractGeom::length() const
{
    return 0.0;
}

Point3D AbstractGeom::centroid() const
{
    if ( isEmpty() )
    return Point3D();

  // http://en.wikipedia.org/wiki/Centroid#Centroid_of_polygon
  // Pick the first ring of first part for the moment

  const int n = vertexCount( 0, 0 );
  if ( n == 1 )
  {
    return vertexAt( VertexId( 0, 0, 0 ) );
  }

  double A = 0.;
  double Cx = 0.;
  double Cy = 0.;
  const Point3D v0 = vertexAt( VertexId( 0, 0, 0 ) );
  int i = 0, j = 1;
  if ( vertexAt( VertexId( 0, 0, 0 ) ) != vertexAt( VertexId( 0, 0, n - 1 ) ) )
  {
    i = n - 1;
    j = 0;
  }
  for ( ; j < n; i = j++ )
  {
    Point3D vi = vertexAt( VertexId( 0, 0, i ) );
    Point3D vj = vertexAt( VertexId( 0, 0, j ) );
    vi.rx() -= v0.x();
    vi.ry() -= v0.y();
    vj.rx() -= v0.x();
    vj.ry() -= v0.y();
    const double d = vi.x() * vj.y() - vj.x() * vi.y();
    A += d;
    Cx += ( vi.x() + vj.x() ) * d;
    Cy += ( vi.y() + vj.y() ) * d;
  }

  if ( A < 1E-12 )
  {
    Cx = Cy = 0.;
    for ( int i = 0; i < n - 1; ++i )
    {
      const Point3D vi = vertexAt( VertexId( 0, 0, i ) );
      Cx += vi.x();
      Cy += vi.y();
    }
    return Point3D( Cx / ( n - 1 ), Cy / ( n - 1 ) );
  }
  else
  {
    return Point3D( v0.x() + Cx / ( 3. * A ), v0.y() + Cy / ( 3. * A ) );
  }
}

bool AbstractGeom::isEmpty() const
{
  VertexId vId;
  Point3D vertex;
  return !nextVertex( vId, vertex );
}
