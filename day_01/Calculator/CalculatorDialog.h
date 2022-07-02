#ifndef __CALCULATORDIALOG_H
#define __CALCULATORDIALOG_H

#include<QDialog>
#include<QLabel>
#include<QPushButton>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QDoubleValidator>
#include<QComboBox>
class CalculatorDialog:public QDialog{
	Q_OBJECT
	public:
		CalculatorDialog();
	public slots:
		void enableButton();
		void calcClicked();
	private:
	QLineEdit*m_edit_x;
	QLineEdit*m_edit_y;
	QLineEdit*m_edit_z;
	QLabel*m_label;
	QPushButton*m_button;
	QComboBox*m_comboBox;

};
#endif
