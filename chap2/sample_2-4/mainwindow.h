#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QProgressBar>
#include<QLabel>
#include<QSpinBox>
#include<QFontComboBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLabel *fLabelCurrFile;
    QProgressBar *progress;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;

private slots:

    void iniUI();



    void on_actBold_triggered(bool checked);

    void on_actItalic_triggered(bool checked);

    void on_actUnderline_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    void on_spinBoxFontSize_valueChanged(int aFontSize);//改变字体大小的SpinBox的响应
    void on_comboFont_currentIndexChanged(const QString &arg1);//FontCombobox的响应，选择字体名称

    void iniSignalSlots();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
