#ifndef SUBTITLE_FILE_PARSER_H
#define SUBTITLE_FILE_PARSER_H

#include <QObject>
#include "globals.h"

namespace subtitle_resync {

/**
 \brief
 This class parses the subtitle file to extract and process the timestamps
 */

class subtitle_file_parser
{

public:
    subtitle_file_parser();

    /**
     This function checks the player's guess against the solution
     \param[in] a_str_filename Subtitle filename including path
     \return 0 Success
     \return -1 Unable to open file
     */
    qint32 Initialize(const QString& a_str_filename);

    /**
     This function performs the resync and writes into a different file
     \param[in] a_operation Type of operation to perform
     \param[in] a_magnitude If a_operation is offset, this is in milliseconds.
                If a_operation is multiply, timestamps are simply multiplied by a_magnitude. a_magnitude can be less than 1.
     \return 0 Success
     \return -1 Unable to open file
     */
    void Perform_resync(const e_resync_operation a_operation, const double a_magnitude);

private:
    QString m_str_filename;
};
}

#endif // SUBTITLE_FILE_PARSER_H
