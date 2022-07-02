#include"CalculatorDialog.h"

CalculatorDialog::CalculatorDialog(){
	setWindowTitle("Calculator");
	m_edit_x=new QLineEdit(this);
	m_edit_x->setAlignment(Qt::AlignRight);
	m_edit_x->setValidator(new QDoubleValidator(this));
	m_edit_y=new QLineEdit(this);
	m_edit_y->setAlignment(Qt::AlignRight);
        m_edit_y->setValidator(new QDoubleValidator(this));

	m_edit_z=new QLineEdit(this);
	m_edit_z->setAlignment(Qt::AlignRight);
        m_edit_z->setReadOnly(true);

	//m_label=new QLabel("+",this);
	m_button=new QPushButton("=",this);
	m_button->setEnabled(false);
	
	m_comboBox=new QComboBox(this);
	m_comboBox->addItem("+");
	m_comboBox->addItem("-");
	m_comboBox->addItem("*");
	m_comboBox->addItem("/");

	QHBoxLayout*layout=new QHBoxLayout(this);
	layout->addWidget(m_edit_x);
	//layout->addWidget(m_label);
	layout->addWidget(m_comboBox);
	layout->addWidget(m_edit_y);
	layout->addWidget(m_button);
	layout->addWidget(m_edit_z);

	setLayout(layout);

	connect(m_edit_x,&QLineEdit::textChanged,this,&CalculatorDialog::enableButton);
	connect(m_edit_y,&QLineEdit::textChanged,this,&CalculatorDialog::enableButton);
	connect(m_button,&QPushButton::clicked,this,&CalculatorDialog::calcClicked);
}

void CalculatorDialog::enableButton(){
	bool bXok,bYok;
	m_edit_x->text().toDouble(&bXok);
	m_edit_y->text().toDouble(&bYok);
	m_button->setEnabled(bXok&&bYok);
}

void CalculatorDialog::calcClicked(){

	//double res=m_edit_x->text().toDouble()+m_edit_y->text().toDouble();
	double x=m_edit_x->text().toDouble(),y=m_edit_y->text().toDouble();
	QString symbel=m_comboBox->currentText();
	double res;
	if(symbel=="+") res=x+y;
	else if(symbel=="-") res=x-y;
	else if(symbel=="*") res=x*y;
	else if(symbel=="/"){
		if(y==0) res=0;
		else res=x/y;
	}
	QString str=QString::number(res);
	m_edit_z->setText(str);
}
