#ifndef __LOGINDIALOG_H
#define __LOGINDIALOG_H

#include "ui_LoginDialog.h"
#include<QMessageBox>
#include<QDebug>

class LoginDialog:public QDialog,public Ui::Dialog
{
    Q_OBJECT
public:
    LoginDialog();

public slots:
    void onAccepted();
    void onRejected();

private:
};


#endif
