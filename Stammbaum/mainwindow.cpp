#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctype.h>
#include "secdialog.h"

#include <QDebug>
#include <QtWidgets>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>

#include <QSql>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Datenbank-Funktionen
    datenbankConnect();
    datenbankSynchronisieren();
    //datenbankInput();

    ui->comboBox_bearbeiten->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setName(QString n)
{
    name = n;
}

QString MainWindow::getName()
{
    return name;
}

/////////////////////// Datenbank ////////////////////////////////////
void MainWindow::datenbankConnect()
{
    QString dbName("stammbaumdatenbank.db3");
    QFile::remove(dbName);
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);
    if(!db.open())
        qWarning() << "ERROR beim oeffnen der Datenbank: " << db.lastError();

    // Tabelle erstellen
    query = QSqlQuery(db);
    if(!query.exec("CREATE TABLE vorfahren (id INTEGER PRIMARY KEY, vorname TEXT, nachname TEXT, geburtsname TEXT, geburtsdatum DATE, geburtsort TEXT, gestorben DATE, begraben TEXT, beruf TEXT, kinder INTEGER, geschlecht TEXT, vater TEXT, mutter TEXT)")){
        qWarning() << "ERROR query beim erstellen: " << query.lastError().text();
    }
}

void MainWindow::datenbankInput(QString vn, QString nn, QString gn, QString gd, QString go, QString ge, QString be, QString bf, int k, QString g, QString v, QString m)
{
    // Daten in die Tabelle eingeben (aktuell noch feste Werte)
    query.prepare("INSERT INTO vorfahren (vorname, nachname, geburtsname, geburtsdatum, geburtsort, gestorben, begraben, beruf, kinder, geschlecht, vater, mutter) VALUES(:vorname, :nachname, :geburtsname, :geburtsdatum, :geburtsort, :gestorben, :begraben, :beruf, :kinder, :geschlecht, :vater, :mutter)");
    query.bindValue(":vorname", vn);
    query.bindValue(":nachname", nn);
    query.bindValue(":geburtsname", gn);
    query.bindValue(":geburtsdatum", gd);
    query.bindValue(":geburtsort", go);
    query.bindValue(":gestorben", ge);
    query.bindValue(":begraben", be);
    query.bindValue(":beruf", bf);
    query.bindValue(":kinder", k);
    query.bindValue(":geschlecht", g);
    query.bindValue(":vater", v);
    query.bindValue(":mutter", m);
    if(!query.exec()){
        qWarning() << "ERROR query beim einfuegen: " << query.lastError().text();
    }
}

void MainWindow::datenbankSynchronisieren()
{
    // Kommando vorbereiten und ausführen
    query.prepare("SELECT * FROM vorfahren");
    query.exec();

    // Index vom query abfragen
    int idVorname = query.record().indexOf("vorname");
    int idNachname = query.record().indexOf("nachname");
    int idGeburtsname = query.record().indexOf("geburtsname");

    // Leeren der gesamten ComboBox
    ui->comboBox_bearbeiten->clear();

    while(query.next())
    {
        ui->comboBox_bearbeiten->addItem(query.value(idVorname).toString() + " " + query.value(idNachname).toString() + query.value(idGeburtsname).toString());
    }
}

void MainWindow::datenbankUpdate()
{
    // Text aktueller Dropdown herauslesen und filtern
    QString vname, nname, gname, vn, nn, gn, gebOrt, begraben, beruf, geschlecht;
    int anzKinder;
    QString text = ui->comboBox_bearbeiten->currentText();
    QString t = ui->lineEdit_1_name->text();
    int c = 0, d = 0;

    // Name trennen und überprüfen aktuelle ComboBox
    gname = " ";
    for(int i=0; i<text.count(); i++){
        if (!(text[i] == ' ') && c == 0){
            vname[d] = text[i];
            d++;
        }
        else if (!(text[i] == ' ') && c == 1){
            nname[d] = text[i];
            d++;
        }
        else if (!(text[i] == ' ') && c == 2){
            gname[d] = text[i];
            d++;
        }
        else {
            c++;
            d = 0;
        }
    }

    // Name trennen und überprüfen aktuelle Textfelder
    gn = " ";
    c = 0;
    d = 0;
    for(int i=0; i<t.count(); i++){
        if (!(t[i] == ' ') && c == 0){
            vn[d] = t[i];
            d++;
        }
        else if (!(t[i] == ' ') && c == 1){
            nn[d] = t[i];
            d++;
        }
        else if (!(t[i] == ' ') && c == 2){
            gn[d] = t[i];
            d++;
        }
        else {
            c++;
            d = 0;
        }
    }
    gebOrt = ui->lineEdit_3_ort->text();
    begraben = ui->lineEdit_5_begraben->text();
    beruf = ui->lineEdit_6_beruf->text();
    anzKinder = ui->lineEdit_7_kinder->text().toInt();

    if(ui->radioButton_maennlich->isChecked())
        geschlecht = "m";
    else
        geschlecht = "w";

    //Eltern
    QString vater, mutter;
    vater = ui->comboBox_vater->currentText();
    mutter = ui->comboBox_mutter->currentText();
    qDebug() << vater;
    qDebug() << mutter;
    // Aktualiseren des Datensatzes
    query.exec("UPDATE vorfahren SET vorname = '" + vn + "', nachname = '" + nn + "', geburtsname = '" + gn + "', geburtsort = '" + gebOrt + "', begraben = '" + begraben + "', beruf = '" + beruf + "', kinder = 7, geschlecht = '" + geschlecht + "',  vater = '" + vater + "', mutter = '" + mutter + "' WHERE vorname = '" + vname + "' AND nachname = '" + nname + "'");


    //Aktualisieren des Dropdown-Menüs
    datenbankSynchronisieren();
}

