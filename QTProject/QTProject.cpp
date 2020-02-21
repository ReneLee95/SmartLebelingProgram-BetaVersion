#include "QTProject.h"

QTProject::QTProject(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);

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

	posX = QCursor::pos().x();
	posY = QCursor::pos().y();
	absX = QCursor::pos().x();
	absY = QCursor::pos().y();
	
	mouse_state = false;
	brushcount = 0;
	Pensize = 20;
	QBrush Pencolor = Qt::black;

	ui.PensizeLabel->setText(QString::number(Pensize));
}

void QTProject::colorBlackselect() {
	Pencolor = Qt::black;
}

void QTProject::colorBlueselect() {
	Pencolor = Qt::blue;
}

void QTProject::colorRedselect() {
	Pencolor = Qt::red;
}

void QTProject::fontsizeup() {
	Pensize++;
	ui.PensizeLabel->setText(QString::number(Pensize));
}

void QTProject::fontsizedown() {
	Pensize--;
	ui.PensizeLabel->setText(QString::number(Pensize));
}

void QTProject::mousePressEvent(QMouseEvent* mouse) {
	mouse_state = true;
}

void QTProject::mouseReleaseEvent(QMouseEvent* mouse) {
	mouse_state = false;
}

void QTProject::mouseMoveEvent(QMouseEvent* mouse) {
	ui.pictureDraw->setMouseTracking(true);
	QPainter painter;
	QPoint position = mouse->pos();
	posX = absX;
	posY = absY;
	absX = position.x();
	absY = position.y();

	if (mouse_state) {
		//update();
	}
	switch (brushcount) {
	case 1:
		update(posX, posY, Pensize, Pensize);
		break;
	case 2:
		update();
		break;
	case 3:
		update();
		break;
	default:
		break;
	}
}

void QTProject::paintEvent(QPaintEvent* event) {
	Q_UNUSED(event);
	QPainter painter(this);
	switch (brushcount) {
	case 1 :
		painter.begin(this);
		painter.setPen(QPen(Pencolor, 100, Qt::SolidLine, Qt::RoundCap));
		painter.drawLine(posX, posY, absX, absY);
		painter.end();
		break;
	case 2:
		painter.begin(this);
		painter.setPen(QPen(Pencolor, 10, Qt::SolidLine, Qt::RoundCap));
		painter.drawRect(posX, posY, 80, 60);
		painter.end();
		break;
	case 3:
		painter.begin(this);
		painter.setPen(QPen(Pencolor, 10, Qt::SolidLine, Qt::RoundCap));
		painter.drawEllipse(posX, posY, 80, 60);
		painter.end();
		break;
	default:
		break;
	}
}

void QTProject::imageOpen() {
	mutex.lock();
	QPixmap buffer;
	QString filePath = imgLoad.getOpenFileName(this, "Load Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);

	ui.FileLabel->setText(fileName);
	img.load(filePath);
	buffer = QPixmap::fromImage(img);

	ui.pictureDraw->setPixmap(buffer);
	
	int w = img.width();
	ui.WidthLabel->setText(QString::number(w));
	
	int h = img.height();
	ui.HeightLabel->setText(QString::number(h));
	
	undostack.push(buffer);
	
	ui.pictureDraw->setScaledContents(true);
	mutex.unlock();
}

void QTProject::brushcountfunc(){
	brushcount = 0;
}

void QTProject::closeClicked(){
	mutex.lock();
	QMessageBox messagebox;
	messagebox.setText("Do you want to exit?");
	messagebox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	messagebox.setDefaultButton(QMessageBox::Ok);

	if (messagebox.exec() == QMessageBox::Ok)
	{
		this->close();
	}
	mutex.unlock();
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
	mutex.lock();
	QPixmap buffer;
	QString filePath = imgSave.getSaveFileName(this, "Save Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);
//	image = imwrite("copy image",image);
	img.save(filePath);
	buffer = QPixmap::fromImage(img);
	ui.pictureDraw->setPixmap(buffer);
	undostack.push(buffer);
	ui.pictureDraw->setScaledContents(true);
	mutex.unlock();
}

void QTProject::Newfile(){
	ui.pictureDraw->setPixmap(newimg);
}

void QTProject::version(){
	QMessageBox::information(this, "Version", "Version : 0.0.1(Alpha)");
	qDebug() << brushcount;
}

void QTProject::undo(){
	if (undostack.empty()) {
		QMessageBox::information(this, "none", "can't undo");
	}
	else {
		ui.pictureDraw->setPixmap(undostack.top());
		redostack.push(undostack.top());
		undostack.pop();
	}
}

void QTProject::redo(){
	if (redostack.empty()) {
		QMessageBox::information(this, "none", "can't redo");
	}
	else {
		ui.pictureDraw->setPixmap(redostack.top());
		undostack.push(redostack.top());
		redostack.pop();
	}
}

void QTProject::Screenshot() {
	QPixmap buffer;
	QString filePath = imgSave.getSaveFileName(this, "Screenshot Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);

	img.save(filePath);
	buffer = QPixmap::fromImage(img);
	ui.pictureDraw->setPixmap(buffer);
	undostack.push(buffer);
	ui.pictureDraw->setScaledContents(true);
}