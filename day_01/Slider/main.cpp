#include<QApplication>
#include<QDialog>
#include<QSlider>
#include<QSpinBox>

int main(int argc,char**argv){
	QApplication app(argc,argv);

	QDialog parent;
	parent.resize(220,100);
	parent.show();

	QSlider slider(Qt::Horizontal,&parent);
	slider.move(30,50);
	slider.setRange(0,100);
	slider.show();

	QSpinBox sb(&parent);
	sb.move(150,50);
	sb.setRange(0,100);
	sb.show();
	
	QObject::connect(&slider,&QSlider::valueChanged,&sb,&QSpinBox::setValue);
	QObject::connect(&sb,&QSpinBox::valueChanged,&slider,&QSlider::setValue);

	return app.exec();
}
