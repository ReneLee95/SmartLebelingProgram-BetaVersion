#pragma once

//#define BOOST_PYTHON_STATIC_LIB
//#define BOOST_LIB_NAME "boost_numpy3"

//#include <boost/config/auto_link.hpp>
//#include <boost/python.hpp>
//#include <boost/python/numpy.hpp>
#include <iostream>
#include <conio.h>
#include <stack>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include <QtCore/qcoreapplication.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/core/core.hpp>
#include <QToolBox>
#include <qapplication.h>
#include <QMessageBox>
#include <qfiledialog.h>
#include <QImage>
#include <QPainter>
#include <qdebug.h>
#include <qmutex.h>
#include <qwidget.h>
#include <qmatrix.h>
#include "ui_QTProject.h"
#include <Windows.h>
#include <tchar.h>

using namespace std;
using namespace cv;
//namespace py = boost::python;
//namespace np = boost::python::numpy;

class QTProject : public QMainWindow{
	Q_OBJECT

public:
	QTProject(QWidget *parent = Q_NULLPTR);
	QPixmap img;
	QPixmap newimg;
	QFileDialog imgLoad;
	QFileDialog imgSave;
	stack<QPixmap> undostack;
	stack<QPixmap> redostack;
	int brushcount;
	Mat image;

private:
	Ui::QTProjectClass ui;
	int posX;
	int posY;
	int absX;
	int absY;
	Point ptOld;

public slots:
	void brushClicked();
	void closeClicked();
	void imageCapture();
	void imageSaveAs();
	void Newfile();
	void version();
	void paintEvent(QPaintEvent* event);
	void undo();
	void redo();
	void Screenshot();
	void DrawLine();
	void brushcountfunc();
};