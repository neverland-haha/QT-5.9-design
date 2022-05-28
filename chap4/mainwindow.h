#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QLabel>
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

    void on_bntDec_clicked();

    void on_bntBin_clicked();

    void on_bntHex_clicked();

    void on_bntCaculate_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
