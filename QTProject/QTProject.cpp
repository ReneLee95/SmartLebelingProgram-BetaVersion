#include "QTProject.h"

QBrush Pencolor = Qt::black;
qreal Pensize = 5;
int brushcount = 0;
int Colorselect = 1;

QTProject::QTProject(QWidget* parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
	//	this->ui.testView= this->findChild<QGraphicsView*>("graphicsView");
	//	this->m_graphScene = this->ui.testView->scene();
	setWindowFlags(Qt::CustomizeWindowHint);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(imageOpen()));
	connect(ui.actionScreenShot, SIGNAL(triggered()), this, SLOT(imageCapture()));
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(closeClicked()));
	connect(ui.actionSaveAs, SIGNAL(triggered()), this, SLOT(imageSaveAs()));
	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(Newfile()));
	connect(ui.actionVersion, SIGNAL(triggered()), this, SLOT(version()));
	connect(ui.actionUndo, SIGNAL(triggered()), this, SLOT(undo()));
	connect(ui.actionRedo, SIGNAL(triggered()), this, SLOT(redo()));
	connect(ui.actionScreenShot, SIGNAL(triggered()), this, SLOT(Screenshot()));
	connect(ui.LineButton, SIGNAL(clicked()), this, SLOT(DrawLine()));
	connect(ui.PaintButton, SIGNAL(clicked()), this, SLOT(brushcountfunc()));
	connect(ui.FontsizeUp, SIGNAL(clicked()), this, SLOT(fontsizeup()));
	connect(ui.FontsizeDown, SIGNAL(clicked()), this, SLOT(fontsizedown()));
	connect(ui.penBlack, SIGNAL(clicked()), this, SLOT(colorBlackselect()));
	connect(ui.penBlue, SIGNAL(clicked()), this, SLOT(colorBlueselect()));
	connect(ui.penRed, SIGNAL(clicked()), this, SLOT(colorRedselect()));
	connect(ui.RectangleButton, SIGNAL(clicked()), this, SLOT(DrawRect()));
	connect(ui.CircleButton, SIGNAL(clicked()), this, SLOT(DrawCir()));
	connect(ui.eraseButton, SIGNAL(clicked()), this, SLOT(Erase()));
	connect(ui.PaintButton, SIGNAL(clicekd()), this, SLOT(Paint()));

	posX = QCursor::pos().x();
	posY = QCursor::pos().y();
	absX = QCursor::pos().x();
	absY = QCursor::pos().y();

	mouse_state = false;

	if (Colorselect == 0) {
		ui.Pencolor->setText("Erase");
	}

	ui.PensizeLabel->setText(QString::number(Pensize));
	ui.testView2->ensureVisible;
	newScene();

}

void QTProject::newScene() {
//	if (ui.testView->scene()) ui.testView->scene();
	ui.testView->setScene(new Scene);
}

void QTProject::Paint() {

}

void QTProject::Erase() {
	Pencolor = Qt::white;
	Colorselect = 0;
	ui.Pencolor->setText("Erase");
}

void Scene::LineDraw() {
	addItem(m_item = new QGraphicsPathItem);
	m_item->setPen(QPen{ Pencolor, Pensize, Qt::SolidLine, Qt::RoundCap });
	m_path = QPainterPath{};
}

void QTProject::colorBlackselect() {
	Pencolor = Qt::black;
	Colorselect = 1;
	ui.Pencolor->setText("black");
}

void QTProject::colorBlueselect() {
	Pencolor = Qt::blue;
	Colorselect = 2;
	ui.Pencolor->setText("blue");
}

void QTProject::colorRedselect() {
	Pencolor = Qt::red;
	Colorselect = 3;
	ui.Pencolor->setText("red");
}

void QTProject::fontsizeup() {
	Pensize++;
	ui.PensizeLabel->setText(QString::number(Pensize));
}

void QTProject::fontsizedown() {
	Pensize--;
	ui.PensizeLabel->setText(QString::number(Pensize));
}

void QTProject::paintEvent(QPaintEvent* event) {	

}

void QTProject::imageOpen() {
	//cv::Mat imgtest;
	QString filePath = QFileDialog::getOpenFileName(this, "Open Image File", QDir::currentPath());
	QString fileName = filePath.section("/", -1);
	if (!filePath.isEmpty())
	{
		QImage image(filePath);

		if (image.isNull())
		{
			QMessageBox::information(this, "Image Viewer", "Error Displaying image");
			return;
		}
		QGraphicsView* view = new QGraphicsView(&scene);
		image.setPixel(50, 50, qRgba(255, 255, 255,0));
	
		int w = image.width();
		ui.WidthLabel->setText(QString::number(w));

		int h = image.height();
		ui.HeightLabel->setText(QString::number(h));

		QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		item->setOpacity(1);
		scene.addItem(item);
		ui.testView->setScene(&scene);
//		undostack.push(scene);
	}
	ui.FileLabel->setText(fileName);
/*
	while (!redostack.empty()) {
		redostack.pop();
	}*/
}

void QTProject::brushcountfunc() {
	QString filePath = QFileDialog::getOpenFileName(this, "Open Image File", QDir::currentPath());
	QString fileName = filePath.section("/", -1);
	if (!filePath.isEmpty())
	{
		QImage image(filePath);

		if (image.isNull())
		{
			QMessageBox::information(this, "Image Viewer", "Error Displaying image");
			return;
		}
		QGraphicsView* view = new QGraphicsView(&scene);
		QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		item->setOpacity(0.7);
		scene.addItem(item);
		ui.testView->setScene(&scene);
//		undostack.push(scene);
	}
/*
	while (!redostack.empty()) {
		redostack.pop();
	}*/
}

void QTProject::closeClicked() {
	QMessageBox messagebox;
	messagebox.setText("Do you want to exit?");
	messagebox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	messagebox.setDefaultButton(QMessageBox::Ok);

	if (messagebox.exec() == QMessageBox::Ok)
	{
		this->close();
	}
}

void QTProject::imageCapture() {

}

void QTProject::DrawLine() {
	brushcount = 1;
}

void QTProject::DrawRect() {
	brushcount = 2;
}

void QTProject::DrawCir() {
	brushcount = 3;
}

void QTProject::drawEvent(QMouseEvent* mouse) {

}

void QTProject::imageSaveAs(){
	QPixmap buffer;
	QString filePath = imgSave.getSaveFileName(this, "Save Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);
	image.save(filePath);
	buffer = QPixmap::fromImage(image);
}

void QTProject::Newfile(){
//	ui.pictureDraw->setPixmap(newimg);
}

void QTProject::version(){
	QMessageBox::information(this, "Version", "Version : 0.0.1(Alpha)");
}

void QTProject::undo(){
/*	if (undostack.empty()) {
		QMessageBox::information(this, "none", "can't undo");
	}
	else {
		ui.testView->setScene(&undostack.top());
		redostack.push(undostack.top());
		undostack.pop();
	}*/
}

void QTProject::redo(){
/*	if (redostack.empty()) {
		QMessageBox::information(this, "none", "can't redo");
	}
	else {
		ui.testView->setScene(&redostack.top());
		undostack.push(redostack.top());
		redostack.pop();
	}*/
}

void QTProject::Screenshot() {

}

QTProject::~QTProject() {
	//delete ui;
}