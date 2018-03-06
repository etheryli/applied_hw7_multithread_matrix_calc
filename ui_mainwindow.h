/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *CentralWidget;
    QWidget *layoutWidget;
    QGridLayout *Grid;
    QLabel *MatrixALabel;
    QLineEdit *MatrixALineEdit;
    QPushButton *MatrixAButton;
    QLabel *MatrixBLabel;
    QLineEdit *MatrixBLineEdit;
    QPushButton *MatrixBButton;
    QLabel *MatrixCLabel;
    QLineEdit *MatrixCLineEdit;
    QPushButton *MatrixCButton;
    QLabel *pThreadLabel;
    QProgressBar *pThreadProgressBar;
    QLabel *pThreadValueLabel;
    QLabel *QRunnableLabe1;
    QProgressBar *QRunnableProgressBaR;
    QLabel *QRunnableValueLabel;
    QPushButton *ComputeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(500, 300);
        CentralWidget = new QWidget(MainWindow);
        CentralWidget->setObjectName(QStringLiteral("CentralWidget"));
        CentralWidget->setMinimumSize(QSize(400, 0));
        layoutWidget = new QWidget(CentralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 10, 461, 231));
        Grid = new QGridLayout(layoutWidget);
        Grid->setSpacing(6);
        Grid->setContentsMargins(11, 11, 11, 11);
        Grid->setObjectName(QStringLiteral("Grid"));
        Grid->setContentsMargins(0, 0, 0, 0);
        MatrixALabel = new QLabel(layoutWidget);
        MatrixALabel->setObjectName(QStringLiteral("MatrixALabel"));

        Grid->addWidget(MatrixALabel, 0, 0, 1, 1);

        MatrixALineEdit = new QLineEdit(layoutWidget);
        MatrixALineEdit->setObjectName(QStringLiteral("MatrixALineEdit"));
        MatrixALineEdit->setEnabled(false);
        MatrixALineEdit->setReadOnly(true);

        Grid->addWidget(MatrixALineEdit, 0, 1, 1, 1);

        MatrixAButton = new QPushButton(layoutWidget);
        MatrixAButton->setObjectName(QStringLiteral("MatrixAButton"));

        Grid->addWidget(MatrixAButton, 0, 2, 1, 1);

        MatrixBLabel = new QLabel(layoutWidget);
        MatrixBLabel->setObjectName(QStringLiteral("MatrixBLabel"));

        Grid->addWidget(MatrixBLabel, 1, 0, 1, 1);

        MatrixBLineEdit = new QLineEdit(layoutWidget);
        MatrixBLineEdit->setObjectName(QStringLiteral("MatrixBLineEdit"));
        MatrixBLineEdit->setEnabled(false);
        MatrixBLineEdit->setReadOnly(true);

        Grid->addWidget(MatrixBLineEdit, 1, 1, 1, 1);

        MatrixBButton = new QPushButton(layoutWidget);
        MatrixBButton->setObjectName(QStringLiteral("MatrixBButton"));

        Grid->addWidget(MatrixBButton, 1, 2, 1, 1);

        MatrixCLabel = new QLabel(layoutWidget);
        MatrixCLabel->setObjectName(QStringLiteral("MatrixCLabel"));

        Grid->addWidget(MatrixCLabel, 2, 0, 1, 1);

        MatrixCLineEdit = new QLineEdit(layoutWidget);
        MatrixCLineEdit->setObjectName(QStringLiteral("MatrixCLineEdit"));
        MatrixCLineEdit->setReadOnly(false);

        Grid->addWidget(MatrixCLineEdit, 2, 1, 1, 1);

        MatrixCButton = new QPushButton(layoutWidget);
        MatrixCButton->setObjectName(QStringLiteral("MatrixCButton"));

        Grid->addWidget(MatrixCButton, 2, 2, 1, 1);

        pThreadLabel = new QLabel(layoutWidget);
        pThreadLabel->setObjectName(QStringLiteral("pThreadLabel"));

        Grid->addWidget(pThreadLabel, 3, 0, 1, 1);

        pThreadProgressBar = new QProgressBar(layoutWidget);
        pThreadProgressBar->setObjectName(QStringLiteral("pThreadProgressBar"));
        pThreadProgressBar->setValue(0);

        Grid->addWidget(pThreadProgressBar, 3, 1, 1, 1);

        pThreadValueLabel = new QLabel(layoutWidget);
        pThreadValueLabel->setObjectName(QStringLiteral("pThreadValueLabel"));
        pThreadValueLabel->setAlignment(Qt::AlignCenter);

        Grid->addWidget(pThreadValueLabel, 3, 2, 1, 1);

        QRunnableLabe1 = new QLabel(layoutWidget);
        QRunnableLabe1->setObjectName(QStringLiteral("QRunnableLabe1"));

        Grid->addWidget(QRunnableLabe1, 4, 0, 1, 1);

        QRunnableProgressBaR = new QProgressBar(layoutWidget);
        QRunnableProgressBaR->setObjectName(QStringLiteral("QRunnableProgressBaR"));
        QRunnableProgressBaR->setValue(0);

        Grid->addWidget(QRunnableProgressBaR, 4, 1, 1, 1);

        QRunnableValueLabel = new QLabel(layoutWidget);
        QRunnableValueLabel->setObjectName(QStringLiteral("QRunnableValueLabel"));
        QRunnableValueLabel->setAlignment(Qt::AlignCenter);

        Grid->addWidget(QRunnableValueLabel, 4, 2, 1, 1);

        ComputeButton = new QPushButton(CentralWidget);
        ComputeButton->setObjectName(QStringLiteral("ComputeButton"));
        ComputeButton->setGeometry(QRect(20, 240, 461, 40));
        ComputeButton->setFlat(false);
        MainWindow->setCentralWidget(CentralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        MatrixALabel->setText(QApplication::translate("MainWindow", "Matrix A", Q_NULLPTR));
        MatrixAButton->setText(QApplication::translate("MainWindow", "....", Q_NULLPTR));
        MatrixBLabel->setText(QApplication::translate("MainWindow", "Matrix B", Q_NULLPTR));
        MatrixBButton->setText(QApplication::translate("MainWindow", "....", Q_NULLPTR));
        MatrixCLabel->setText(QApplication::translate("MainWindow", "Matrix C", Q_NULLPTR));
        MatrixCButton->setText(QApplication::translate("MainWindow", "....", Q_NULLPTR));
        pThreadLabel->setText(QApplication::translate("MainWindow", "PThread", Q_NULLPTR));
        pThreadValueLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        QRunnableLabe1->setText(QApplication::translate("MainWindow", "QRunnable", Q_NULLPTR));
        QRunnableValueLabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        ComputeButton->setText(QApplication::translate("MainWindow", "COMPUTE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
