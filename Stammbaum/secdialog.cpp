#include "secdialog.h"
#include "ui_secdialog.h"

SecDialog::SecDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecDialog)
{
    ui->setupUi(this);

}

SecDialog::~SecDialog()
{
    delete ui;
}

void SecDialog::setName(QString n)
{
    name = n;
}

void SecDialog::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.drawRect(QRect(80, 120, 200, 180));
}

void SecDialog::on_pushButton_clicked()
{
    ui->lineEdit->setText(name);
}
