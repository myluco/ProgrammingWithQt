#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SortDialog)
{
    ui->setupUi(this);
    ui->secondaryGroupBox->hide();
    ui->tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);
}

SortDialog::~SortDialog()
{
    delete ui;
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    ui->primaryColumnCombo->clear();
    ui->secondaryColumnCombo->clear();
    ui->tertiaryColumnCombo->clear();

    ui->secondaryColumnCombo->addItem(tr("None"));
    ui->tertiaryColumnCombo->addItem(tr("None"));
    ui->primaryColumnCombo->setMinimumSize(ui->secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while(ch <= last) {
        ui->primaryColumnCombo->addItem(QString(ch));
        ui->secondaryColumnCombo->addItem(QString(ch));
        ui->tertiaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode() + 1;

    }
}

void SortDialog::changeToggleButtonText()
{
    if (ui->moreButton->text() == "&More") {
        ui->moreButton->setText("&Less");
        ui->secondaryGroupBox->show();
        ui->tertiaryGroupBox->show();
    } else {
         ui->moreButton->setText("&More");
         ui->secondaryGroupBox->hide();
         ui->tertiaryGroupBox->hide();
    }
}
