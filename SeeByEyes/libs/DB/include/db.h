
#ifndef DB_HEADER
#define DB_HEADER

#include <cmath>

#include <QtCore/QtGlobal>

#if defined( DB_LIBRARY_BUILD )
#  define DB_LIB_API Q_DECL_EXPORT
#else
#  define DB_LIB_API Q_DECL_IMPORT
#endif

#endif