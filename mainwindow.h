#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void NumPress();
    void MathButtonPress();
    void EqualButton();
    void ResetCalculator();
    void ChangeNumberSign();
    void ToSquare();
    void MakeDecimal();

};
#endif // MAINWINDOW_H
