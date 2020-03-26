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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
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
    QGroupBox *groupBox;
    QLabel *WidthLabel;
    QTextEdit *textEdit;
    QLabel *HeightLabel;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QLabel *FileLabel;
    QLabel *PensizeLabel;
    QTextEdit *textEdit_4;
    QPushButton *FontsizeUp;
    QPushButton *FontsizeDown;
    QPushButton *penBlack;
    QPushButton *penRed;
    QPushButton *penBlue;
    QLabel *Pencolor;
    QTextEdit *textEdit_5;
    QGroupBox *groupBox_2;
    QTextEdit *textEdit_6;
    QLabel *Penmode;
    QGroupBox *groupBox_3;
    QRadioButton *PaintButton;
    QRadioButton *LineButton;
    QRadioButton *TextButton;
    QRadioButton *RectangleButton;
    QRadioButton *CircleButton;
    QRadioButton *eraseButton;
    QRadioButton *AreaButton;
    QRadioButton *EllipseButton;
    QGraphicsView *testView;
    QPushButton *extractButton;
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
        QTProjectClass->resize(1435, 848);
        QTProjectClass->setMouseTracking(false);
        QTProjectClass->setTabletTracking(false);
        QTProjectClass->setDocumentMode(false);
        QTProjectClass->setUnifiedTitleAndToolBarOnMac(false);
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
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1110, 580, 301, 181));
        WidthLabel = new QLabel(groupBox);
        WidthLabel->setObjectName(QStringLiteral("WidthLabel"));
        WidthLabel->setGeometry(QRect(90, 80, 191, 31));
        textEdit = new QTextEdit(groupBox);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setEnabled(false);
        textEdit->setGeometry(QRect(10, 80, 61, 31));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setLineWidth(0);
        textEdit->setLineWrapMode(QTextEdit::NoWrap);
        textEdit->setReadOnly(true);
        textEdit->setAcceptRichText(true);
        HeightLabel = new QLabel(groupBox);
        HeightLabel->setObjectName(QStringLiteral("HeightLabel"));
        HeightLabel->setGeometry(QRect(90, 120, 191, 31));
        textEdit_2 = new QTextEdit(groupBox);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setEnabled(false);
        textEdit_2->setGeometry(QRect(10, 120, 71, 31));
        textEdit_2->setFrameShape(QFrame::NoFrame);
        textEdit_2->setLineWidth(0);
        textEdit_2->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_2->setReadOnly(true);
        textEdit_2->setAcceptRichText(true);
        textEdit_3 = new QTextEdit(groupBox);
        textEdit_3->setObjectName(QStringLiteral("textEdit_3"));
        textEdit_3->setEnabled(false);
        textEdit_3->setGeometry(QRect(10, 40, 61, 31));
        textEdit_3->setFrameShape(QFrame::NoFrame);
        textEdit_3->setLineWidth(0);
        textEdit_3->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_3->setReadOnly(true);
        textEdit_3->setAcceptRichText(true);
        FileLabel = new QLabel(groupBox);
        FileLabel->setObjectName(QStringLiteral("FileLabel"));
        FileLabel->setGeometry(QRect(90, 40, 191, 31));
        PensizeLabel = new QLabel(centralWidget);
        PensizeLabel->setObjectName(QStringLiteral("PensizeLabel"));
        PensizeLabel->setGeometry(QRect(1320, 410, 71, 31));
        textEdit_4 = new QTextEdit(centralWidget);
        textEdit_4->setObjectName(QStringLiteral("textEdit_4"));
        textEdit_4->setEnabled(false);
        textEdit_4->setGeometry(QRect(1230, 410, 91, 31));
        textEdit_4->setFrameShape(QFrame::NoFrame);
        textEdit_4->setFrameShadow(QFrame::Sunken);
        textEdit_4->setLineWidth(0);
        textEdit_4->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_4->setReadOnly(true);
        textEdit_4->setAcceptRichText(true);
        FontsizeUp = new QPushButton(centralWidget);
        FontsizeUp->setObjectName(QStringLiteral("FontsizeUp"));
        FontsizeUp->setGeometry(QRect(1310, 490, 31, 28));
        FontsizeDown = new QPushButton(centralWidget);
        FontsizeDown->setObjectName(QStringLiteral("FontsizeDown"));
        FontsizeDown->setGeometry(QRect(1350, 490, 31, 28));
        penBlack = new QPushButton(centralWidget);
        penBlack->setObjectName(QStringLiteral("penBlack"));
        penBlack->setGeometry(QRect(1240, 530, 51, 28));
        penRed = new QPushButton(centralWidget);
        penRed->setObjectName(QStringLiteral("penRed"));
        penRed->setGeometry(QRect(1300, 530, 51, 28));
        penBlue = new QPushButton(centralWidget);
        penBlue->setObjectName(QStringLiteral("penBlue"));
        penBlue->setGeometry(QRect(1360, 530, 51, 28));
        Pencolor = new QLabel(centralWidget);
        Pencolor->setObjectName(QStringLiteral("Pencolor"));
        Pencolor->setGeometry(QRect(1320, 440, 71, 31));
        textEdit_5 = new QTextEdit(centralWidget);
        textEdit_5->setObjectName(QStringLiteral("textEdit_5"));
        textEdit_5->setEnabled(false);
        textEdit_5->setGeometry(QRect(1230, 440, 91, 31));
        textEdit_5->setFrameShape(QFrame::NoFrame);
        textEdit_5->setFrameShadow(QFrame::Sunken);
        textEdit_5->setLineWidth(0);
        textEdit_5->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_5->setReadOnly(true);
        textEdit_5->setAcceptRichText(true);
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1200, 320, 211, 161));
        groupBox_2->setCheckable(false);
        groupBox_2->setChecked(false);
        textEdit_6 = new QTextEdit(centralWidget);
        textEdit_6->setObjectName(QStringLiteral("textEdit_6"));
        textEdit_6->setEnabled(false);
        textEdit_6->setGeometry(QRect(1230, 380, 101, 31));
        textEdit_6->setFrameShape(QFrame::NoFrame);
        textEdit_6->setFrameShadow(QFrame::Sunken);
        textEdit_6->setLineWidth(0);
        textEdit_6->setLineWrapMode(QTextEdit::NoWrap);
        textEdit_6->setReadOnly(true);
        textEdit_6->setOverwriteMode(true);
        textEdit_6->setAcceptRichText(true);
        Penmode = new QLabel(centralWidget);
        Penmode->setObjectName(QStringLiteral("Penmode"));
        Penmode->setGeometry(QRect(1320, 380, 71, 31));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setEnabled(true);
        groupBox_3->setGeometry(QRect(1290, 20, 121, 271));
        groupBox_3->setFlat(false);
        groupBox_3->setCheckable(false);
        groupBox_3->setChecked(false);
        PaintButton = new QRadioButton(groupBox_3);
        PaintButton->setObjectName(QStringLiteral("PaintButton"));
        PaintButton->setGeometry(QRect(20, 30, 61, 19));
        LineButton = new QRadioButton(groupBox_3);
        LineButton->setObjectName(QStringLiteral("LineButton"));
        LineButton->setGeometry(QRect(20, 60, 61, 19));
        LineButton->setChecked(true);
        TextButton = new QRadioButton(groupBox_3);
        TextButton->setObjectName(QStringLiteral("TextButton"));
        TextButton->setGeometry(QRect(20, 90, 61, 19));
        RectangleButton = new QRadioButton(groupBox_3);
        RectangleButton->setObjectName(QStringLiteral("RectangleButton"));
        RectangleButton->setGeometry(QRect(20, 120, 61, 19));
        CircleButton = new QRadioButton(groupBox_3);
        CircleButton->setObjectName(QStringLiteral("CircleButton"));
        CircleButton->setGeometry(QRect(20, 150, 108, 19));
        eraseButton = new QRadioButton(groupBox_3);
        eraseButton->setObjectName(QStringLiteral("eraseButton"));
        eraseButton->setGeometry(QRect(20, 210, 71, 19));
        AreaButton = new QRadioButton(groupBox_3);
        AreaButton->setObjectName(QStringLiteral("AreaButton"));
        AreaButton->setGeometry(QRect(20, 240, 61, 19));
        EllipseButton = new QRadioButton(groupBox_3);
        EllipseButton->setObjectName(QStringLiteral("EllipseButton"));
        EllipseButton->setGeometry(QRect(20, 180, 81, 19));
        testView = new QGraphicsView(centralWidget);
        testView->setObjectName(QStringLiteral("testView"));
        testView->setGeometry(QRect(40, 10, 1000, 751));
        testView->setMaximumSize(QSize(1000, 800));
        testView->setBaseSize(QSize(1000, 800));
        testView->setMouseTracking(false);
        testView->setFocusPolicy(Qt::StrongFocus);
        testView->setAcceptDrops(false);
        QBrush brush(QColor(255, 255, 255, 50));
        brush.setStyle(Qt::SolidPattern);
        testView->setBackgroundBrush(brush);
        QBrush brush1(QColor(255, 255, 255, 30));
        brush1.setStyle(Qt::SolidPattern);
        testView->setForegroundBrush(brush1);
        testView->setSceneRect(QRectF(0, 0, 0, 0));
        testView->setDragMode(QGraphicsView::NoDrag);
        testView->setCacheMode(QGraphicsView::CacheNone);
        testView->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        testView->setResizeAnchor(QGraphicsView::NoAnchor);
        testView->setRubberBandSelectionMode(Qt::IntersectsItemShape);
        extractButton = new QPushButton(centralWidget);
        extractButton->setObjectName(QStringLiteral("extractButton"));
        extractButton->setGeometry(QRect(1110, 10, 131, 41));
        QTProjectClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QTProjectClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setEnabled(true);
        menuBar->setGeometry(QRect(0, 0, 1435, 26));
        menuBar->setAutoFillBackground(false);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menuQTProject = new QMenu(menuBar);
        menuQTProject->setObjectName(QStringLiteral("menuQTProject"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QStringLiteral("menuOption"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        QTProjectClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QTProjectClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
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
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("QTProjectClass", "Ctrl+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSave->setText(QApplication::translate("QTProjectClass", "Save", Q_NULLPTR));
        actionExit->setText(QApplication::translate("QTProjectClass", "Exit", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("QTProjectClass", "Esc", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionUndo->setText(QApplication::translate("QTProjectClass", "undo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionUndo->setShortcut(QApplication::translate("QTProjectClass", "Ctrl+Z", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionView->setText(QApplication::translate("QTProjectClass", "View", Q_NULLPTR));
        actionRedo->setText(QApplication::translate("QTProjectClass", "redo", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionRedo->setShortcut(QApplication::translate("QTProjectClass", "Ctrl+X", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionVersion->setText(QApplication::translate("QTProjectClass", "Version", Q_NULLPTR));
        actionUser->setText(QApplication::translate("QTProjectClass", "User", Q_NULLPTR));
        actionCut->setText(QApplication::translate("QTProjectClass", "Cut", Q_NULLPTR));
        actionNew->setText(QApplication::translate("QTProjectClass", "New", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("QTProjectClass", "Ctrl+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionSaveAs->setText(QApplication::translate("QTProjectClass", "Save As", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSaveAs->setShortcut(QApplication::translate("QTProjectClass", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionPrint->setText(QApplication::translate("QTProjectClass", "Print", Q_NULLPTR));
        actionScreenShot->setText(QApplication::translate("QTProjectClass", "Screen Shot", Q_NULLPTR));
        actionCopy->setText(QApplication::translate("QTProjectClass", "Copy", Q_NULLPTR));
        actionSelect_All->setText(QApplication::translate("QTProjectClass", "Select All", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("QTProjectClass", "Information", Q_NULLPTR));
        WidthLabel->setText(QString());
        textEdit->setHtml(QApplication::translate("QTProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Width :</span></p></body></html>", Q_NULLPTR));
        HeightLabel->setText(QString());
        textEdit_2->setHtml(QApplication::translate("QTProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Height :</span></p></body></html>", Q_NULLPTR));
        textEdit_3->setHtml(QApplication::translate("QTProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">File :</span></p></body></html>", Q_NULLPTR));
        FileLabel->setText(QString());
        PensizeLabel->setText(QString());
        textEdit_4->setHtml(QApplication::translate("QTProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Font size :</span></p></body></html>", Q_NULLPTR));
        FontsizeUp->setText(QApplication::translate("QTProjectClass", "\342\206\221", Q_NULLPTR));
        FontsizeDown->setText(QApplication::translate("QTProjectClass", "\342\206\223", Q_NULLPTR));
        penBlack->setText(QApplication::translate("QTProjectClass", "Black", Q_NULLPTR));
        penRed->setText(QApplication::translate("QTProjectClass", "Red", Q_NULLPTR));
        penBlue->setText(QApplication::translate("QTProjectClass", "Blue", Q_NULLPTR));
        Pencolor->setText(QString());
        textEdit_5->setHtml(QApplication::translate("QTProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Font </span>color<span style=\" font-size:10pt;\"> :</span></p></body></html>", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("QTProjectClass", "Font Information", Q_NULLPTR));
        textEdit_6->setHtml(QApplication::translate("QTProjectClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Gulim'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">Fon</span>t mode<span style=\" font-size:10pt;\"> :</span></p></body></html>", Q_NULLPTR));
        Penmode->setText(QString());
        groupBox_3->setTitle(QApplication::translate("QTProjectClass", "SelectMode", Q_NULLPTR));
        PaintButton->setText(QApplication::translate("QTProjectClass", "Paint", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        PaintButton->setShortcut(QApplication::translate("QTProjectClass", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        LineButton->setText(QApplication::translate("QTProjectClass", "Line", Q_NULLPTR));
        TextButton->setText(QApplication::translate("QTProjectClass", "Text", Q_NULLPTR));
        RectangleButton->setText(QApplication::translate("QTProjectClass", "Rect", Q_NULLPTR));
        CircleButton->setText(QApplication::translate("QTProjectClass", "Circ", Q_NULLPTR));
        eraseButton->setText(QApplication::translate("QTProjectClass", "Erase", Q_NULLPTR));
        AreaButton->setText(QApplication::translate("QTProjectClass", "Area", Q_NULLPTR));
        EllipseButton->setText(QApplication::translate("QTProjectClass", "Ellipse", Q_NULLPTR));
        extractButton->setText(QApplication::translate("QTProjectClass", "Extract", Q_NULLPTR));
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
