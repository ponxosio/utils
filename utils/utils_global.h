#ifndef UTILS_GLOBAL_H
#define UTILS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(UTILS_LIBRARY)
#  define UTILS_EXPORT Q_DECL_EXPORT
#  define SEQUENCE_EXPORT Q_DECL_EXPORT
#  define AUTOENUMERATE_EXPORT Q_DECL_EXPORT
#  define PLUGINCONFIGURATION_EXPORT Q_DECL_EXPORT
#  define FILESENDER_EXPORT Q_DECL_EXPORT
#  define SERIALSENDER_EXPORT Q_DECL_EXPORT
#else
#  define UTILS_EXPORT Q_DECL_IMPORT
#  define SEQUENCE_EXPORT Q_DECL_IMPORT
#  define AUTOENUMERATE_EXPORT Q_DECL_IMPORT
#  define PLUGINCONFIGURATION_EXPORT Q_DECL_IMPORT
#  define FILESENDER_EXPORT Q_DECL_EXPORT
#  define SERIALSENDER_EXPORT Q_DECL_EXPORT
#endif

#endif // UTILS_GLOBAL_H
