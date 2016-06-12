#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGridLayout>
#include <QPushButton>
#include <QTextEdit>
#include <QRadioButton>
#include <QLabel>

#include "subtitle_file_parser.h"

namespace subtitle_resync {

/**
 \brief
 This is the main GUI class
 */

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = 0);
    ~mainwindow();

private:
    // GUI
    QGridLayout m_layout;
    QPushButton m_btn_load;
    QLabel m_label_filename;

    QPushButton m_btn_process;
    QLabel m_label_progress;
    QTextEdit m_text_magnitude;
    QRadioButton m_radio_offset;
    QRadioButton m_radio_multiply;

    // file variables
    subtitle_file_parser m_fileparser;
    QString m_str_filename;

private slots:
    void Clicked_load();
    void Clicked_process();
};
}

#endif // MAINWINDOW_H
