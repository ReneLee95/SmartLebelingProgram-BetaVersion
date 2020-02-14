#include "QTProject.h"

QTProject::QTProject(QWidget *parent)
	: QMainWindow(parent){
	ui.setupUi(this);

	setWindowFlags(Qt::CustomizeWindowHint);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(brushClicked()));
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

	posX = 0;
	posY = 0;
	absX = 0;
	absY = 0;
	brushcount = 0;
}

void QTProject::brushClicked(){
	QString filePath = imgLoad.getOpenFileName(this, "Load Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");

	QString fileName = filePath.section("/", -1);
	img.load(filePath);
//	image = imread(filePath.toStdString());

	ui.pictureDraw->setPixmap(img);
//	imshow("Load Image", image);
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
	QPen pen(Qt::red);
	posX = QCursor::pos().x();
	posY = QCursor::pos().y();
	if (brushcount == 1)
	{
		if (MKF_LEFTBUTTONDOWN)
		{
			painter.begin(this);    // start drawing

			painter.setPen(Qt::blue);
			painter.drawLine(posX, posY, posX+10, posY+10);  // line
			painter.drawRect(120, 10, 80, 80);  // rectangle
			QRectF rect(230.0, 10.0, 80.0, 80.0);
			pen.setWidth(4);
			painter.setPen(pen);
			painter.drawRoundedRect(rect, 20, 20);  // rounded rectangle
			painter.end();      // close Paint device
			update();
		}
	}
}

void QTProject::DrawLine(){
	QPainter painter;
	if (brushcount > 0)
	{
		if (MOUSEEVENTF_LEFTDOWN)
		{
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
	if (undostack.empty())
	{
		QMessageBox::information(this, "none", "can't undo");
	}
	else
	{
		ui.pictureDraw->setPixmap(undostack.top());
		redostack.push(undostack.top());
		undostack.pop();
	}
}

void QTProject::redo(){
	if (redostack.empty())
	{
		QMessageBox::information(this, "none", "can't redo");
	}
	else
	{
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