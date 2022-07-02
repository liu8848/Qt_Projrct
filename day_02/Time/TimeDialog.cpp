#include "TimeDialog.h"
#include<QFont>
TimeDialog::TimeDialog(){
	m_label=new QLabel(this);
	m_label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
	m_label->setAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
	QFont font;
	font.setPointSize(20);
	m_label->setFont(font);

	m_button=new QPushButton("获取当前时间",this);
	m_button->setFont(font);

	QVBoxLayout*layout=new QVBoxLayout(this);
	layout->addWidget(m_label);
	layout->addWidget(m_button);
	setLayout(layout);


	connect(m_button,&QPushButton::clicked,this,&TimeDialog::getTime);
	connect(this,&TimeDialog::mySignal,m_label,&QLabel::setText);
}


void TimeDialog::getTime(){
	qDebug("getTime");
	QTime time=QTime::currentTime();
	QString str=time.toString("hh:mm:ss");
	emit mySignal(str);
	//	m_label->setText(str);
}
