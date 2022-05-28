#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QTimer>
#include<QTime>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

private:
    QTimer *fTimer;  //定时器
    QTime  ftimeCounter;

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_bntReadTime_clicked();

    void on_bntSetDT_clicked();

    void on_calendarWidget_selectionChanged();

    void on_timer_timeout();

    void on_bntStart_clicked();

    void on_bntStop_clicked();

    void on_bntSetC_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
