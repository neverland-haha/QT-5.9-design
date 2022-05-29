#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextDocument>
#include<QTextBlock>
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
    void on_bntInit_clicked();

    void on_bntInitCity_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_bntClear_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_checkBox_2_stateChanged(bool checked);

    void on_bntClearContent_clicked();

    void on_bntAdd_clicked();

    void on_checkBox_2_clicked(bool checked);

    void on_plainTextEdit_customContextMenuRequested(const QPoint &pos);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
