#ifndef SECDIALOG_H
#define SECDIALOG_H

#include <QDialog>
#include <QPainter>

namespace Ui {
class SecDialog;
}

class SecDialog : public QDialog
{
    Q_OBJECT

    QString name;
public:
    explicit SecDialog(QWidget *parent = nullptr);
    ~SecDialog();

    void setName(QString n);

    virtual void paintEvent(QPaintEvent *event);
private slots:
    void on_pushButton_clicked();

private:
    Ui::SecDialog *ui;
};

#endif // SECDIALOG_H
