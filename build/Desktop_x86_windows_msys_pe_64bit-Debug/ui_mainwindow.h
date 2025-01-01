/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QTreeView *treeView;
    QPushButton *pushButton;
    QLabel *selected;
    QPushButton *Compress;
    QPushButton *Decompress;
    QLabel *notify;
    QLabel *size;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 750);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        MainWindow->setPalette(palette);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, -25, 1000, 750));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/images/background.png)"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 40, 521, 81));
        QPalette palette1;
        QBrush brush1(QColor(18, 34, 30, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        label_2->setPalette(palette1);
        QFont font;
        font.setFamilies({QString::fromUtf8("OCR A Extended")});
        font.setPointSize(48);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(110, 200, 311, 61));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        label_3->setPalette(palette2);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("OCR A Extended")});
        font1.setPointSize(28);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(570, 200, 311, 61));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        label_4->setPalette(palette3);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignCenter);
        treeView = new QTreeView(centralwidget);
        treeView->setObjectName("treeView");
        treeView->setGeometry(QRect(70, 270, 381, 311));
        treeView->setStyleSheet(QString::fromUtf8("border-radius: 25 px;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 600, 111, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("OCR A Extended")});
        font2.setPointSize(12);
        pushButton->setFont(font2);
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(39, 236, 188);\n"
"color: rgb(18, 34, 30);\n"
"border: 4px outset;\n"
"border-color: rgb(69, 155, 138);\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color: rgb(40, 245, 194);\n"
"border-color: rgb(76, 170, 151);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: rgb(33, 198, 157);\n"
"border-color: rgb(63, 141, 125);\n"
"}"));
        selected = new QLabel(centralwidget);
        selected->setObjectName("selected");
        selected->setGeometry(QRect(530, 290, 381, 20));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        selected->setPalette(palette4);
        selected->setFont(font2);
        selected->setAlignment(Qt::AlignCenter);
        Compress = new QPushButton(centralwidget);
        Compress->setObjectName("Compress");
        Compress->setGeometry(QRect(630, 370, 181, 51));
        Compress->setFont(font2);
        Compress->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(229, 227, 226);\n"
"color: rgb(18, 34, 30);\n"
"border: 4px outset;\n"
"border-color: rgb(155, 155, 155);\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color: rgb(238, 236, 235);\n"
"border-color: rgb(179, 179, 179);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: rgb(204, 202, 202);\n"
"border-color: rgb(126, 126, 126);\n"
"}"));
        Decompress = new QPushButton(centralwidget);
        Decompress->setObjectName("Decompress");
        Decompress->setGeometry(QRect(630, 450, 181, 51));
        Decompress->setFont(font2);
        Decompress->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"background-color: rgb(229, 227, 226);\n"
"color: rgb(18, 34, 30);\n"
"border: 4px outset;\n"
"border-color: rgb(155, 155, 155);\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton::hover{\n"
"background-color: rgb(238, 236, 235);\n"
"border-color: rgb(179, 179, 179);\n"
"}\n"
"QPushButton::pressed{\n"
"background-color: rgb(204, 202, 202);\n"
"border-color: rgb(126, 126, 126);\n"
"}"));
        notify = new QLabel(centralwidget);
        notify->setObjectName("notify");
        notify->setGeometry(QRect(540, 580, 371, 20));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        notify->setPalette(palette5);
        notify->setFont(font2);
        notify->setAlignment(Qt::AlignCenter);
        size = new QLabel(centralwidget);
        size->setObjectName("size");
        size->setGeometry(QRect(540, 620, 371, 20));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        size->setPalette(palette6);
        size->setFont(font2);
        size->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "File Zipper", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Choose File", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Choose Task", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Select", nullptr));
        selected->setText(QCoreApplication::translate("MainWindow", "No File Selected", nullptr));
        Compress->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        Decompress->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        notify->setText(QString());
        size->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
