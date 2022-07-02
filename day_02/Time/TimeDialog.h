#ifndef __TIMEDIALOG_H
#define __TIMEDIALOG_H

#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QTime>
#include<QDebug>


class TimeDialog:public QDialog{
	Q_OBJECT
	public:
		TimeDialog();
	public slots:
		void getTime();
	signals:
		void mySignal(const QString&);
	private:
		QLabel*m_label;
		QPushButton*m_button;
};


#endif