void MainWindow::datenbankDelete()
{
    query.exec("DELETE FROM vorfahren WHERE id = 2");
}

void MainWindow::datenbankgetOutput()
{
    // Text aktueller Dropdown herauslesen und filtern
    QString vname, nname, gname;
    QString text = ui->comboBox_bearbeiten->currentText();
    int c = 0, d = 0;

    // Name trennen und überprüfen
    gname = " ";
    for(int i=0; i<text.count(); i++){
        if (!(text[i] == ' ') && c == 0){
            vname[d] = text[i];
            d++;
        }
        else if (!(text[i] == ' ') && c == 1){
            nname[d] = text[i];
            d++;
        }
        else if (!(text[i] == ' ') && c == 2){
            gname[d] = text[i];
            d++;
        }
        else {
            c++;
            d = 0;
        }
    }

    // Kommando vorbereiten und ausführen
    query.prepare("SELECT * FROM vorfahren WHERE vorname = '" + vname + "' AND nachname = '" +nname + "'");
    query.exec();

    // Index vom query abfragen
    int idVorname = query.record().indexOf("vorname");
    int idNachname = query.record().indexOf("nachname");
    int idGeburtsname = query.record().indexOf("geburtsname");
    int idGeburtsdatum = query.record().indexOf("geburtsdatum");
    int idGeburtsort = query.record().indexOf("geburtsort");
    int idGestorben = query.record().indexOf("gestorben");
    int idBegraben = query.record().indexOf("begraben");
    int idBeruf = query.record().indexOf("beruf");
    int idKinder = query.record().indexOf("kinder");
    int idVater = query.record().indexOf("vater");
    int idMutter = query.record().indexOf("mutter");

    // query-Index erhöhen
    query.next();

    // Zuordnen und Ausgabe
    ui->lineEdit_1_name->setText("" + query.value(idVorname).toString() + " " + query.value(idNachname).toString() + query.value(idGeburtsname).toString());
    ui->dateEdit_2_geb->setDate(query.value(idGeburtsdatum).toDate());
    ui->lineEdit_3_ort->setText(query.value(idGeburtsort).toString());
    ui->dateEdit_4_gestorben->setDate(query.value(idGestorben).toDate());
    ui->lineEdit_5_begraben->setText(query.value(idBegraben).toString());
    ui->lineEdit_6_beruf->setText(query.value(idBeruf).toString());
    ui->lineEdit_7_kinder->setText(query.value(idKinder).toString());
    ui->comboBox_vater->setCurrentText(query.value(idVater).toString());
    ui->comboBox_mutter->setCurrentText(query.value(idMutter).toString());

}
/////////////////////// Buttons //////////////////////////////////////
void MainWindow::on_button_accept_clicked()
{
    qDebug() << ui->radioButton_neu->isChecked();

    // Radiobutton neuer Benutzer
    if (ui->radioButton_neu->isChecked()) {

        // Combobox zum bearbeiten deaktivieren
        ui->comboBox_bearbeiten->setDisabled(true);

        // Variablen
        bool eingabenKorrekt = true;
        int c = 0, d = 0;   // für Überprüfung der Namen
        QString vorname, nachname, geburtsname, text, geburtsdatum, gestorben, geschlecht;

        // Datum überprüfen
        geburtsdatum = ui->dateEdit_2_geb->text();
        gestorben = ui->dateEdit_4_gestorben->text();
        //ui->dateEdit_2_geb->setReadOnly(true);
        //ui->dateEdit_4_gestorben->setReadOnly(true);

        // Name trennen und überprüfen
        text = ui->lineEdit_1_name->text();
        geburtsname = " ";
        for(int i=0; i<text.count(); i++){
            if (!(text[i] == ' ') && c == 0){
                vorname[d] = text[i];
                d++;
            }
            else if (!(text[i] == ' ') && c == 1){
                nachname[d] = text[i];
                d++;
            }
            else if (!(text[i] == ' ') && c == 2){
                geburtsname[d] = text[i];
                d++;
            }
            else {
                c++;
                d = 0;
            }
        }
        //ui->lineEdit_1_name->setReadOnly(true);
        setName(ui->lineEdit_1_name->text());

        // Geburtsort überprüfen
        QString geburtsort = ui->lineEdit_3_ort->text();
        for (int i=0; i<geburtsort.count(); i++)
        {
            if((geburtsort[i] >= 'A' && geburtsort[i] <= 'Z') || (geburtsort[i] >= 'a' && geburtsort[i] <= 'z'))
            {
                //ui->lineEdit_3_ort->setReadOnly(true);
            }
            else
            {
                ui->lineEdit_3_ort->setReadOnly(false);
                ui->lineEdit_3_ort->setText("Keine Zahlen oder Sonderzeichen!");
                eingabenKorrekt = false;
                break;
            }
        }

        // Begraben überprüfen
        QString begraben = ui->lineEdit_5_begraben->text();
        for (int i=0; i<begraben.count(); i++)
        {
            if((begraben[i] >= 'A' && begraben[i] <= 'Z') || (begraben[i] >= 'a' && begraben[i] <= 'z'))
            {
                //ui->lineEdit_5_begraben->setReadOnly(true);
            }
            else
            {
                ui->lineEdit_5_begraben->setReadOnly(false);
                ui->lineEdit_5_begraben->setText("Keine Zahlen oder Sonderzeichen!");
                eingabenKorrekt = false;
                break;
            }
        }

        // Beruf übeprüfen
        QString beruf = ui->lineEdit_6_beruf->text();
        for (int i=0; i<beruf.count(); i++)
        {
            if((beruf[i] >= 'A' && beruf[i] <= 'Z') || (beruf[i] >= 'a' && beruf[i] <= 'z'))
            {
                //ui->lineEdit_6_beruf->setReadOnly(true);
            }
            else
            {
                ui->lineEdit_6_beruf->setReadOnly(false);
                ui->lineEdit_6_beruf->setText("Keine Zahlen oder Sonderzeichen!");
                eingabenKorrekt = false;
                break;
            }
        }

        // Anzahl Kinder überprüfen
        QString anzKinder = ui->lineEdit_7_kinder->text();
        for(int i=0; i<anzKinder.count(); i++)
        {
            if(anzKinder[i] >= '0' && anzKinder[i] <= '9')
            {
                //ui->lineEdit_7_kinder->setReadOnly(true);
            }
            else
            {
                ui->lineEdit_7_kinder->setReadOnly(false);
                ui->lineEdit_7_kinder->setText("Dieses Feld darf nur Zahlen enthalten!");
                eingabenKorrekt = false;
                break;
            }
        }

        // Geschlecht
        if(ui->radioButton_maennlich->isChecked()) {
            geschlecht = "m";
        }
        else {
            geschlecht = "w";
        }

        // Vater und Mutter überprüfen
        QString vater = ui->comboBox_vater->currentText();
        QString mutter = ui->comboBox_mutter->currentText();

        if(eingabenKorrekt){
            datenbankInput(vorname, nachname, geburtsname, geburtsdatum, geburtsort, gestorben, begraben, beruf, anzKinder.toInt(), geschlecht, vater, mutter);
            ui->comboBox_bearbeiten->addItem(vorname + " " + nachname + " " + geburtsname);

            if(ui->radioButton_maennlich->isChecked()) {
                ui->comboBox_vater->addItem(ui->lineEdit_1_name->text());
            }
            else {
                ui->comboBox_mutter->addItem(ui->lineEdit_1_name->text());
            }
            clearLineEdit();
        }
    }

    // Radiobutton bearbeiten
    if(ui->radioButton_bearbeiten->isChecked()){

        datenbankUpdate();

        qDebug() << "Radiobutton bearbeiten";
    }
}

