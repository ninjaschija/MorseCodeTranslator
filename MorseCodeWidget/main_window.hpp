/// @file
///
/// @author
///
/// @copyright

#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>
#include <morse_code_translator.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();

private slots:
    void plain_text_changed(int, int, int);
    void morse_text_changed(int, int, int);

private:
    Ui::MainWindow* ui;
    morse_code_engine::MorseCodeTranslator morse_translator;
};

#endif // MAIN_WINDOW_HPP
