#include<QApplication>
#include<QLabel>
#include<QPushButton>
#include<QWidget>
int main(int argc,char**argv){
	QApplication app(argc,argv);
	QWidget parent;
	parent.show();
	QLabel label("label");
	label.setParent(&parent);
	label.show();

	QPushButton button("button",&parent);
	button.move(0,30);
	button.show();
	return app.exec();
}
