#include "QTProject.h"

QBrush Pencolor = Qt::black;
qreal Pensize = 5;

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

	//ui.pictureDraw->setStyleSheet("background-color: rgba(255,255,255,10%)")

	posX = QCursor::pos().x();
	posY = QCursor::pos().y();
	absX = QCursor::pos().x();
	absY = QCursor::pos().y();

	mouse_state = false;
	brushcount = 0;
	Colorselect = 0;

	ui.PensizeLabel->setText(QString::number(Pensize));
	ui.testView->setAttribute(Qt::WA_TranslucentBackground, false);
	ui.testView2->setAttribute(Qt::WA_TranslucentBackground, true);
	newScene();
}

void QTProject::newScene() {
	if (ui.testView->scene()) ui.testView->scene()->deleteLater();
	ui.testView->setScene(new Scene);
	ui.testView->scene()->connect(&m_join, SIGNAL(toggled(bool)), SLOT(setJoinFigures(bool)));

	if (ui.testView2->scene()) ui.testView2->scene()->deleteLater();
	ui.testView2->setScene(new Scene);
	ui.testView2->scene()->connect(&m_join, SIGNAL(toggled(bool)), SLOT(setJoinFigures(bool)));

	ui.testView->setBackgroundBrush(QColor(0, 0, 0, 150));
}

void QTProject::Paint() {
	brushcount = 100;
//	m_graphScene->addLine(0,0,42,42, QPen(QBrush(Qt::black), 1));
//	ui.testView->show();
}

void QTProject::Erase() {
	Colorselect = 0;
	brushcount = 0;
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

/*
void QTProject::mousePressEvent(QGraphicsSceneMouseEvent* mouse) {
	
	mouse_state = true;
}

void QTProject::mouseReleaseEvent(QGraphicsSceneMouseEvent* mouse) {

	mouse_state = false;
}

void QTProject::mouseMoveEvent(QGraphicsSceneMouseEvent* mouse) {
	ui.pictureDraw->setMouseTracking(true);
	QPainter painter;
	QPointF position = mouse->scenePos();
	posX = absX;
	posY = absY;
	absX = position.x();
	absY = position.y();

	if (mouse_state) {
		//update();
	}
	switch (brushcount) {
	case 0:
		update(posX, posY, Pensize, Pensize);
	case 1:
		update(posX, posY, Pensize, Pensize);
		break;
	case 2:
		update();
		break;
	case 3:
		update();
		break;
	case 100:
		update(20, 20, 500, 500);
	default:
		break;
	}
	
}*/

void QTProject::paintEvent(QPaintEvent* event) {	
	/*
	Q_UNUSED(event);
	QPainter painter(ui.testView);
	switch (brushcount) {
	case 0 :
		painter.begin(ui.testView);
		painter.setPen(Qt::gray);
		painter.eraseRect(posX, posY, absX, absY);
		painter.end();
		break;
	case 1 :
		painter.begin(ui.testView);
//		painter.setPen(QPen(Pencolor, 100, Qt::SolidLine, Qt::RoundCap));
		painter.drawLine(posX, posY, absX, absY);
		painter.end();
		break;
	case 2:
		painter.begin(this);
		painter.setPen(QPen(Pencolor, 10));
		painter.drawRect(posX, posY, 80, 60);
		painter.end();
		break;
	case 3:
		painter.begin(this);
		painter.setPen(QPen(Pencolor, 10));
		painter.drawEllipse(posX, posY, 80, 60);
		painter.end();
		break;
	case 100:
		//painter.drawImage(img);
	default:
		break;
	}
	*/
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
		QGraphicsScene* scene = new QGraphicsScene();
		QGraphicsView* view = new QGraphicsView(scene);
		image.setPixel(50, 50, qRgba(255, 255, 255, 255));
		QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		scene->addItem(item);
		ui.testView->setScene(scene);
		ui.testView->setWindowOpacity(0.2);
	}
	ui.FileLabel->setText(fileName);

	int w = image.width();
	ui.WidthLabel->setText(QString::number(w));
	
	int h = image.height();
	ui.HeightLabel->setText(QString::number(h));
	
	undostack.push(buffer);
	while (!redostack.empty()) {
		redostack.pop();
	}

//	ui.pictureDraw->setScaledContents(true);
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
		QGraphicsScene* scene = new QGraphicsScene();
		QGraphicsView* view = new QGraphicsView(scene);
		image.setPixel(50, 50, qRgba(255, 255, 255, 30));
		QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
		scene->addItem(item);
		ui.testView->setScene(scene);
	}
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
/*	if (mouse_state) {
		posX = absX;
		posY = absY;

		absX = mouse->x();
		absY = mouse->y();

		QPainter painter(this);
		painter.setPen(QPen(Qt::black, 12, Qt::SolidLine, Qt::RoundCap));
		painter.drawLine(posX, posY, absX, absY);
		update();
	}*/
}

void QTProject::imageSaveAs(){
	QPixmap buffer;
	QString filePath = imgSave.getSaveFileName(this, "Save Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);
//	image = imwrite("copy image",image);
	image.save(filePath);
	buffer = QPixmap::fromImage(image);
//	ui.pictureDraw->setPixmap(buffer);
	undostack.push(buffer);
//	ui.pictureDraw->setScaledContents(true);
}

void QTProject::Newfile(){
//	ui.pictureDraw->setPixmap(newimg);
}

void QTProject::version(){
	QMessageBox::information(this, "Version", "Version : 0.0.1(Alpha)");
}

void QTProject::undo(){
	if (undostack.empty()) {
		QMessageBox::information(this, "none", "can't undo");
	}
	else {
	//	ui.pictureDraw->setPixmap(undostack.top());
		redostack.push(undostack.top());
		undostack.pop();
	}
}

void QTProject::redo(){
/*	if (redostack.empty()) {
		QMessageBox::information(this, "none", "can't redo");
	}
	else {
		ui.pictureDraw->setPixmap(redostack.top());
		undostack.push(redostack.top());
		redostack.pop();
	}*/
}

void QTProject::Screenshot() {

}

QTProject::~QTProject() {
	//delete ui;
}