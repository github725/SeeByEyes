#include "box3d.h"

Box3D::Box3D(double xmin, double ymin, double zmin, double xmax, double ymax, double zmax, bool normalize)
    :m_xmin(xmin),
    m_ymin(ymin),
    m_zmin(zmin),
    m_xmax(xmax),
    m_ymax(ymax),
    m_zmax(zmax)
{
    if ( normalize )
  {
    Box3D::normalize();
  }

}

Box3D::Box3D(const Point3D &p1, const Point3D &p2, bool normalize)
    :m_xmin(p1.x()),
    m_ymin(p1.y()),
    m_zmin(p1.z()),
    m_xmax(p2.x()),
    m_ymax(p2.y()),
    m_zmax(p2.z())
{
    if ( normalize )
  {
    Box3D::normalize();
  }

    
}

void Box3D::setXMinimum(double x)
{
    m_xmin = x;
}

void Box3D::setXMaximum(double x)
{
    m_xmax = x;
}

void Box3D::setYMinimum(double y)
{
    m_ymin = y;
}

void Box3D::setYMaximum(double y)
{
    m_ymax = y;
}

void Box3D::setZMinimum(double z)
{
    m_zmin = z;
}

void Box3D::setZMaximum(double z)
{
    m_zmax = z;
}

bool Box3D::operator==(const Box3D &other) const
{
    return m_xmin == other.m_xmin &&
            m_xmax == other.m_xmax &&
            m_ymin == other.m_ymin &&
            m_ymax == other.m_ymax &&
            m_zmin == other.m_zmin &&
            m_zmax == other.m_zmax ;
}

Box3D Box3D::operator-(const QVector3D &v) const
{
    return Box3D(m_xmin - v.x(), m_ymin - v.y(), m_zmin - v.z(),
                m_xmax - v.x(), m_ymax - v.y(), m_zmax - v.z() );
}

Box3D Box3D::operator+(const QVector3D &v) const
{
    return Box3D(m_xmin + v.x(), m_ymin + v.y(), m_zmin + v.z(),
                m_xmax + v.x(), m_ymax + v.y(), m_zmax + v.z() );
}

Box3D &Box3D::operator-=(const QVector3D &v)
{
    m_xmin -= v.x(); 
    m_ymin -= v.y(); 
    m_zmin -= v.z();
    m_xmax -= v.x(); 
    m_ymax -= v.y();
    m_zmax -= v.z();
    return *this;
}

Box3D &Box3D::operator+=(const QVector3D &v)
{
    m_xmin += v.x(); 
    m_ymin += v.y(); 
    m_zmin += v.z();
    m_xmax += v.x(); 
    m_ymax += v.y();
    m_zmax += v.z();
    return *this;
}

bool Box3D::isNull() const
{
  return ( std::isnan( m_xmin ) && std::isnan( m_xmax )
           && std::isnan( m_ymin ) && std::isnan( m_ymax )
           && std::isnan( m_zmin ) && std::isnan( m_zmax ) )
         ||
         ( m_xmin == std::numeric_limits<double>::max() && m_ymin == std::numeric_limits<double>::max() && m_zmin == std::numeric_limits<double>::max()
           && m_xmax == -std::numeric_limits<double>::max() && m_ymax == -std::numeric_limits<double>::max() && m_zmax == -std::numeric_limits<double>::max() );
}

void Box3D::scale(double scaleFactor, const Point3D &center)
{
    double centerX, centerY, centerZ;
    if ( !center.isEmpty() )
    {
        centerX = center.x();
        centerY = center.y();
        centerZ = center.z();
    }
    else
    {
        centerX = ( xMinimum() + xMaximum() ) / 2;
        centerY = ( yMinimum() + yMaximum() ) / 2;
        centerZ = ( zMinimum() + zMaximum() ) / 2;
    }
    scale( scaleFactor, centerX, centerY, centerZ );

}

void Box3D::scale(double scaleFactor, double centerX, double centerY, double centerZ)
{
    setXMinimum( centerX + ( xMinimum() - centerX ) * scaleFactor );
    setXMaximum( centerX + ( xMaximum() - centerX ) * scaleFactor );

    setYMinimum( centerY + ( yMinimum() - centerY ) * scaleFactor );
    setYMaximum( centerY + ( yMaximum() - centerY ) * scaleFactor );

    setZMinimum( centerZ + ( zMinimum() - centerZ ) * scaleFactor );
    setZMaximum( centerZ + ( zMaximum() - centerZ ) * scaleFactor );

}

void Box3D::normalize()
{  
    if ( m_zmin > m_zmax )
    {
        std::swap( m_zmin, m_zmax );
    }
    if ( m_xmin > m_xmax )
    {
        std::swap( m_xmin, m_xmax );
    }
      if ( m_ymin > m_ymax )
    {
        std::swap( m_ymin, m_ymax );
    }
}

QVector3D Box3D::center()
{
  return QVector3D( 0.5 * ( m_xmin + m_xmax),
                      0.5 * ( m_ymin + m_ymax ),
                      0.5 * ( m_zmin + m_zmax ) );
}

bool Box3D::intersects(const Box3D &other) const
{
    const double x1 = ( m_xmin > other.m_xmin ? m_xmin : other.m_xmin );
    const double x2 = ( m_xmax < other.m_xmax ? m_xmax : other.m_xmax );
    if ( x1 > x2 )
        return false;
    const double y1 = ( m_ymin > other.m_ymin ? m_ymin : other.m_ymin );
    const double y2 = ( m_ymax < other.m_ymax ? m_ymax : other.m_ymax );
    if (y1 <= y2)
        return false;
    const double z1 = ( m_zmin > other.m_zmin ? m_zmin : other.m_zmin );
    const double z2 = ( m_zmax < other.m_zmax ? m_zmax : other.m_zmax );
    return z1 <= z2;
}

bool Box3D::contains(const Point3D &point) const
{
    return contains( point.x(), point.y(), point.z() );
}

bool Box3D::contains(double x, double y, double z) const
{
    return (m_xmin <= x && x <= m_xmax) ||
           (m_ymin <= y && y <= m_ymax) ||
           (m_zmin <= z && z <= m_zmax) ;
}

bool Box3D::contains(const Box3D &other) const
{

    
    return other.m_xmin >= m_xmin && other.m_xmax <= m_xmax &&
           other.m_ymin >= m_zmin && other.m_ymax <= m_zmax &&
           other.m_zmin >= m_zmin && other.m_zmax <= m_zmax ;
}
