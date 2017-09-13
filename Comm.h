#ifndef COMM_H
#define COMM_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QDebug>
static long debug_count = 0;
static long warning_count = 0;
static long fatal_count = 0;

#include <QString>
#define HS_Debug qDebug() << (QString( "Debug [%1 %2:%3 %4]" ).arg (__FILE__).arg (__FUNCTION__).arg(__LINE__).arg (++debug_count))
#define HS_Warning qWarning() << (QString( "Warning [%1 %2:%3 %4]" ).arg (__FILE__).arg (__FUNCTION__).arg(__LINE__).arg (++warning_count))
#define HS_critical qCritical() << (QString( "Critical [%1 %2:%3 %4]" ).arg (__FILE__).arg (__FUNCTION__).arg(__LINE__).arg (++fatal_count))
#define HS_Item(i) (i)




#endif // COMM_H
