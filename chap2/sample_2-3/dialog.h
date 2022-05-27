#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QApplication>
#include<QCheckBox>
#include<QRadioButton>
#include<QPlainTextEdit>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>

class Dialog : public QDialog
{
    Q_OBJECT
private:
    QCheckBox *checkBoxUnderline;
    QCheckBox *checkBoxItalic;
    QCheckBox *checkBold;

    QRadioButton *rBtnBlack;
    QRadioButton *rBtnBlue;
    QRadioButton *rBtnRed;

    QPlainTextEdit *plainTextEdit;

    QPushButton *bntOK;
    QPushButton *bntCancel;
    QPushButton *bntClose;

    QHBoxLayout *HLayout1;
    QHBoxLayout *HLayout2;
    QHBoxLayout *HLayout3;

    void iniUI();
    void iniSignalSlots();

private slots:
    void on_checkUnderLine(bool checked);
    void on_checkItalic(bool checked);
    void on_checkBold(bool checked);

    void setTextFontColor();
public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
};
#endif // DIALOG_H
