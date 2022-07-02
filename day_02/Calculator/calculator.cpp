#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Calculator)
{
    ui->setupUi(this);
    ui->m_cbBox->addItems({"+","-","*","/"});
    this->resize(800,200);

    connect(ui->m_editX,&QLineEdit::textChanged,this,&Calculator::enableButton);
    connect(ui->m_EditY,&QLineEdit::textChanged,this,&Calculator::enableButton);
    connect(ui->m_button,&QPushButton::clicked,this,&Calculator::calcClicked);

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::enableButton(){
    bool X,Y;
    ui->m_editX->text().toDouble(&X);
    ui->m_EditY->text().toDouble(&Y);
    ui->m_button->setEnabled(X&&Y);
}

void Calculator::calcClicked(){
    double x=ui->m_editX->text().toDouble(),y=ui->m_EditY->text().toDouble();
    QString symbel=ui->m_cbBox->currentText();

    double res=0;
    if(symbel=="+") res=x+y;
    else if(symbel=="-") res=x-y;
    else if(symbel=="*") res=x*y;
    else if(symbel=="/"){
        if(y==0) res=0;
        else res=x/y;
    }
    QString str=QString::number(res);
    ui->m_editZ->setText(str);
}

