#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include <ui_gotocelldialog.h>

namespace Ui {
class GotoCellDialog;
}

class GotoCellDialog : public QDialog, public Ui::GotoCellDialog
{
    Q_OBJECT

public:
    explicit GotoCellDialog(QWidget *parent = 0);
    ~GotoCellDialog();

private slots:
    void on_lineEdit_textChanged();


private:
    Ui::GotoCellDialog *ui;
};

#endif // GOTOCELLDIALOG_H
