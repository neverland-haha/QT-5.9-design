#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_bntAppend_clicked();

    void on_bntPrepend_clicked();

    void on_bntToUpper_clicked();

    void on_bntToLower_clicked();

    void on_bntLeft_clicked();

    void on_bntRight_clicked();

    void on_bntSection_clicked();

    void on_bntSimplified_clicked();

    void on_bntTrimed_clicked();

    void on_bntSize_clicked();

    void on_bntCount_clicked();

    void on_bntIndexof_clicked();

    void on_bntLasteIndex_clicked();

    void on_bntEndswith_clicked();

    void on_bntStartWith_clicked();

    void on_bntContains_clicked();

    void on_bntIsNull_clicked();

    void on_bntIsempty_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
