/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_graph;
    QHBoxLayout *layoutH_graph1;
    QCustomPlot *BreathingWaveform;
    QCustomPlot *RangeProfile;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *ChestDisplacement;
    QCustomPlot *HeartRate;
    QSpacerItem *horizontalSpacer;
    QLabel *label1;
    QVBoxLayout *verticalLayout;
    QPushButton *mStop;
    QPushButton *mStart;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1366, 815);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 20, 1031, 461));
        gridLayout_2 = new QGridLayout(gridLayoutWidget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setVerticalSpacing(6);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_graph = new QVBoxLayout();
        verticalLayout_graph->setObjectName(QString::fromUtf8("verticalLayout_graph"));
        verticalLayout_graph->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_graph->setContentsMargins(0, -1, -1, -1);
        layoutH_graph1 = new QHBoxLayout();
        layoutH_graph1->setObjectName(QString::fromUtf8("layoutH_graph1"));
        BreathingWaveform = new QCustomPlot(gridLayoutWidget);
        BreathingWaveform->setObjectName(QString::fromUtf8("BreathingWaveform"));

        layoutH_graph1->addWidget(BreathingWaveform);

        RangeProfile = new QCustomPlot(gridLayoutWidget);
        RangeProfile->setObjectName(QString::fromUtf8("RangeProfile"));

        layoutH_graph1->addWidget(RangeProfile);


        verticalLayout_graph->addLayout(layoutH_graph1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ChestDisplacement = new QCustomPlot(gridLayoutWidget);
        ChestDisplacement->setObjectName(QString::fromUtf8("ChestDisplacement"));

        horizontalLayout->addWidget(ChestDisplacement);

        HeartRate = new QCustomPlot(gridLayoutWidget);
        HeartRate->setObjectName(QString::fromUtf8("HeartRate"));

        horizontalLayout->addWidget(HeartRate);


        verticalLayout_graph->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout_graph, 2, 0, 6, 4);

        horizontalSpacer = new QSpacerItem(488, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 1, 1, 1);

        label1 = new QLabel(gridLayoutWidget);
        label1->setObjectName(QString::fromUtf8("label1"));

        gridLayout_2->addWidget(label1, 0, 0, 2, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        mStop = new QPushButton(gridLayoutWidget);
        mStop->setObjectName(QString::fromUtf8("mStop"));

        verticalLayout->addWidget(mStop);

        mStart = new QPushButton(gridLayoutWidget);
        mStart->setObjectName(QString::fromUtf8("mStart"));
        mStart->setEnabled(true);

        verticalLayout->addWidget(mStart);


        gridLayout_2->addLayout(verticalLayout, 1, 2, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1366, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        mStop->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        mStart->setText(QCoreApplication::translate("MainWindow", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
