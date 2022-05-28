#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    fTimer = new QTimer(this);
    fTimer->setInterval(1000);
    fTimer->stop();
    connect(fTimer,SIGNAL(timeout()),this,SLOT(on_timer_timeout())); //关联定时器的信号与槽
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_bntReadTime_clicked()
{
    QDateTime currDateTime = QDateTime::currentDateTime();
    ui->timeEdit->setTime(currDateTime.time());
    ui->lineTime->setText(currDateTime.toString("hh:mm:ss"));
    ui->dateEdit->setDate(currDateTime.date());
    ui->lineDate->setText(currDateTime.toString("yyyy-MM-dd"));
    ui->dateTimeEdit->setDateTime(currDateTime);
    ui->lineDT->setText(currDateTime.toString("yyyy-MM-dd hh:mm:ss"));
}

void Dialog::on_bntSetDT_clicked()
{
    QString str = ui->lineDT->text();
    str = str.trimmed();
    if(!str.isEmpty())
    {
        QDateTime datetime = QDateTime::fromString(str,"yyyy-MM-dd hh:mm:ss");
        ui->dateTimeEdit->setDateTime(datetime);
    }
}


void Dialog::on_calendarWidget_selectionChanged()
{
    QDate dt = ui->calendarWidget->selectedDate();
    QString str = dt.toString("yyyy 年 M 月 d 日");
    ui->lineShowTime->setText(str);
}

void Dialog::on_timer_timeout()
{ //定时器中断响应槽函数
    QTime curTime=QTime::currentTime(); //获取当前时间

    ui->lcdHour->display(curTime.hour()); //显示  小时

    ui->lcdMiniute->display(curTime.minute());//显示  分钟

    ui->lcdSecond->display(curTime.second());//显示  秒

    int va=ui->progressBar->value(); //读取progressBar的数值
    ui->progressBar->setValue(va); //设置progressBar的数值
    va++;
    if (va>100)
        va=0;

}

void Dialog::on_bntStart_clicked()
{
    fTimer->start();//定时器开始工作
    ftimeCounter.start();//计时器开始工作
//更新各按键的状态
    ui->bntStart->setEnabled(false);
    ui->bntStop->setEnabled(true);
    ui->bntSetC->setEnabled(false);
}


void Dialog::on_bntStop_clicked()
{
    fTimer->stop();
    int tmMsec = ftimeCounter.elapsed();
    int ms = tmMsec %1000;
    int sec = tmMsec /1000;
    QString str = QString::asprintf("流逝时间: %d, %d 毫秒",sec,ms);
    ui->label_5->setText(str);
    ui->bntStart->setEnabled(true);
    ui->bntStop->setEnabled(false);
    ui->bntSetC->setEnabled(true);
}

void Dialog::on_bntSetC_clicked()
{
    fTimer->setInterval(ui->spinBoxSetT->value());
}
