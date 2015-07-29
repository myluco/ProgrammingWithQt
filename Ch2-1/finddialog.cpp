#include "finddialog.h"
#include "ui_finddialog.h"

FindDialog::FindDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindDialog)
  {
    ui->setupUi(this);
    setWindowTitle(tr("Find"));

    setFixedSize(sizeHint().width(),sizeHint().height());
    connect(ui->findButton,SIGNAL(clicked()),this,SLOT(findClicked()));
    connect(ui->lineEdit, SIGNAL(textChanged(QString)),this,SLOT(enableFindButton(QString)));
    connect(ui->closeButton, SIGNAL(clicked()), this, SLOT(close()));


}
void FindDialog::findClicked()
{
    QString text = ui->lineEdit->text();
    Qt::CaseSensitivity cs =
            ui->caseCheckBox->isChecked() ? Qt::CaseSensitive
                                          : Qt::CaseInsensitive;
    if (ui->backwardCheckBox->isChecked()){
        emit findPrevious(text,cs);
    } else {
        emit findNext(text,cs);
    }
}

void FindDialog::enableFindButton(const QString &text){
    ui->findButton->setEnabled(!text.isEmpty());
}


FindDialog::~FindDialog()
{
    delete ui;
}
