/********************************************************************************
** Form generated from reading UI file 'QTProject.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTPROJECT_H
#define UI_QTPROJECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTProjectClass
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionUndo;
    QAction *actionView;
    QAction *actionRedo;
    QAction *actionVersion;
    QAction *actionUser;
    QAction *actionCut;
    QAction *actionNew;
    QAction *actionSaveAs;
    QAction *actionPrint;
    QAction *actionScreenShot;
    QAction *actionCopy;
    QAction *actionSelect_All;
    QWidget *centralWidget;
    QLabel *pictureDraw;
    QPushButton *PaintButton;
    QMenuBar *menuBar;
    QMenu *menuQTProject;
    QMenu *menuOption;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QTProjectClass)
    {
        if (QTProjectClass->objectName().isEmpty())
            QTProjectClass->setObjectName(QStringLiteral("QTProjectClass"));
        QTProjectClass->resize(997, 865);
        actionOpen = new QAction(QTProjectClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(QTProjectClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionExit = new QAction(QTProjectClass);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionUndo = new QAction(QTProjectClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionView = new QAction(QTProjectClass);
        actionView->setObjectName(QStringLiteral("actionView"));
        actionRedo = new QAction(QTProjectClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionVersion = new QAction(QTProjectClass);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionUser = new QAction(QTProjectClass);
        actionUser->setObjectName(QStringLiteral("actionUser"));
        actionCut = new QAction(QTProjectClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionNew = new QAction(QTProjectClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionSaveAs = new QAction(QTProjectClass);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionPrint = new QAction(QTProjectClass);
        actionPrint->setObjectName(QStringLiteral("actionPrint"));
        actionScreenShot = new QAction(QTProjectClass);
        actionScreenShot->setObjectName(QStringLiteral("actionScreenShot"));
        actionCopy = new QAction(QTProjectClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionSelect_All = new QAction(QTProjectClass);
        actionSelect_All->setObjectName(QStringLiteral("actionSelect_All"));
        centralWidget = new QWidget(QTProjectClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pictureDraw = new QLabel(centralWidget);
        pictureDraw->setObjectName(QStringLiteral("pictureDraw"));
        pictureDraw->setGeometry(QRect(60, 10, 311, 291));
        PaintButton = new QPushButton(centralWidget);
        PaintButton->setObjectName(QStringLiteral("PaintButton"));
        PaintButton->setGeometry(QRect(430, 10, 93, 31));
        QTProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTProjectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 997, 26));
        menuQTProject = new QMenu(menuBar);
        menuQTProject->setObjectName(QStringLiteral("menuQTProject"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QTProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTProjectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        QTProjectClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QTProjectClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTProjectClass->setStatusBar(statusBar);

        menuBar->addAction(menuQTProject->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuQTProject->addSeparator();
        menuQTProject->addAction(actionNew);
        menuQTProject->addAction(actionOpen);
        menuQTProject->addAction(actionSave);
        menuQTProject->addAction(actionSaveAs);
        menuQTProject->addAction(actionPrint);
        menuQTProject->addAction(actionScreenShot);
        menuQTProject->addAction(actionExit);
        menuOption->addAction(actionUndo);
        menuOption->addAction(actionRedo);
        menuOption->addAction(actionCut);
        menuOption->addAction(actionCopy);
        menuOption->addAction(actionSelect_All);
        menuHelp->addAction(actionUser);
        menuHelp->addAction(actionVersion);

        retranslateUi(QTProjectClass);

        QMetaObject::connectSlotsByName(QTProjectClass);
    } // setupUi

    void retranslateUi(QMainWindow *QTProjectClass)
    {
        QTProjectClass->setWindowTitle(QApplication::translate("QTProjectClass", "QTProject", Q_NULLPTR));
        actionOpen->setText(QApplication::translate("QTProjectClass", "Open", Q_NULLPTR));
        actionSave->setText(QApplication::translate("QTProjectClass", "Save", Q_NULLPTR));
        actionExit->setText(QApplication::translate("QTProjectClass", "Exit", Q_NULLPTR));
        actionUndo->setText(QApplication::translate("QTProjectClass", "undo", Q_NULLPTR));
        actionView->setText(QApplication::translate("QTProjectClass", "View", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("QTProjectClass", "redo", Q_NULLPTR));
        actionVersion->setText(QApplication::translate("QTProjectClass", "Version", Q_NULLPTR));
        actionUser->setText(QApplication::translate("QTProjectClass", "User", Q_NULLPTR));
        actionCut->setText(QApplication::translate("QTProjectClass", "Cut", Q_NULLPTR));
        actionNew->setText(QApplication::translate("QTProjectClass", "New", Q_NULLPTR));
        actionSaveAs->setText(QApplication::translate("QTProjectClass", "Save As", Q_NULLPTR));
        actionPrint->setText(QApplication::translate("QTProjectClass", "Print", Q_NULLPTR));
        actionScreenShot->setText(QApplication::translate("QTProjectClass", "Screen Shot", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("QTProjectClass", "Copy", Q_NULLPTR));
        actionSelect_All->setText(QApplication::translate("QTProjectClass", "Select All", Q_NULLPTR));
        pictureDraw->setText(QString());
        PaintButton->setText(QApplication::translate("QTProjectClass", "Paint", Q_NULLPTR));
        menuQTProject->setTitle(QApplication::translate("QTProjectClass", "File", Q_NULLPTR));
        menuOption->setTitle(QApplication::translate("QTProjectClass", "Edit", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("QTProjectClass", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QTProjectClass: public Ui_QTProjectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTPROJECT_H
