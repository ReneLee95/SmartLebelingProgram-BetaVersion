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
	connect(ui.pictureDraw, SIGNAL(Mouse_Pressed()), this, SLOT(DrawLine()));
	connect(ui.PaintButton, SIGNAL(clicked()), this, SLOT(brushcountfunc()));
	
	QMouseEvent* ev;
	posX = this->geometry().x();
	posY = this->geometry().y();
	absX = this->geometry().x();
	absY = this->geometry().y();
}
/*
void QTProject::mouseMoveEvent(QMouseEvent* mouse) {
	if (this->isMaximized() == true) return;

	if (mouse->button() == Qt::RightButton) return;

	posX = QCursor::pos().x();
	posY = QCursor::pos().y();

	if (oneclick == 0) {
		absX = mouse->pos().x() + 7;
		absY = mouse->pos().y() + 7;
		oneclick++;
	}
	this->move(posX - absX, posY - absY);
}

void QTProject::mouseRelease(QMouseEvent*) {
	oneclick = 0;
}
*/
void QTProject::imageOpen(){
	QString filePath = imgLoad.getOpenFileName(this, "Load Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");

	QString fileName = filePath.section("/", -1);
	ui.FileLabel->setText(fileName);
	img.load(filePath);

	ui.pictureDraw->setPixmap(img);
	int w = img.width();
	ui.WidthLabel->setText(QString::number(w));
	int h = img.height();
	ui.HeightLabel->setText(QString::number(h));
	undostack.push(img);
	ui.pictureDraw->setScaledContents(true);
}

void QTProject::brushcountfunc(){
	brushcount = 1;
}

void QTProject::closeClicked(){
	QMessageBox messagebox;
	messagebox.setText("Do you want to exit?");
	messagebox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	messagebox.setDefaultButton(QMessageBox::Ok);

	if (messagebox.exec() == QMessageBox::Ok)
	{
		this->close();
	}
}

void QTProject::imageCapture(){

}

void QTProject::paintEvent(QPaintEvent* event){
	Q_UNUSED(event);
	QPainter painter;
	QPen pen(Qt::black);
	posX = QCursor::pos().x();
	posY = QCursor::pos().y();
	painter.begin(this);

	painter.drawLine(80, 80, 100, 40);
	painter.end();
}

void QTProject::DrawLine(){
	QPainter painter;
	if (brushcount > 0) {
		if (MOUSEEVENTF_LEFTDOWN) {
			QPen pen(Qt::black);
			painter.begin(this);
			posX = QCursor::pos().x();
			posY = QCursor::pos().y();
			absX = posX - absX;
			absY = posY - absY;
			painter.drawLine(0, 0, 50, 50);
			painter.end();
		}
	}
}

void QTProject::imageSaveAs(){
	QString filePath = imgSave.getSaveFileName(this, "Save Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);
//	image = imwrite("copy image",image);
	img.save(filePath);

	ui.pictureDraw->setPixmap(img);
	undostack.push(img);
	ui.pictureDraw->setScaledContents(true);
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

void QTProject::Screenshot(){
	QString filePath = imgSave.getSaveFileName(this, "Screenshot Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);

	img.save(filePath);

	ui.pictureDraw->setPixmap(img);
	undostack.push(img);
	ui.pictureDraw->setScaledContents(true);
}