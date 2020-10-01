/// @file
///
/// @author
///
/// @copyright

#include "main_window.hpp"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->plainTextEdit->document(), SIGNAL(contentsChange(int, int, int)), this,
            SLOT(plain_text_changed(int, int, int)));
    connect(ui->morseTextEdit->document(), SIGNAL(contentsChange(int, int, int)), this,
            SLOT(morse_text_changed(int, int, int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::plain_text_changed(int /*pos*/, int /*del*/, int /*add*/)
{
    //    auto text = ui->plainTextEdit->toPlainText().mid(pos, add);
    auto text = ui->plainTextEdit->toPlainText();
    auto morse_text = morse_translator.Text2Morse(text.toUtf8().constData());
    ui->morseTextEdit->document()->blockSignals(true);
    ui->morseTextEdit->moveCursor(QTextCursor::End);
    //    ui->morseTextEdit->insertPlainText(morse_text.c_str());
    ui->morseTextEdit->setPlainText(morse_text.c_str());
    ui->morseTextEdit->moveCursor(QTextCursor::End);
    ui->morseTextEdit->document()->blockSignals(false);
}

void MainWindow::morse_text_changed(int /*pos*/, int /*del*/, int /*add*/)
{
    //    auto text = ui->morseTextEdit->toPlainText().mid(pos, add);
    auto text = ui->morseTextEdit->toPlainText();
    auto plain_text = morse_translator.Morse2Text(text.toUtf8().constData());
    ui->plainTextEdit->document()->blockSignals(true);
    ui->plainTextEdit->moveCursor(QTextCursor::End);
    //    ui->plainTextEdit->insertPlainText(morse_text.c_str());
    ui->plainTextEdit->setPlainText(plain_text.c_str());
    ui->plainTextEdit->moveCursor(QTextCursor::End);
    ui->plainTextEdit->document()->blockSignals(false);
}
