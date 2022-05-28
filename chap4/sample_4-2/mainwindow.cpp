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


// append
void MainWindow::on_bntAppend_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();
    ui->edtResult_2->setText(str1.append(str2));
}

// prepend
void MainWindow::on_bntPrepend_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();
    ui->edtResult_2->setText(str1.prepend(str2));
}

// toUpper
void MainWindow::on_bntToUpper_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    ui->edtResult_2->setText(str1.toUpper());
}

// toLower
void MainWindow::on_bntToLower_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    ui->edtResult_2->setText(str1.toLower());
}



void MainWindow::on_bntLeft_clicked()
{
    QString str1,str2;
    str1=ui->comboBox1_2->currentText();
    int v=ui->spinBox->value();
    str2=str1.left(v);
    ui->edtResult_2->setText(str2);

}


void MainWindow::on_bntRight_clicked()
{
    QString str1,str2;
    str1=ui->comboBox1_2->currentText();
    int v=ui->spinBox->value();
    str2=str1.right(v);
    ui->edtResult_2->setText(str2);
}





void MainWindow::on_bntSection_clicked()
{
    //section()函数
        int i;
        QString str1,str2,str3;
        str1=ui->comboBox1_2->currentText();
        i=ui->spinBox->value();
    //    str2=str1.section('\\',2,2);
        str3=ui->comboBox2_2->currentText();
        if (QString::compare(str3,"\\",Qt::CaseInsensitive)==0)
            str2=str1.section('\\',i,i+1); //
        else
            str2=str1.section(str3,i,i+1); //

        ui->edtResult_2->setText(str2);
}




void MainWindow::on_bntSimplified_clicked()
{
    QString str1;
    str1 = ui->comboBox1_2->currentText();
    str1 = str1.simplified();
    ui->edtResult_2->setText(str1);
}


void MainWindow::on_bntTrimed_clicked()
{
    QString str1;
    str1=ui->comboBox1_2->currentText();
    str1=str1.trimmed();
    ui->edtResult_2->setText(str1);

}

void MainWindow::on_bntSize_clicked()
{
    QString str1;
    str1 = ui->comboBox1_2->currentText();
    int i = str1.size();
    ui->spinBox->setValue(i);
    ui->label_7->setText("size() ");
}

void MainWindow::on_bntCount_clicked()
{
    QString str1;
    str1 = ui->comboBox1_2->currentText();
    int i = str1.count();
    ui->spinBox->setValue(i);
    ui->label_7->setText("size() ");
}


void MainWindow::on_bntIndexof_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();

    int i;
    i = str1.indexOf(str2);
    ui->spinBox->setValue(i);
    ui->label_7->setText("indexOf");
}


void MainWindow::on_bntLasteIndex_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();

    int i;
    i = str1.lastIndexOf(str2);
    ui->spinBox->setValue(i);
    ui->label_7->setText("lastIndexOf");
}




void MainWindow::on_bntEndswith_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();

    bool chk;
    chk = str1.endsWith(str2);
    ui->checkCotains->setChecked(chk);
    ui->checkCotains->setText("endsWith()");
    ui->checkCotains->sizeHint();
}

void MainWindow::on_bntStartWith_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();

    bool chk;
    chk = str1.startsWith(str2);
    ui->checkCotains->setChecked(chk);
    ui->checkCotains->setText("startWith()");
    ui->checkCotains->sizeHint();
}

void MainWindow::on_bntContains_clicked()
{
    QString str1,str2;
    str1 = ui->comboBox1_2->currentText();
    str2 = ui->comboBox2_2->currentText();

    bool chk;
    chk = str1.contains(str2);
    ui->checkCotains->setChecked(chk);
    ui->checkCotains->setText("contains()");
    ui->checkCotains->sizeHint();
}

void MainWindow::on_bntIsNull_clicked()
{
    QString str1;
    str1 = ui->comboBox1_2->currentText();
    bool chk;
    chk = str1.isNull();
    ui->checkCotains->setChecked(chk);
    ui->checkCotains->setText("isNull()");
    ui->checkCotains->sizeHint();
}


void MainWindow::on_bntIsempty_clicked()
{
    QString str1;
    str1 = ui->comboBox1_2->currentText();
    bool chk;
    chk = str1.isEmpty();
    ui->checkCotains->setChecked(chk);
    ui->checkCotains->setText("isEmpty()");
    ui->checkCotains->sizeHint();
}
