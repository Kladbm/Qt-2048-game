/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *newGame_btn;
    QLabel *B13;
    QLabel *B14;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_6;
    QLabel *B31;
    QLabel *B33;
    QLabel *B32;
    QLabel *B34;
    QLabel *B44;
    QLabel *B43;
    QLabel *B41;
    QLabel *B42;
    QLabel *B21;
    QLabel *B24;
    QLabel *B23;
    QLabel *B22;
    QLabel *B11;
    QLabel *B12;
    QLabel *Score_lbl;
    QFrame *frame;
    QLabel *status_label;
    QPushButton *try_again_btn;
    QLabel *Max_Score_lbl;
    QPushButton *change_theme_button;
    QLabel *B22_2;
    QLabel *B13_2;
    QLabel *B34_2;
    QLabel *B11_2;
    QLabel *B31_2;
    QLabel *B41_2;
    QLabel *B32_2;
    QLabel *B14_2;
    QLabel *B42_2;
    QLabel *B43_2;
    QLabel *B12_2;
    QLabel *B33_2;
    QLabel *B21_2;
    QLabel *B23_2;
    QLabel *B24_2;
    QLabel *B44_2;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(467, 540);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(467, 540));
        MainWindow->setMaximumSize(QSize(467, 540));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(187, 173, 160);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        newGame_btn = new QPushButton(centralwidget);
        newGame_btn->setObjectName(QString::fromUtf8("newGame_btn"));
        newGame_btn->setGeometry(QRect(15, 25, 121, 36));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        newGame_btn->setFont(font);
        newGame_btn->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(143, 122, 102);"));
        B13 = new QLabel(centralwidget);
        B13->setObjectName(QString::fromUtf8("B13"));
        B13->setEnabled(true);
        B13->setGeometry(QRect(241, 77, 98, 98));
        B13->setMaximumSize(QSize(110, 110));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(40);
        B13->setFont(font1);
        B13->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B13->setAlignment(Qt::AlignCenter);
        B13->setMargin(20);
        B14 = new QLabel(centralwidget);
        B14->setObjectName(QString::fromUtf8("B14"));
        B14->setEnabled(true);
        B14->setGeometry(QRect(354, 77, 98, 98));
        B14->setMaximumSize(QSize(110, 110));
        B14->setFont(font1);
        B14->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B14->setAlignment(Qt::AlignCenter);
        B14->setMargin(20);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 134, 26));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        B31 = new QLabel(centralwidget);
        B31->setObjectName(QString::fromUtf8("B31"));
        B31->setGeometry(QRect(15, 303, 98, 98));
        B31->setMaximumSize(QSize(110, 110));
        B31->setFont(font1);
        B31->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B31->setAlignment(Qt::AlignCenter);
        B31->setMargin(20);
        B33 = new QLabel(centralwidget);
        B33->setObjectName(QString::fromUtf8("B33"));
        B33->setGeometry(QRect(241, 303, 98, 98));
        B33->setMaximumSize(QSize(110, 110));
        B33->setFont(font1);
        B33->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B33->setAlignment(Qt::AlignCenter);
        B33->setMargin(20);
        B32 = new QLabel(centralwidget);
        B32->setObjectName(QString::fromUtf8("B32"));
        B32->setGeometry(QRect(128, 303, 98, 98));
        B32->setMaximumSize(QSize(110, 110));
        B32->setFont(font1);
        B32->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B32->setAlignment(Qt::AlignCenter);
        B32->setMargin(20);
        B34 = new QLabel(centralwidget);
        B34->setObjectName(QString::fromUtf8("B34"));
        B34->setGeometry(QRect(354, 303, 98, 98));
        B34->setMaximumSize(QSize(110, 110));
        B34->setFont(font1);
        B34->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B34->setAlignment(Qt::AlignCenter);
        B34->setMargin(20);
        B44 = new QLabel(centralwidget);
        B44->setObjectName(QString::fromUtf8("B44"));
        B44->setGeometry(QRect(354, 416, 98, 98));
        B44->setMaximumSize(QSize(110, 110));
        B44->setFont(font1);
        B44->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B44->setAlignment(Qt::AlignCenter);
        B44->setMargin(20);
        B43 = new QLabel(centralwidget);
        B43->setObjectName(QString::fromUtf8("B43"));
        B43->setGeometry(QRect(241, 416, 98, 98));
        B43->setMaximumSize(QSize(110, 110));
        B43->setFont(font1);
        B43->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B43->setAlignment(Qt::AlignCenter);
        B43->setMargin(20);
        B41 = new QLabel(centralwidget);
        B41->setObjectName(QString::fromUtf8("B41"));
        B41->setGeometry(QRect(15, 416, 98, 98));
        B41->setMaximumSize(QSize(110, 110));
        B41->setFont(font1);
        B41->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B41->setAlignment(Qt::AlignCenter);
        B41->setMargin(20);
        B42 = new QLabel(centralwidget);
        B42->setObjectName(QString::fromUtf8("B42"));
        B42->setGeometry(QRect(128, 416, 98, 98));
        B42->setMaximumSize(QSize(110, 110));
        B42->setFont(font1);
        B42->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B42->setAlignment(Qt::AlignCenter);
        B42->setMargin(20);
        B21 = new QLabel(centralwidget);
        B21->setObjectName(QString::fromUtf8("B21"));
        B21->setGeometry(QRect(15, 190, 98, 98));
        B21->setMaximumSize(QSize(110, 110));
        B21->setFont(font1);
        B21->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B21->setAlignment(Qt::AlignCenter);
        B21->setMargin(20);
        B24 = new QLabel(centralwidget);
        B24->setObjectName(QString::fromUtf8("B24"));
        B24->setGeometry(QRect(354, 190, 98, 98));
        B24->setMaximumSize(QSize(110, 110));
        B24->setFont(font1);
        B24->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B24->setAlignment(Qt::AlignCenter);
        B24->setMargin(20);
        B23 = new QLabel(centralwidget);
        B23->setObjectName(QString::fromUtf8("B23"));
        B23->setGeometry(QRect(241, 190, 98, 98));
        B23->setMaximumSize(QSize(110, 110));
        B23->setFont(font1);
        B23->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B23->setAlignment(Qt::AlignCenter);
        B23->setMargin(20);
        B22 = new QLabel(centralwidget);
        B22->setObjectName(QString::fromUtf8("B22"));
        B22->setGeometry(QRect(128, 190, 98, 98));
        B22->setMaximumSize(QSize(110, 110));
        B22->setFont(font1);
        B22->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B22->setAlignment(Qt::AlignCenter);
        B22->setMargin(20);
        B11 = new QLabel(centralwidget);
        B11->setObjectName(QString::fromUtf8("B11"));
        B11->setEnabled(true);
        B11->setGeometry(QRect(15, 77, 98, 98));
        B11->setMaximumSize(QSize(110, 110));
        B11->setFont(font1);
        B11->setAutoFillBackground(false);
        B11->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B11->setAlignment(Qt::AlignCenter);
        B11->setMargin(20);
        B12 = new QLabel(centralwidget);
        B12->setObjectName(QString::fromUtf8("B12"));
        B12->setEnabled(true);
        B12->setGeometry(QRect(128, 77, 98, 98));
        B12->setMaximumSize(QSize(110, 110));
        B12->setFont(font1);
        B12->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B12->setAlignment(Qt::AlignCenter);
        B12->setMargin(20);
        Score_lbl = new QLabel(centralwidget);
        Score_lbl->setObjectName(QString::fromUtf8("Score_lbl"));
        Score_lbl->setGeometry(QRect(170, 40, 171, 24));
        QFont font2;
        font2.setPointSize(15);
        Score_lbl->setFont(font2);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-4, -16, 471, 551));
        frame->setStyleSheet(QString::fromUtf8("background: rgba(238,228,218,.5);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        status_label = new QLabel(frame);
        status_label->setObjectName(QString::fromUtf8("status_label"));
        status_label->setGeometry(QRect(20, 140, 431, 101));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Freestyle Script")});
        font3.setPointSize(55);
        font3.setBold(true);
        status_label->setFont(font3);
        status_label->setAutoFillBackground(false);
        status_label->setStyleSheet(QString::fromUtf8("color : #776E65;\n"
"background-color: transparent;"));
        status_label->setAlignment(Qt::AlignCenter);
        try_again_btn = new QPushButton(frame);
        try_again_btn->setObjectName(QString::fromUtf8("try_again_btn"));
        try_again_btn->setGeometry(QRect(160, 230, 141, 31));
        try_again_btn->setFont(font);
        try_again_btn->setStyleSheet(QString::fromUtf8("background-color:#8F7A66;\n"
"color: #f9f6f2;"));
        Max_Score_lbl = new QLabel(centralwidget);
        Max_Score_lbl->setObjectName(QString::fromUtf8("Max_Score_lbl"));
        Max_Score_lbl->setGeometry(QRect(170, 10, 171, 24));
        Max_Score_lbl->setFont(font2);
        change_theme_button = new QPushButton(centralwidget);
        change_theme_button->setObjectName(QString::fromUtf8("change_theme_button"));
        change_theme_button->setGeometry(QRect(370, 10, 48, 48));
        change_theme_button->setStyleSheet(QString::fromUtf8("background-image: url(:/2048/image/dark_theme.png)"));
        B22_2 = new QLabel(centralwidget);
        B22_2->setObjectName(QString::fromUtf8("B22_2"));
        B22_2->setGeometry(QRect(128, 190, 98, 98));
        B22_2->setMaximumSize(QSize(110, 110));
        B22_2->setFont(font1);
        B22_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B22_2->setAlignment(Qt::AlignCenter);
        B22_2->setMargin(20);
        B13_2 = new QLabel(centralwidget);
        B13_2->setObjectName(QString::fromUtf8("B13_2"));
        B13_2->setEnabled(true);
        B13_2->setGeometry(QRect(241, 77, 98, 98));
        B13_2->setMaximumSize(QSize(110, 110));
        B13_2->setFont(font1);
        B13_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B13_2->setAlignment(Qt::AlignCenter);
        B13_2->setMargin(20);
        B34_2 = new QLabel(centralwidget);
        B34_2->setObjectName(QString::fromUtf8("B34_2"));
        B34_2->setGeometry(QRect(354, 303, 98, 98));
        B34_2->setMaximumSize(QSize(110, 110));
        B34_2->setFont(font1);
        B34_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B34_2->setAlignment(Qt::AlignCenter);
        B34_2->setMargin(20);
        B11_2 = new QLabel(centralwidget);
        B11_2->setObjectName(QString::fromUtf8("B11_2"));
        B11_2->setEnabled(true);
        B11_2->setGeometry(QRect(15, 77, 98, 98));
        B11_2->setMaximumSize(QSize(110, 110));
        B11_2->setFont(font1);
        B11_2->setAutoFillBackground(false);
        B11_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B11_2->setAlignment(Qt::AlignCenter);
        B11_2->setMargin(20);
        B31_2 = new QLabel(centralwidget);
        B31_2->setObjectName(QString::fromUtf8("B31_2"));
        B31_2->setGeometry(QRect(15, 303, 98, 98));
        B31_2->setMaximumSize(QSize(110, 110));
        B31_2->setFont(font1);
        B31_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B31_2->setAlignment(Qt::AlignCenter);
        B31_2->setMargin(20);
        B41_2 = new QLabel(centralwidget);
        B41_2->setObjectName(QString::fromUtf8("B41_2"));
        B41_2->setGeometry(QRect(15, 416, 98, 98));
        B41_2->setMaximumSize(QSize(110, 110));
        B41_2->setFont(font1);
        B41_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B41_2->setAlignment(Qt::AlignCenter);
        B41_2->setMargin(20);
        B32_2 = new QLabel(centralwidget);
        B32_2->setObjectName(QString::fromUtf8("B32_2"));
        B32_2->setGeometry(QRect(128, 303, 98, 98));
        B32_2->setMaximumSize(QSize(110, 110));
        B32_2->setFont(font1);
        B32_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B32_2->setAlignment(Qt::AlignCenter);
        B32_2->setMargin(20);
        B14_2 = new QLabel(centralwidget);
        B14_2->setObjectName(QString::fromUtf8("B14_2"));
        B14_2->setEnabled(true);
        B14_2->setGeometry(QRect(354, 77, 98, 98));
        B14_2->setMaximumSize(QSize(110, 110));
        B14_2->setFont(font1);
        B14_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B14_2->setAlignment(Qt::AlignCenter);
        B14_2->setMargin(20);
        B42_2 = new QLabel(centralwidget);
        B42_2->setObjectName(QString::fromUtf8("B42_2"));
        B42_2->setGeometry(QRect(128, 416, 98, 98));
        B42_2->setMaximumSize(QSize(110, 110));
        B42_2->setFont(font1);
        B42_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B42_2->setAlignment(Qt::AlignCenter);
        B42_2->setMargin(20);
        B43_2 = new QLabel(centralwidget);
        B43_2->setObjectName(QString::fromUtf8("B43_2"));
        B43_2->setGeometry(QRect(241, 416, 98, 98));
        B43_2->setMaximumSize(QSize(110, 110));
        B43_2->setFont(font1);
        B43_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B43_2->setAlignment(Qt::AlignCenter);
        B43_2->setMargin(20);
        B12_2 = new QLabel(centralwidget);
        B12_2->setObjectName(QString::fromUtf8("B12_2"));
        B12_2->setEnabled(true);
        B12_2->setGeometry(QRect(128, 77, 98, 98));
        B12_2->setMaximumSize(QSize(110, 110));
        B12_2->setFont(font1);
        B12_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B12_2->setAlignment(Qt::AlignCenter);
        B12_2->setMargin(20);
        B33_2 = new QLabel(centralwidget);
        B33_2->setObjectName(QString::fromUtf8("B33_2"));
        B33_2->setGeometry(QRect(241, 303, 98, 98));
        B33_2->setMaximumSize(QSize(110, 110));
        B33_2->setFont(font1);
        B33_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B33_2->setAlignment(Qt::AlignCenter);
        B33_2->setMargin(20);
        B21_2 = new QLabel(centralwidget);
        B21_2->setObjectName(QString::fromUtf8("B21_2"));
        B21_2->setGeometry(QRect(15, 190, 98, 98));
        B21_2->setMaximumSize(QSize(110, 110));
        B21_2->setFont(font1);
        B21_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B21_2->setAlignment(Qt::AlignCenter);
        B21_2->setMargin(20);
        B23_2 = new QLabel(centralwidget);
        B23_2->setObjectName(QString::fromUtf8("B23_2"));
        B23_2->setGeometry(QRect(241, 190, 98, 98));
        B23_2->setMaximumSize(QSize(110, 110));
        B23_2->setFont(font1);
        B23_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B23_2->setAlignment(Qt::AlignCenter);
        B23_2->setMargin(20);
        B24_2 = new QLabel(centralwidget);
        B24_2->setObjectName(QString::fromUtf8("B24_2"));
        B24_2->setGeometry(QRect(354, 190, 98, 98));
        B24_2->setMaximumSize(QSize(110, 110));
        B24_2->setFont(font1);
        B24_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B24_2->setAlignment(Qt::AlignCenter);
        B24_2->setMargin(20);
        B44_2 = new QLabel(centralwidget);
        B44_2->setObjectName(QString::fromUtf8("B44_2"));
        B44_2->setGeometry(QRect(354, 416, 98, 98));
        B44_2->setMaximumSize(QSize(110, 110));
        B44_2->setFont(font1);
        B44_2->setStyleSheet(QString::fromUtf8("background-color: #cdc1b4; \n"
"border-radius: 3px;"));
        B44_2->setAlignment(Qt::AlignCenter);
        B44_2->setMargin(20);
        MainWindow->setCentralWidget(centralwidget);
        B44_2->raise();
        B43_2->raise();
        B42_2->raise();
        B41_2->raise();
        B34_2->raise();
        B33_2->raise();
        B32_2->raise();
        B31_2->raise();
        B24_2->raise();
        B23_2->raise();
        B22_2->raise();
        B21_2->raise();
        B14_2->raise();
        B13_2->raise();
        B12_2->raise();
        B11_2->raise();
        change_theme_button->raise();
        Max_Score_lbl->raise();
        layoutWidget->raise();
        B31->raise();
        B33->raise();
        B32->raise();
        B34->raise();
        B44->raise();
        B43->raise();
        B41->raise();
        B42->raise();
        B21->raise();
        newGame_btn->raise();
        B13->raise();
        B14->raise();
        B24->raise();
        B23->raise();
        B22->raise();
        B11->raise();
        B12->raise();
        Score_lbl->raise();
        frame->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 467, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        newGame_btn->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
#if QT_CONFIG(shortcut)
        newGame_btn->setShortcut(QCoreApplication::translate("MainWindow", "N", nullptr));
#endif // QT_CONFIG(shortcut)
        B13->setText(QString());
        B14->setText(QString());
        B31->setText(QString());
        B33->setText(QString());
        B32->setText(QString());
        B34->setText(QString());
        B44->setText(QString());
        B43->setText(QString());
        B41->setText(QString());
        B42->setText(QString());
        B21->setText(QString());
        B24->setText(QString());
        B23->setText(QString());
        B22->setText(QString());
        B11->setText(QString());
        B12->setText(QString());
        Score_lbl->setText(QCoreApplication::translate("MainWindow", "Score: ", nullptr));
        status_label->setText(QCoreApplication::translate("MainWindow", "Game Over!", nullptr));
        try_again_btn->setText(QCoreApplication::translate("MainWindow", "Try again", nullptr));
        Max_Score_lbl->setText(QCoreApplication::translate("MainWindow", "Best Score: ", nullptr));
        change_theme_button->setText(QString());
        B22_2->setText(QString());
        B13_2->setText(QString());
        B34_2->setText(QString());
        B11_2->setText(QString());
        B31_2->setText(QString());
        B41_2->setText(QString());
        B32_2->setText(QString());
        B14_2->setText(QString());
        B42_2->setText(QString());
        B43_2->setText(QString());
        B12_2->setText(QString());
        B33_2->setText(QString());
        B21_2->setText(QString());
        B23_2->setText(QString());
        B24_2->setText(QString());
        B44_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
