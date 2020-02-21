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
#include <qpainterpath.h>
#include <qfontdialog.h>
#include <qaction.h>
#include <qstatusbar.h>
#include <Qt3DInput/qmouseevent.h>
#include <QtGui/qevent.h>
#include <qpicture.h>
#include <qdebug.h>
#include <qmutex.h>
#include <qicon.h>
#include <qpainter.h>
//#include <qwidget.h>
#include <QtWidgets/qwidget.h>
#include <qmatrix.h>
#include "ui_QTProject.h"
#include <Windows.h>
#include <tchar.h>
#include <mutex>
#include <qline.h>
#include <vector>
#include <QtGui/qtgui-config.h>
#include <qslider.h>

using namespace std;
using namespace cv;
//namespace py = boost::python;
//namespace np = boost::python::numpy;


class QTProject : public QMainWindow{
	Q_OBJECT

public:
	QTProject(QWidget *parent = Q_NULLPTR);
	QImage img;
	QPixmap newimg;
	QFileDialog imgLoad;
	QFileDialog imgSave;
	stack<QPixmap> undostack;
	stack<QPixmap> redostack;
	int brushcount;
	mutex mutex;
	int posX;
	int posY;
	int absX;
	int absY;
	int Pensize;
	QBrush Pencolor;

private:
	Ui::QTProjectClass ui;
	int oneclick;
	bool mouse_state;
	void mousePressEvent(QMouseEvent* mouse);
	void mouseReleaseEvent(QMouseEvent* mouse);
	void mouseMoveEvent(QMouseEvent* mouse);
	void paintEvent(QPaintEvent* event);
	void drawEvent(QMouseEvent* mouse);

public slots:
	void imageOpen();
	void closeClicked();
	void imageCapture();
	void imageSaveAs();
	void Newfile();
	void version();
	void undo();
	void redo();
	void Screenshot();
	void DrawLine();
	void brushcountfunc();
	void fontsizeup();
	void fontsizedown();
	void colorRedselect();
	void colorBlueselect();
	void colorBlackselect();
	void DrawRect();
	void DrawCir();
};