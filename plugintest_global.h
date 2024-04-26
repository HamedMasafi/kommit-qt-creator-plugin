#pragma once

#include <qglobal.h>

#if defined(PLUGINTEST_LIBRARY)
#define PLUGINTEST_EXPORT Q_DECL_EXPORT
#else
#define PLUGINTEST_EXPORT Q_DECL_IMPORT
#endif
