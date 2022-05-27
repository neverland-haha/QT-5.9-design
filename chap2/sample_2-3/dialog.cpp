#include "dialog.h"

void Dialog::iniUI()
{
    // 水平布局1
    HLayout1 = new QHBoxLayout();
    checkBoxUnderline = new QCheckBox(tr("Underline"));
    checkBoxItalic = new QCheckBox(tr("Italic"));
    checkBold = new QCheckBox(tr("Bold"));
    HLayout1->addWidget(checkBoxUnderline);
    HLayout1->addWidget(checkBoxItalic);
    HLayout1->addWidget(checkBold);

    // 水平布局2
    HLayout2 = new QHBoxLayout();
    rBtnBlack = new QRadioButton(tr("Black"));
    rBtnBlue = new QRadioButton(tr("Blue"));
    rBtnRed = new QRadioButton(tr("Red"));
    HLayout2->addWidget(rBtnBlack);
    HLayout2->addWidget(rBtnBlue);
    HLayout2->addWidget(rBtnRed);

    plainTextEdit = new QPlainTextEdit();
    QFont font = plainTextEdit->font();
    font.setPointSize(20);
    plainTextEdit->setFont(font);
    plainTextEdit->setPlainText("Hello World\n\nThis is Arxbye");

    //水平布局3
    HLayout3 = new QHBoxLayout();
    bntOK = new QPushButton(tr("确定"));
    bntCancel = new QPushButton(tr("取消"));
    bntClose = new QPushButton(tr("退出"));
    HLayout3->addWidget(bntOK);
    HLayout3->addWidget(bntCancel);
    HLayout3->addWidget(bntClose);

    //添加垂直布局
    QVBoxLayout *VLayout = new QVBoxLayout;
    VLayout->addLayout(HLayout1);
    VLayout->addLayout(HLayout2);
    VLayout->addWidget(plainTextEdit);
    VLayout->addLayout(HLayout3);
    setLayout(VLayout);
}

void Dialog::iniSignalSlots()
{
    connect(bntOK,SIGNAL(clicked()),this,SLOT(accept()));
    connect(bntCancel,SIGNAL(clicked()),this,SLOT(reject()));
    connect(bntClose,SIGNAL(clicked()),this,SLOT(close()));

    connect(checkBoxUnderline,SIGNAL(clicked(bool)),this,SLOT(on_checkUnderLine(bool)));
    connect(checkBoxItalic,SIGNAL(clicked(bool)),this,SLOT(on_checkItalic(bool)));
    connect(checkBold,SIGNAL(clicked(bool)),this,SLOT(on_checkBold(bool)));

    connect(rBtnRed,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlue,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
    connect(rBtnBlack,SIGNAL(clicked()),this,SLOT(setTextFontColor()));
}

void Dialog::on_checkUnderLine(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setUnderline(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkItalic(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setItalic(checked);
    plainTextEdit->setFont(font);
}

void Dialog::on_checkBold(bool checked)
{
    QFont font = plainTextEdit->font();
    font.setBold(checked);
    plainTextEdit->setFont(font);
}

void Dialog::setTextFontColor()
{
    QPalette plet = plainTextEdit->palette();
    if(rBtnBlack->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else if(rBtnBlue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(rBtnRed->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    else
        plet.setColor(QPalette::Text,Qt::black);
   plainTextEdit->setPalette(plet);
}


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
     iniUI();
     iniSignalSlots();

}

Dialog::~Dialog()
{

}

