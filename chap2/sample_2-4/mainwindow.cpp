#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("摸鱼万岁");
    iniUI();
    iniSignalSlots();
    setCentralWidget(ui->textEdit);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::iniUI()
{
    fLabelCurrFile = new QLabel;
    fLabelCurrFile->setMidLineWidth(150);
    fLabelCurrFile->setText(tr("当前文件: "));
    ui->statusbar->addWidget(fLabelCurrFile);

    progress = new QProgressBar;
    progress->setMinimum(5);
    progress->setMaximum(50);
    progress->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progress);

    spinFontSize = new QSpinBox;
    spinFontSize->setMaximum(5);
    spinFontSize->setMaximum(50);
    ui->toolBar->addWidget(new QLabel(tr("字体大小")));
    ui->toolBar->addWidget(spinFontSize);

    comboFont = new QFontComboBox;
    ui->toolBar->addWidget(new QLabel(tr("字体")));
    ui->toolBar->addWidget(comboFont);

}



void MainWindow::on_actBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}



void MainWindow::on_actItalic_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_actUnderline_triggered(bool checked)
{
    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actCut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());
}

void MainWindow::on_textEdit_selectionChanged()
{

    QTextCharFormat fmt;
    fmt = ui->textEdit->currentCharFormat();
    ui->actItalic->setChecked(fmt.fontItalic());
    ui->actBold->setChecked(fmt.font().bold());
    ui->actUnderline->setChecked(fmt.fontUnderline());
}

void MainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{//改变字体大小的SpinBox的响应
    QTextCharFormat fmt;
    fmt.setFontPointSize(aFontSize); //设置字体大小
    ui->textEdit->mergeCurrentCharFormat(fmt);
    progress->setValue(aFontSize);
}

void MainWindow::on_comboFont_currentIndexChanged(const QString &arg1)
{//FontCombobox的响应，选择字体名称
    QTextCharFormat fmt;
    fmt.setFontFamily(arg1);//设置字体名称
    ui->textEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::iniSignalSlots()
{
    connect(spinFontSize,SIGNAL(valueChanged(int)),
            this,SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QString &)),
            this,SLOT(on_comboFont_currentIndexChanged(const QString &)));
}
