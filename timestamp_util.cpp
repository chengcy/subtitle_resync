#include "timestamp_util.h"
#include <QTime>
#include <QDebug>

subtitle_resync::timestamp_util::timestamp_util()
{
}

QString subtitle_resync::timestamp_util::Perform_operation(const QString& a_timestamp, const e_resync_operation a_operation, const double a_magnitude)
{
    //qDebug() << "subtitle_resync::timestamp_util::Perform_operation";
    //qDebug() << a_timestamp << a_operation << a_magnitude;
    QStringList t_ts = a_timestamp.split(QRegExp(",|:"));

    QTime t_input_time(t_ts[0].toInt()
            , t_ts[1].toInt()
            , t_ts[2].toInt()
            , t_ts[3].toInt());
    QTime t_output_time(0, 0, 0, 0);
    qint32 t_total_msecs = t_input_time.msecsSinceStartOfDay();

    switch(a_operation){
    case resync_operation_multiply:
        t_total_msecs *= a_magnitude;
        break;
    case resync_operation_offset:
        t_total_msecs += a_magnitude;
        break;
    default:
        qDebug() << "subtitle_resync::timestamp_util::Perform_operation::Invalid a_operation"<<a_operation;
        break;
    }

    t_output_time = t_output_time.addMSecs(t_total_msecs);
    return t_output_time.toString("HH:mm:ss,zzz");
}
