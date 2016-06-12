#include "mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>

subtitle_resync::mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
    , m_layout(this)
    , m_btn_load("Load file")
    , m_btn_process("Process")
    , m_radio_offset("Offset")
    , m_radio_multiply("Multiply")
{
    // Initialize GUI
    m_text_magnitude.setMaximumSize(100, 30);
    m_text_magnitude.setText("1.000");
    m_radio_multiply.setChecked(true);

    // GUI layout
    m_layout.addWidget(&m_btn_load, 0, 0);
    m_layout.addWidget(&m_label_filename, 0, 1, 1, 5);
    m_layout.addWidget(&m_text_magnitude, 1, 1);
    m_layout.addWidget(&m_btn_process, 1, 2);
    m_layout.addWidget(&m_radio_offset, 1, 0);
    m_layout.addWidget(&m_radio_multiply, 2, 0);
    m_layout.addWidget(&m_label_progress, 2, 2);

    // Button click signals
    connect(&m_btn_load, SIGNAL(clicked(bool)), this, SLOT(Clicked_load()));
    connect(&m_btn_process, SIGNAL(clicked(bool)), this, SLOT(Clicked_process()));
}

subtitle_resync::mainwindow::~mainwindow()
{
}

void subtitle_resync::mainwindow::Clicked_load()
{
    m_str_filename = QFileDialog::getOpenFileName(this,
                                                  tr("Select subtitle file"), "D:/Downloads", tr("Subtitle Files (*.srt)"));

    if(m_str_filename != ""){
        if (m_fileparser.Initialize(m_str_filename) == 0){
            m_label_filename.setText(m_str_filename);
            m_label_progress.setText("");
        }
        else{
            QMessageBox t_msgbox;
            t_msgbox.setText("Error: Unable to open file\n" + m_str_filename);
            t_msgbox.exec();
        }
    }
}

void subtitle_resync::mainwindow::Clicked_process()
{
    m_label_progress.setText("Resync...");
    e_resync_operation t_operation = m_radio_offset.isChecked() ? resync_operation_offset : resync_operation_multiply;
    m_fileparser.Perform_resync(t_operation, m_text_magnitude.toPlainText().toDouble());
    m_label_progress.setText("Resync...Complete");
}
