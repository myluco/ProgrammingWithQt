#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include <ui_sortdialog.h>

namespace Ui {
class SortDialog;
}

class SortDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SortDialog(QWidget *parent = 0);
    ~SortDialog();
    void setColumnRange(QChar first,QChar last);

private slots:
    void changeToggleButtonText();

private:
    Ui::SortDialog *ui;
};

#endif // SORTDIALOG_H
