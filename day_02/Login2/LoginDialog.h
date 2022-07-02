#ifndef __LOGINDIALOG_H
#define __LOGINDIALOG_H

#include "ui_LoginDialog.h"
#include<QMessageBox>
#include<QDebug>

class LoginDialog:public QDialog
{
    Q_OBJECT
public:
    LoginDialog();
    ~LoginDialog();

public slots:
    void onAccepted();
    void onRejected();

private:
    Ui::Dialog*ui;
};


#endif
