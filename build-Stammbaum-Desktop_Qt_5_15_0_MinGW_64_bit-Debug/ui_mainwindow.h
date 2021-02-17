/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QGroupBox *groupBox_mitglied;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QLabel *label_5_begraben;
    QLabel *label_7_kinder;
    QLabel *label_3_ort;
    QRadioButton *radioButton_maennlich;
    QLabel *label_2_geb;
    QDateEdit *dateEdit_2_geb;
    QLabel *label_1_name;
    QLineEdit *lineEdit_7_kinder;
    QLabel *label_6_beruf;
    QLineEdit *lineEdit_1_name;
    QLineEdit *lineEdit_6_beruf;
    QLineEdit *lineEdit_3_ort;
    QLabel *label_8_geschlecht;
    QLineEdit *lineEdit_5_begraben;
    QDateEdit *dateEdit_4_gestorben;
    QLabel *label_4_gestorben;
    QRadioButton *radioButton_weiblich;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioButton_neu;
    QRadioButton *radioButton_bearbeiten;
    QComboBox *comboBox_bearbeiten;
    QPushButton *pushButton;
    QGroupBox *groupBox_vorfahren;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QComboBox *comboBox_vater;
    QComboBox *comboBox_mutter;
    QLabel *label_mutter;
    QLabel *label_vater;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *button_accept;
    QPushButton *button_cancel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(781, 638);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 0, 151, 51));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        groupBox_mitglied = new QGroupBox(centralwidget);
        groupBox_mitglied->setObjectName(QString::fromUtf8("groupBox_mitglied"));
        groupBox_mitglied->setGeometry(QRect(170, 60, 541, 311));
        gridLayoutWidget = new QWidget(groupBox_mitglied);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 60, 479, 243));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5_begraben = new QLabel(gridLayoutWidget);
        label_5_begraben->setObjectName(QString::fromUtf8("label_5_begraben"));
        label_5_begraben->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_5_begraben, 4, 0, 1, 1);

        label_7_kinder = new QLabel(gridLayoutWidget);
        label_7_kinder->setObjectName(QString::fromUtf8("label_7_kinder"));
        label_7_kinder->setLayoutDirection(Qt::LeftToRight);
        label_7_kinder->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_7_kinder, 6, 0, 1, 1);

        label_3_ort = new QLabel(gridLayoutWidget);
        label_3_ort->setObjectName(QString::fromUtf8("label_3_ort"));
        label_3_ort->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_3_ort, 2, 0, 1, 1);

        radioButton_maennlich = new QRadioButton(gridLayoutWidget);
        radioButton_maennlich->setObjectName(QString::fromUtf8("radioButton_maennlich"));
        radioButton_maennlich->setChecked(true);

        gridLayout_2->addWidget(radioButton_maennlich, 7, 1, 1, 1);

        label_2_geb = new QLabel(gridLayoutWidget);
        label_2_geb->setObjectName(QString::fromUtf8("label_2_geb"));
        label_2_geb->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2_geb, 1, 0, 1, 1);

        dateEdit_2_geb = new QDateEdit(gridLayoutWidget);
        dateEdit_2_geb->setObjectName(QString::fromUtf8("dateEdit_2_geb"));

        gridLayout_2->addWidget(dateEdit_2_geb, 1, 1, 1, 1);

        label_1_name = new QLabel(gridLayoutWidget);
        label_1_name->setObjectName(QString::fromUtf8("label_1_name"));
        label_1_name->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_1_name, 0, 0, 1, 1);

        lineEdit_7_kinder = new QLineEdit(gridLayoutWidget);
        lineEdit_7_kinder->setObjectName(QString::fromUtf8("lineEdit_7_kinder"));
        lineEdit_7_kinder->setEnabled(true);
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        lineEdit_7_kinder->setFont(font1);

        gridLayout_2->addWidget(lineEdit_7_kinder, 6, 1, 1, 1);

        label_6_beruf = new QLabel(gridLayoutWidget);
        label_6_beruf->setObjectName(QString::fromUtf8("label_6_beruf"));
        label_6_beruf->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_6_beruf, 5, 0, 1, 1);

        lineEdit_1_name = new QLineEdit(gridLayoutWidget);
        lineEdit_1_name->setObjectName(QString::fromUtf8("lineEdit_1_name"));

        gridLayout_2->addWidget(lineEdit_1_name, 0, 1, 1, 1);

        lineEdit_6_beruf = new QLineEdit(gridLayoutWidget);
        lineEdit_6_beruf->setObjectName(QString::fromUtf8("lineEdit_6_beruf"));

        gridLayout_2->addWidget(lineEdit_6_beruf, 5, 1, 1, 1);

        lineEdit_3_ort = new QLineEdit(gridLayoutWidget);
        lineEdit_3_ort->setObjectName(QString::fromUtf8("lineEdit_3_ort"));

        gridLayout_2->addWidget(lineEdit_3_ort, 2, 1, 1, 1);

        label_8_geschlecht = new QLabel(gridLayoutWidget);
        label_8_geschlecht->setObjectName(QString::fromUtf8("label_8_geschlecht"));
        label_8_geschlecht->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_8_geschlecht, 7, 0, 1, 1);

        lineEdit_5_begraben = new QLineEdit(gridLayoutWidget);
        lineEdit_5_begraben->setObjectName(QString::fromUtf8("lineEdit_5_begraben"));

        gridLayout_2->addWidget(lineEdit_5_begraben, 4, 1, 1, 1);

        dateEdit_4_gestorben = new QDateEdit(gridLayoutWidget);
        dateEdit_4_gestorben->setObjectName(QString::fromUtf8("dateEdit_4_gestorben"));

        gridLayout_2->addWidget(dateEdit_4_gestorben, 3, 1, 1, 1);

        label_4_gestorben = new QLabel(gridLayoutWidget);
        label_4_gestorben->setObjectName(QString::fromUtf8("label_4_gestorben"));
        label_4_gestorben->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_4_gestorben, 3, 0, 1, 1);

        radioButton_weiblich = new QRadioButton(gridLayoutWidget);
        radioButton_weiblich->setObjectName(QString::fromUtf8("radioButton_weiblich"));

        gridLayout_2->addWidget(radioButton_weiblich, 8, 1, 1, 1);

        horizontalLayoutWidget_2 = new QWidget(groupBox_mitglied);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(30, 20, 481, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_neu = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_neu->setObjectName(QString::fromUtf8("radioButton_neu"));
        radioButton_neu->setEnabled(true);
        radioButton_neu->setAcceptDrops(false);
        radioButton_neu->setChecked(true);

        horizontalLayout_2->addWidget(radioButton_neu);

        radioButton_bearbeiten = new QRadioButton(horizontalLayoutWidget_2);
        radioButton_bearbeiten->setObjectName(QString::fromUtf8("radioButton_bearbeiten"));

        horizontalLayout_2->addWidget(radioButton_bearbeiten);

        comboBox_bearbeiten = new QComboBox(horizontalLayoutWidget_2);
        comboBox_bearbeiten->setObjectName(QString::fromUtf8("comboBox_bearbeiten"));

        horizontalLayout_2->addWidget(comboBox_bearbeiten);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 500, 75, 23));
        groupBox_vorfahren = new QGroupBox(centralwidget);
        groupBox_vorfahren->setObjectName(QString::fromUtf8("groupBox_vorfahren"));
        groupBox_vorfahren->setGeometry(QRect(170, 390, 471, 171));
        gridLayoutWidget_2 = new QWidget(groupBox_vorfahren);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(30, 50, 251, 81));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_vater = new QComboBox(gridLayoutWidget_2);
        comboBox_vater->addItem(QString());
        comboBox_vater->setObjectName(QString::fromUtf8("comboBox_vater"));
        comboBox_vater->setEditable(false);

        gridLayout->addWidget(comboBox_vater, 0, 1, 1, 1);

        comboBox_mutter = new QComboBox(gridLayoutWidget_2);
        comboBox_mutter->addItem(QString());
        comboBox_mutter->setObjectName(QString::fromUtf8("comboBox_mutter"));

        gridLayout->addWidget(comboBox_mutter, 1, 1, 1, 1);

        label_mutter = new QLabel(gridLayoutWidget_2);
        label_mutter->setObjectName(QString::fromUtf8("label_mutter"));
        label_mutter->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_mutter, 1, 0, 1, 1);

        label_vater = new QLabel(gridLayoutWidget_2);
        label_vater->setObjectName(QString::fromUtf8("label_vater"));
        label_vater->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_vater, 0, 0, 1, 1);

        horizontalLayoutWidget = new QWidget(groupBox_vorfahren);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(210, 140, 239, 25));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        button_accept = new QPushButton(horizontalLayoutWidget);
        button_accept->setObjectName(QString::fromUtf8("button_accept"));

        horizontalLayout->addWidget(button_accept);

        button_cancel = new QPushButton(horizontalLayoutWidget);
        button_cancel->setObjectName(QString::fromUtf8("button_cancel"));

        horizontalLayout->addWidget(button_cancel);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 781, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        QWidget::setTabOrder(lineEdit_1_name, dateEdit_2_geb);
        QWidget::setTabOrder(dateEdit_2_geb, lineEdit_3_ort);
        QWidget::setTabOrder(lineEdit_3_ort, dateEdit_4_gestorben);
        QWidget::setTabOrder(dateEdit_4_gestorben, lineEdit_5_begraben);
        QWidget::setTabOrder(lineEdit_5_begraben, lineEdit_6_beruf);
        QWidget::setTabOrder(lineEdit_6_beruf, lineEdit_7_kinder);
        QWidget::setTabOrder(lineEdit_7_kinder, comboBox_vater);
        QWidget::setTabOrder(comboBox_vater, comboBox_mutter);
        QWidget::setTabOrder(comboBox_mutter, button_accept);
        QWidget::setTabOrder(button_accept, button_cancel);
        QWidget::setTabOrder(button_cancel, pushButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Stammbaum", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Stammbaum", nullptr));
        groupBox_mitglied->setTitle(QCoreApplication::translate("MainWindow", "neuer Vorfahre", nullptr));
        label_5_begraben->setText(QCoreApplication::translate("MainWindow", "begraben", nullptr));
        label_7_kinder->setText(QCoreApplication::translate("MainWindow", "Anzahl Kinder", nullptr));
        label_3_ort->setText(QCoreApplication::translate("MainWindow", "Geburtsort", nullptr));
        radioButton_maennlich->setText(QCoreApplication::translate("MainWindow", "m\303\244nnlich", nullptr));
        label_2_geb->setText(QCoreApplication::translate("MainWindow", "Geburtsdatum", nullptr));
        label_1_name->setText(QCoreApplication::translate("MainWindow", "Vorname, Nachname, (geborene(r))", nullptr));
        label_6_beruf->setText(QCoreApplication::translate("MainWindow", "Beruf", nullptr));
        label_8_geschlecht->setText(QCoreApplication::translate("MainWindow", "Geschlecht", nullptr));
        label_4_gestorben->setText(QCoreApplication::translate("MainWindow", "gestorben", nullptr));
        radioButton_weiblich->setText(QCoreApplication::translate("MainWindow", "weiblich", nullptr));
        radioButton_neu->setText(QCoreApplication::translate("MainWindow", "neuer Vorfahre", nullptr));
        radioButton_bearbeiten->setText(QCoreApplication::translate("MainWindow", "Vorfahre bearbeiten", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        groupBox_vorfahren->setTitle(QCoreApplication::translate("MainWindow", "Eltern", nullptr));
        comboBox_vater->setItemText(0, QCoreApplication::translate("MainWindow", "None (M)", nullptr));

        comboBox_vater->setCurrentText(QCoreApplication::translate("MainWindow", "None (M)", nullptr));
        comboBox_mutter->setItemText(0, QCoreApplication::translate("MainWindow", "None (F)", nullptr));

        label_mutter->setText(QCoreApplication::translate("MainWindow", "Mutter", nullptr));
        label_vater->setText(QCoreApplication::translate("MainWindow", "Vater", nullptr));
        button_accept->setText(QCoreApplication::translate("MainWindow", "Best\303\244tigen", nullptr));
        button_cancel->setText(QCoreApplication::translate("MainWindow", "Abbrechen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
