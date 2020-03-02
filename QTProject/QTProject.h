#pragma once

#include "ui_QTProject.h"
#include <iostream>
#include <stack>
#include <vector>
#include "Qt.h"
#include "opencv.h"

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
	Q_SLOT void setJoinFigures(bool j) { m_joinFigures = j; }
	bool joinFigures() const { return m_joinFigures; }
};

class QTProject : public QMainWindow {
	Q_OBJECT
public:
	QTProject(QWidget* parent = Q_NULLPTR);

	//stack<QGraphicsScene> undostack;
	//stack<QGraphicsScene> redostack;
	Scene GScene;
	QPixmap* pixamp;
	QPixmap buffer;
	QImage image;
	QPixmap newimg;
	QFileDialog imgLoad;
	QFileDialog imgSave;
	int posX;
	int posY;
	int absX;
	int absY;

	~QTProject();

signals:
	void clicked();

private:
	Ui::QTProjectClass ui;
	int oneclick;
	bool mouse_state;
	void wheelEvent(QWheelEvent* event);

public slots:
	void imageOpen();
	void closeClicked();
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
};