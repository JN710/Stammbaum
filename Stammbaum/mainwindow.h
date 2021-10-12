#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString name;

    //Datenbank
    QSqlQuery query;

private slots:

    void setName(QString n);
    QString getName();

    void datenbankConnect();
    void datenbankSynchronisieren();
    void datenbankInput(QString vn, QString nn, QString gn, QString gd, QString go, QString ge, QString be, QString bf, int k, QString g, QString v, QString m);
    void datenbankUpdate();
    void datenbankDelete();
    void datenbankgetOutput();

    void on_button_accept_clicked();
    void on_button_cancel_clicked();
    void on_pushButton_clicked();
    void on_button_veraendern_clicked();

    void on_radioButton_neu_clicked();
    void on_radioButton_bearbeiten_clicked();

    void clearLineEdit();
    void on_comboBox_bearbeiten_textActivated(const QString &arg1);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
