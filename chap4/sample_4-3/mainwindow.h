#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QColor>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_hSliderRed_valueChanged(int value);


    void on_hSliderVertical_valueChanged(int value);

    void on_dial_valueChanged(int value);

    void on_radioHex_clicked();

    void on_radioOct_clicked();

    void on_radioBin_clicked();

    void on_radioDec_clicked();

    void on_verticalSlider_valueChanged(int value);

    void on_bntExit_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
