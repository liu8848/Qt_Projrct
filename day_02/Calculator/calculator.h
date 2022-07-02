#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QDialog>
#include<QDoubleValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QDialog
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();

public slots:
    void enableButton();
    void calcClicked();
private:
    Ui::Calculator *ui;
};
#endif // CALCULATOR_H
