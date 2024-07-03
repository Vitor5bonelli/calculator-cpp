#include "mainwindow.h"
#include "ui_mainwindow.h"

double calcValue = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->display->setText(QString::number(calcValue));
    QPushButton *numButtons[10];

    for(int i = 0; i <10; i++){
        QString butName = "button_" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPress()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::NumPress(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->display->text();

    if( (displayVal.toDouble() == 0) || (displayVal.toDouble() == 0.0)){
        ui->display->setText(butVal);
    }
    else {
        QString newVal = displayVal + butVal;
        double dbNewVal = newVal.toDouble();
        ui->display->setText(QString::number(dbNewVal, 'g', 16));
    }
}






















