#include "subtitle_file_parser.h"
#include "timestamp_util.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

#include <QDebug>

subtitle_resync::subtitle_file_parser::subtitle_file_parser()
{
}

qint32 subtitle_resync::subtitle_file_parser::Initialize(const QString& a_str_filename)
{
    // Initialize
    qint32 t_retcode = -1;
    m_str_filename = a_str_filename;

    // Try open
    QFile t_input_file(m_str_filename);
    if(t_input_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        t_retcode = 0;
        t_input_file.close();
    }

    return t_retcode;
}

void subtitle_resync::subtitle_file_parser::Perform_resync(const e_resync_operation a_operation, const double a_magnitude)
{
    // Open file
    QFile t_input_file(m_str_filename);
    if(t_input_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QFileInfo t_infile_info(t_input_file);
        QFile t_output_file(t_infile_info.absolutePath()
                            + "/synced_"
                            + t_infile_info.baseName()
                            + t_infile_info.completeSuffix());
        t_output_file.open(QIODevice::WriteOnly | QIODevice::Text);

        QTextStream t_input_text(&t_input_file);
        QTextStream t_output_text(&t_output_file);
        QString t_line;

        // Read for the header. Next line after header is timing
        while(t_input_text.readLineInto(&t_line)){
            t_output_text << t_line << "\n";
            bool t_is_int;
            t_line.toInt(&t_is_int);

            // The next t_line is the timestamp. Get LHS and RHS to perform desired operation
            if(t_is_int){
                QString t_timestamp;
                t_input_text.readLineInto(&t_timestamp);
                QStringList t_sl = t_timestamp.split(" --> ");

                if(t_sl.size() == 2){
                    t_timestamp = timestamp_util::Perform_operation(t_sl[0], a_operation, a_magnitude)
                            + " --> "
                            + timestamp_util::Perform_operation(t_sl[1], a_operation, a_magnitude);
                    t_output_text << t_timestamp << "\n";
                }
                else{
                    qDebug() << "Invalid timestamp header found: " << t_line;
                }
            }
        }

        t_input_file.close();
        t_output_file.close();
    }
}
