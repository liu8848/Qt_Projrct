#include<QApplication>
#include<QLabel>
#include<QPushButton>
#include<QDialog>

int main(int argc,char**argv){
	QApplication app(argc,argv);
	QDialog parent;
	parent.resize(320,240);
	parent.show();

	QLabel label("我是标签",&parent);
	label.move(50,40);
	label.show();

	QPushButton button("点击关闭或打开标签",&parent);
	button.move(50,140);
	button.show();

	QPushButton button1("点击退出程序",&parent);
	button1.move(50,180);
	button1.show();

	//QObject::connect(&button,&QPushButton::clicked,&label,&QLabel::close);
	QObject::connect(&button,&QPushButton::clicked,&label,
			[&](){
			if(label.text()==""){
				label.setText("我是标签");
			}else{
				label.setText("");
			}
			});
	//QObject::connect(&button1,&QPushButton::clicked,&app,&QApplication::closeAllWindows);
	QObject::connect(&button1,&QPushButton::clicked,&parent,&QDialog::close);
	return app.exec();
}
