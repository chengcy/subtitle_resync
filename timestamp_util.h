#ifndef TIMESTAMP_UTIL_H
#define TIMESTAMP_UTIL_H

#include <QString>
#include "globals.h"

namespace subtitle_resync {

/**
 \brief
 This is a helper class for timestamp related operations
 */

class timestamp_util
{

public:
    timestamp_util();

    /**
     This function checks the player's guess against the solution
     \param[in] a_str_filename Subtitle filename including path
     \return 0 Success
     \return -1 Unable to open file
     */
    static QString Perform_operation(const QString& a_timestamp, const e_resync_operation a_operation, const double a_magnitude);
};
}

#endif // TIMESTAMP_UTIL_H
