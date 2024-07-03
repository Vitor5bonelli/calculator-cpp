#include "mainwindow.h"
#include "ui_mainwindow.h"

double calcVal = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->display->setText(QString::number(calcVal));
    QPushButton *numButtons[10];

    for(int i = 0; i <10; i++){
        QString butName = "button_" + QString::number(i);
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);
        connect(numButtons[i], SIGNAL(released()), this,
                SLOT(NumPress()));
    }

    connect(ui->button_sum, SIGNAL(released()), this, SLOT(MathButtonPress()));
    connect(ui->button_sub, SIGNAL(released()), this, SLOT(MathButtonPress()));
    connect(ui->button_multiply, SIGNAL(released()), this, SLOT(MathButtonPress()));
    connect(ui->button_divide, SIGNAL(released()), this, SLOT(MathButtonPress()));

    connect(ui->button_equals, SIGNAL(released()), this, SLOT(EqualButton()));

    connect(ui->button_ac, SIGNAL(released()), this, SLOT(ResetCalculator()));

    connect(ui->button_moreorless, SIGNAL(released()), this, SLOT(ChangeNumberSign()));
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


void MainWindow::MathButtonPress(){
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    QString displayVal = ui->display->text();

    calcVal = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();

    if( QString::compare(butVal, "/", Qt::CaseInsensitive) == 0){
        divTrigger = true;
    }
    else if( QString::compare(butVal, "*", Qt::CaseInsensitive) == 0){
        multTrigger = true;
    }
    else if( QString::compare(butVal, "+", Qt::CaseInsensitive) == 0){
        addTrigger = true;
    }
    else {
        subTrigger = true;
    }

    ui->display->setText("");
}

void MainWindow::EqualButton(){
    double solution = 0.0;
    QString displayVal = ui->display->text();
    double dbDisplayVal = displayVal.toDouble();

    if(addTrigger){
        solution = calcVal + dbDisplayVal;
    }
    else if(subTrigger){
        solution = calcVal - dbDisplayVal;
    }
    else if(multTrigger){
        solution = calcVal * dbDisplayVal;
    }
    else {
        solution = calcVal / dbDisplayVal;
    }

    ui->display->setText(QString::number(solution));

}

void MainWindow::ResetCalculator(){
    ui->display->setText("0");
    calcVal = 0.0;
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
}

void MainWindow::ChangeNumberSign(){
    QString displayVal = ui->display->text();
    double dbDisplayVal = displayVal.toDouble();

    if( (dbDisplayVal != 0.0) || (dbDisplayVal != 0)){
        dbDisplayVal *= -1;
    }

    ui->display->setText(QString::number(dbDisplayVal));
}











