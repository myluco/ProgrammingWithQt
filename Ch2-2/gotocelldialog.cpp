#include "gotocelldialog.h"

#include <QDebug>


GotoCellDialog::GotoCellDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GotoCellDialog)
{
    ui->setupUi(this);
    ui->okButton->setEnabled(false);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    ui->lineEdit->setValidator(new QRegExpValidator(regExp,this));

    connect(ui->okButton,SIGNAL(clicked()),this,SLOT(accept()));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(reject()));
    //connect(ui->lineEdit,SIGNAL(textChanged(QString)),this,SLOT(on_lineEdit_textChanged()));


}

GotoCellDialog::~GotoCellDialog()
{
    delete ui;
}

void GotoCellDialog::on_lineEdit_textChanged()
{

    qDebug() << "In onLineEditTextChanged";
    ui->okButton->setEnabled(ui->lineEdit->hasAcceptableInput());
}
