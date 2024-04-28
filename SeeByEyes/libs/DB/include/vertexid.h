#ifndef VERTEX_H
#define VERTEX_H

#include <QMetaEnum>

#include "db.h"

class AbstractGeom;

enum class VertexType : int
    {
    Segment  = 1, //折线顶点
    Curve  = 2, //曲线顶点
};
Q_ENUM( VertexType )

struct  DB_LIB_API VertexId
{
  explicit VertexId( int _part = -1, int _ring = -1, int _vertex = -1, Qgis::VertexType _type = Qgis::VertexType::Segment )
: part( _part )
  , ring( _ring )
  , vertex( _vertex )
  , type( _type )
  {}

  /**
   * Returns TRUE if the vertex id is valid
   */
  bool isValid() const   { return part >= 0 && ring >= 0 && vertex >= 0; }

  bool operator==( VertexId other ) const 
  {
    return part == other.part && ring == other.ring && vertex == other.vertex;
  }
  bool operator!=( VertexId other ) const 
  {
    return part != other.part || ring != other.ring || vertex != other.vertex;
  }

  /**
   * Returns TRUE if this vertex ID belongs to the same part as another vertex ID.
   */
  bool partEqual( VertexId o ) const 
  {
    return part >= 0 && o.part == part;
  }

  /**
   * Returns TRUE if this vertex ID belongs to the same ring as another vertex ID (i.e. the part
   * and ring number are equal).
   */
  bool ringEqual( VertexId o ) const 
  {
    return partEqual( o ) && ( ring >= 0 && o.ring == ring );
  }

  /**
   * Returns TRUE if this vertex ID corresponds to the same vertex as another vertex ID (i.e. the part,
   * ring number and vertex number are equal).
   */
  bool vertexEqual( VertexId o ) const 
  {
    return ringEqual( o ) && ( vertex >= 0 && o.ring == ring );
  }

  /**
   * Returns TRUE if this vertex ID is valid for the specified \a geom.
   */
  bool isValid( const QgsAbstractGeometry *geom ) const ;

  //! Part number
  int part = -1;

  //! Ring number
  int ring = -1;

  //! Vertex number
  int vertex = -1;

  //! Vertex type
  Qgis::VertexType type = Qgis::VertexType::Segment;


};


#endif