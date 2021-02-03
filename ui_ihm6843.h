/********************************************************************************
** Form generated from reading UI file 'ihm6843.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IHM6843_H
#define UI_IHM6843_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_IHM6843
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *distance;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *start;
    QPushButton *stop;
    QHBoxLayout *horizontalLayout_2;
    QCustomPlot *RangeP;

    void setupUi(QMainWindow *IHM6843)
    {
        if (IHM6843->objectName().isEmpty())
            IHM6843->setObjectName(QString::fromUtf8("IHM6843"));
        IHM6843->resize(1038, 715);
        centralwidget = new QWidget(IHM6843);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        distance = new QLabel(centralwidget);
        distance->setObjectName(QString::fromUtf8("distance"));
        distance->setText("Distance : "+QString::number(0)+" m");
        distance->setStyleSheet("QLabel { font: 15pt; }");

        horizontalLayout->addWidget(distance);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        start = new QPushButton(centralwidget);
        start->setObjectName(QString::fromUtf8("start"));

        horizontalLayout->addWidget(start);

        stop = new QPushButton(centralwidget);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setCheckable(false);

        horizontalLayout->addWidget(stop);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        RangeP = new QCustomPlot(centralwidget);
        RangeP->setObjectName(QString::fromUtf8("RangeP"));

        horizontalLayout_2->addWidget(RangeP);


        verticalLayout->addLayout(horizontalLayout_2);

        IHM6843->setCentralWidget(centralwidget);

        retranslateUi(IHM6843);

        QMetaObject::connectSlotsByName(IHM6843);
    } // setupUi

    void retranslateUi(QMainWindow *IHM6843)
    {
        IHM6843->setWindowTitle(QCoreApplication::translate("IHM6843", "MainWindow", nullptr));
        start->setText(QCoreApplication::translate("IHM6843", "Start", nullptr));
        stop->setText(QCoreApplication::translate("IHM6843", "Stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class IHM6843: public Ui_IHM6843 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IHM6843_H
