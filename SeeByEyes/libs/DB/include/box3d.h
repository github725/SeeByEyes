

#ifndef Box3D_H
#define Box3D_H

#include <QVector3D>

#include "db.h"
#include "point3d.h"

class DB_LIB_API Box3D
{
    Q_GADGET
public:
    Box3D( double xmin = std::numeric_limits<double>::quiet_NaN(), double ymin = std::numeric_limits<double>::quiet_NaN(), double zmin = std::numeric_limits<double>::quiet_NaN(),
            double xmax = std::numeric_limits<double>::quiet_NaN(), double ymax = std::numeric_limits<double>::quiet_NaN(), double zmax = std::numeric_limits<double>::quiet_NaN(),
            bool normalize = true );
    Box3D( const Point3D &p1, const Point3D &p2, bool normalize = true );

    
    //set 方法
    void setXMinimum( double x );
    void setXMaximum( double x );
    void setYMinimum( double y );
    void setYMaximum( double y );
    void setZMinimum( double z );
    void setZMaximum( double z );

    //get 方法
    double xMinimum() const  { return m_xmin; }
    double yMinimum() const  { return m_ymin; }
    double zMinimum() const  { return m_zmin; }
    double xMaximum() const  { return m_xmax; }
    double yMaximum() const  { return m_ymax; }
    double zMaximum() const  { return m_zmax; }

    //操作符重载，用于Box3D对象平移
    bool operator==( const Box3D &other ) const;

    Box3D operator-( const QVector3D &v ) const ;

    Box3D operator+( const QVector3D &v ) const ;

    Box3D &operator-=( const QVector3D &v ) ;

    Box3D &operator+=( const QVector3D &v ) ;

    bool isNull() const ;

    /**
     * Box3D对象旋转
     * scaleFactor:缩放比例
     * center:缩放中心点
     */
    void scale( double scaleFactor, const Point3D &center = Point3D() ) ;


    void scale( double scaleFactor, double centerX, double centerY, double centerZ ) ;

    void normalize() ;


    double width() const  { return m_xmax - m_xmin; }


    double height() const  { return m_ymax - m_ymin; }

    double depth() const  { return m_zmax - m_zmin; }

    QVector3D center();

    bool intersects( const Box3D &other ) const ;

    bool contains( const Point3D &point ) const ;
    bool contains( double x, double y, double z ) const ;
    bool contains( const Box3D &other) const ;

private:
    double m_xmin;
    double m_ymin;
    double m_zmin;
    double m_xmax;
    double m_ymax;
    double m_zmax;
};





#endif