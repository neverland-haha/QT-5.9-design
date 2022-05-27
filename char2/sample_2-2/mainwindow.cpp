#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDir>
#include<QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->radioBlue,SIGNAL(clicked()),this,SLOT(setTextFontcolor()));
    QObject::connect(ui->radioRed,SIGNAL(clicked()),this,SLOT(setTextFontcolor()));
    QObject::connect(ui->radioBlack,SIGNAL(clicked()),this,SLOT(setTextFontcolor()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBoxUnderline_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

void MainWindow::on_checkBoxItalic_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}


void MainWindow::on_checkBoxBold_clicked(bool checked)
{
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void MainWindow::setTextFontcolor()
{
    QPalette plte = ui->plainTextEdit->palette();
    if(ui->radioRed->isChecked())
        plte.setColor(QPalette::Text,Qt::red);
    else if(ui->radioBlue->isChecked())
            plte.setColor(QPalette::Text,Qt::blue);
    else if(ui->radioBlack->isChecked())
        plte.setColor(QPalette::Text,Qt::black);
    ui->plainTextEdit->setPalette(plte);

}
