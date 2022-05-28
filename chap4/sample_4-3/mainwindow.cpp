#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("摸鱼快乐");
    connect(ui->hSliderBlue,SIGNAL(valueChanged(int)),
            this,SLOT(on_hSliderRed_valueChanged(int)));
    connect(ui->hSliderGreen,SIGNAL(valueChanged(int)),
            this,SLOT(on_hSliderRed_valueChanged(int)));
    connect(ui->hSliderAlpha,SIGNAL(valueChanged(int)),
            this,SLOT(on_hSliderRed_valueChanged(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_hSliderRed_valueChanged(int value)
{
    QColor color;
    Q_UNUSED(value);
    int R = ui->hSliderRed->value();
    int B = ui->hSliderBlue->value();
    int G = ui->hSliderGreen->value();
    int alpha = ui->hSliderAlpha->value();
    color.setRgb(R,G,B,alpha);
    QPalette pal = ui->textColor->palette();
    pal.setColor(QPalette::Base,color);
    ui->textColor->setPalette(pal);
}


void MainWindow::on_hSliderVertical_valueChanged(int value)
{
    ui->hProcessBar->setValue(value);
    ui->horizontalScrollBar->setValue(value);
}

void MainWindow::on_dial_valueChanged(int value)
{
    ui->lcdNumber->display(value);
}

void MainWindow::on_radioHex_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setHexMode();
}

void MainWindow::on_radioOct_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setOctMode();
}


void MainWindow::on_radioBin_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setBinMode();
}


void MainWindow::on_radioDec_clicked()
{
    ui->lcdNumber->setDigitCount(3);
    ui->lcdNumber->setDecMode();
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
    ui->VProcessBar->setValue(value);
    ui->verticalScrollBar->setValue(value);
}

void MainWindow::on_bntExit_clicked()
{
    this->close();
}