void MainWindow::on_button_cancel_clicked()
{
    //datenbankUpdate();
}

void MainWindow::on_pushButton_clicked()
{
    SecDialog secDialog;
    secDialog.setModal(true);
    secDialog.exec();
}

void MainWindow::on_radioButton_neu_clicked()
{
    ui->comboBox_bearbeiten->setDisabled(true);

    // LineEdits und DateEdits leeren
    clearLineEdit();

    ui->button_accept->setText("Bestätigen");
}

void MainWindow::on_radioButton_bearbeiten_clicked()
{
    ui->comboBox_bearbeiten->setDisabled(false);

    // LineEdits und DateEdits leeren
    clearLineEdit();

    ui->button_accept->setText("Daten abrufen");
}

void MainWindow::clearLineEdit()
{
    ui->lineEdit_1_name->clear();
    //ui->dateEdit_2_geb->clear();    //funktioniert noch nicht
    ui->lineEdit_3_ort->clear();
    //ui->dateEdit_4_gestorben->clear();  //funktioniert noch nicht
    ui->lineEdit_5_begraben->clear();
    ui->lineEdit_6_beruf->clear();
    ui->lineEdit_7_kinder->clear();
}

//Dropdown-Menü beim auswählen
void MainWindow::on_comboBox_bearbeiten_textActivated(const QString &arg1)
{
    // Datensätze aus der Datenbank auslesen und in Textbox ausgeben
    datenbankgetOutput();

    // Buttontext ändern
    ui->button_accept->setText("Eingaben speichern");
}
