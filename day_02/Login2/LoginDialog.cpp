#include"LoginDialog.h"

LoginDialog::LoginDialog():ui(new Ui::Dialog()){
    ui->setupUi(this);
    connect(ui->m_btnBox,&QDialogButtonBox::accepted,this,&LoginDialog::onAccepted);
    connect(ui->m_btnBox,&QDialogButtonBox::rejected,this,&LoginDialog::onRejected);
}

void LoginDialog::onAccepted(){
    if(ui->m_userNameEdit->text()=="admin"&&
        ui->m_passwordEdit->text()=="123456"){
            qDebug()<<"登陆成功";
            close();
    }else{
        QMessageBox msgBox(QMessageBox::Critical,"Error","用户名或密码错误",QMessageBox::Ok,this);
        msgBox.exec();
    }
}

void LoginDialog::onRejected(){
    QMessageBox msgBox(QMessageBox::Question,"登录","是否确定取消登录",QMessageBox::Yes|QMessageBox::No,this);
    if(msgBox.exec()==QMessageBox::Yes){
        close();
    }
}

LoginDialog::~LoginDialog(){
	delete ui;
}
