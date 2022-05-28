#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{

    delete ui;

}




void MainWindow::on_bntDec_clicked()
{
    QString str = ui->lineDec->text();

    int value = str.toInt();
    str = str.setNum(value,2);
    ui->lineBin->setText(str);

    str = str.setNum(value,16);
    ui->lineHex->setText(str.toUpper());
}

void MainWindow::on_bntBin_clicked()
{
    QString str = ui->lineBin->text();
    bool ok;
    int value = str.toInt(&ok,2);
    ui->lineDec->setText(QString::number(value));
    ui->lineHex->setText(QString::number(value,16).toUpper());
}



void MainWindow::on_bntHex_clicked()
{
    QString str = ui->lineHex->text();
    bool ok;
    int value = str.toInt(&ok,16);
    ui->lineDec->setText(QString::number(value));
    ui->lineBin->setText(QString::number(value,2).toUpper());
}

void MainWindow::on_bntCaculate_clicked()
{
   int num = ui->spinBoxNum->value();
   float price = ui->doubleSprice->value();
   float total = num * price;
   ui->doubleDprice->setValue(total);

}

void MainWindow::on_spinBoxNum_valueChanged(const QString &arg1)
{
   Q_UNUSED(arg1);
   on_bntCaculate_clicked();
}



void MainWindow::on_doubleSprice_valueChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    on_bntCaculate_clicked();
}
