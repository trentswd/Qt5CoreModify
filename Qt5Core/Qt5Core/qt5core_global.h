#ifndef QT5CORE_GLOBAL_H
#define QT5CORE_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef QT5CORE_LIB
# define QT5CORE_EXPORT Q_DECL_EXPORT
#else
# define QT5CORE_EXPORT Q_DECL_IMPORT
#endif

#endif // QT5CORE_GLOBAL_H
