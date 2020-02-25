#pragma once

//#define BOOST_PYTHON_STATIC_LIB
//#define BOOST_LIB_NAME "boost_numpy3"

//#include <boost/config/auto_link.hpp>
//#include <boost/python.hpp>
//#include <boost/python/numpy.hpp>
#include <iostream>
#include <stack>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>
#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <QMessageBox>
#include <qfiledialog.h>
#include <QImage>
#include <QPainter>
#include <qcolor.h>
#include <qaction.h>
#include <Qt3DInput/qmouseevent.h>
#include <qgraphicsitem.h>
#include <qgraphicsscene.h>
#include <qgraphicsview.h>
#include <qgraphicsitem.h>
#include <qgraphicsproxywidget.h>
#include <qgraphicsgridlayout.h>
#include <qpainter.h>
#include <QtWidgets/qwidget.h>
#include <qgraphicssceneevent.h>
#include "ui_QTProject.h"
#include <qlabel.h>
#include <vector>
#include <qgridlayout.h>
#include <qcheckbox.h>


using namespace std;
using namespace cv;
//namespace py = boost::python;
//namespace np = boost::python::numpy;

class EmptyItem : public QGraphicsItem {
public:
	EmptyItem(QGraphicsItem* parent = nullptr) : QGraphicsItem{ parent } {}
	QRectF boundingRect() const override { return { 0,0,1,1 }; }
	void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*) override {}
};

class Scene : public QGraphicsScene {
	Q_OBJECT
	Q_PROPERTY(bool joinFigures READ joinFigures WRITE setJoinFigures)

	bool m_joinFigures = false;
	QGraphicsPathItem* m_item = nullptr;
	QPainterPath m_path;

	void LineDraw();

	void newPoint(const QPointF& pt) {
		if (!m_item) {
			LineDraw();
			m_path.moveTo(pt);
		}
		else {
			m_path.lineTo(pt);
			m_item->setPath(m_path);
		}
	}
	void mousePressEvent(QGraphicsSceneMouseEvent* ev) override {
		if (ev->buttons() != Qt::LeftButton) return;
		if (!m_joinFigures) m_item = nullptr;
		newPoint(ev->scenePos());
	}
	void mouseMoveEvent(QGraphicsSceneMouseEvent* ev) override {
		if (ev->buttons() != Qt::LeftButton) return;
		newPoint(ev->scenePos());
	}
	void mouseReleaseEvent(QGraphicsSceneMouseEvent*) override {
		if (!m_path.isEmpty()) return;
		delete m_item;
		m_item = nullptr;
	}
public:
	Scene(QObject* parent = nullptr) : QGraphicsScene{ parent }
	{
		addItem(new EmptyItem{});
	}
	Q_SLOT void setJoinFigures(bool j) { m_joinFigures = j; }
	bool joinFigures() const { return m_joinFigures; }
};

class QTProject : public QMainWindow {
	Q_OBJECT
	QGridLayout m_layout{ this };
	QGraphicsView m_view;
	QCheckBox m_join{ "Join Figures (toggle with Spacebar)" };
	QAction m_toggleJoin{ this };
public:
	QTProject(QWidget* parent = Q_NULLPTR);

	QPixmap* pixamp;
	QPixmap buffer;
	QImage image;
	QPixmap newimg;
	QFileDialog imgLoad;
	QFileDialog imgSave;
	stack<QPixmap> undostack;
	stack<QPixmap> redostack;
	int brushcount;
	int posX;
	int posY;
	int absX;
	int absY;
	int Colorselect;

	~QTProject();

signals:
	void clicked();

private:
	Ui::QTProjectClass ui;
	int oneclick;
	bool mouse_state;
	//void mousePressEvent(QGraphicsSceneMouseEvent *mouse);
	//void mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse);
	//void mouseMoveEvent(QGraphicsSceneMouseEvent* mouse);
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
	void Erase();
	void Paint();
	void newScene();
};