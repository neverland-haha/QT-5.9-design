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


void MainWindow::on_bntInit_clicked()
{
    QIcon icon;
    icon.addFile(":/images/icons/aim.ico");
    ui->comboBox->clear();
    for(int i = 0;i < 20;i++)
        ui->comboBox->addItem(icon,QString::asprintf("Item %d",i));
}

void MainWindow::on_bntInitCity_clicked()
{
    ui->comboBox_2->clear();
    QIcon icon(":/images/icons/UNIT.ICO");
    QMap<QString,int> City_Zone;
    City_Zone.insert("北京",10);
    City_Zone.insert("上海",21);
    City_Zone.insert("天津",22);
    City_Zone.insert("大连",411);
    City_Zone.insert("锦州",416);
    City_Zone.insert("徐州",516);
    City_Zone.insert("福州",591);
    City_Zone.insert("青岛",532);
    ui->comboBox_2->clear();
    foreach(auto str,City_Zone.keys())
        ui->comboBox_2->addItem(icon,str,City_Zone.value(str));
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{   if(!arg1.isEmpty())
    {
    QString zone = ui->comboBox_2->currentData().toString();
    ui->plainTextEdit->appendPlainText(arg1 + "区号:" + zone);
    }
}


void MainWindow::on_bntClear_clicked()
{
    ui->comboBox->clear();
}



void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{   if(!arg1.isEmpty())
      {
        ui->plainTextEdit->appendPlainText(arg1);
       }
}

void MainWindow::on_checkBox_2_stateChanged(bool checked)
{
    ui->plainTextEdit->setReadOnly(checked);
}



void MainWindow::on_bntClearContent_clicked()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_bntAdd_clicked()
{
    ui->comboBox->clear();
    QTextDocument *doc = ui->plainTextEdit->document();
    QIcon ico(":/images/icons/aim.ico");
    int num = doc->blockCount();
    for(int i = 0;i< num ;i++)
    {
        QTextBlock textLine = doc->findBlockByNumber(i);
        QString str = textLine.text();
        ui->comboBox->addItem(ico,str);
    }
}

void MainWindow::on_checkBox_2_clicked(bool checked)
{
    ui->plainTextEdit->setReadOnly(checked);
}

void MainWindow::on_plainTextEdit_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = ui->plainTextEdit->createStandardContextMenu();
    menu->exec(pos);
}
