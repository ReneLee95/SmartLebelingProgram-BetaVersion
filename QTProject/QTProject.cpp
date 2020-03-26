#include "QTProject.h"
#include "Value.h"

QTProject::QTProject(QWidget* parent)
	: QMainWindow(parent) {
	ui.setupUi(this);
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(imageOpen()));
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
	connect(ui.AreaButton, SIGNAL(clicked()), this, SLOT(AreaButton()));
	connect(ui.EllipseButton, SIGNAL(clicked()), this, SLOT(Ellipse()));
	connect(ui.extractButton, SIGNAL(clicked()), this, SLOT(extract()));

	mouse_state = false;
	if (Colorselect == 0) {
		ui.Pencolor->setText("Erase");
	}
	ui.Penmode->setText("Line");
	ui.PensizeLabel->setText(QString::number(Pensize));
}

void QTProject::wheelEvent(QWheelEvent* event) {
	if (event->delta() > 0) {
		ui.testView->scale(1.25, 1.25);
	}
	else {
		ui.testView->scale(0.8, 0.8);
	}
}

void QTProject::colorBlackselect() {
	Pencolor = Qt::black;
	redset = 0;
	blueset = 0;
	greenset = 0;
	ui.Pencolor->setText("black");
}

void QTProject::colorBlueselect() {
	Pencolor = Qt::blue;
	blueset = 255;
	redset = 0;
	greenset = 0;
	ui.Pencolor->setText("blue");
}

void QTProject::colorRedselect() {
	Pencolor = Qt::red;
	redset = 255;
	blueset = 0;
	greenset = 0;
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

void swapNumber(int* a, int* b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
}

void createMatImage(Mat img) {
	img = createMat[createMatNumber];
	createMatNumber++;
}

void onMouseEvent(int event, int x, int y, int flags, void* param) {
	Mat mouseImage = *(Mat*)param;
	Scalar scolor;
	if (brushcount == 1) {
		switch (event) {
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				circle(mouseImage, Point(x, y), Pensize, Scalar(blueset, greenset, redset), -1);
			}
			break;
		case EVENT_LBUTTONUP:
			undoClone = secondImageRst.clone();
			undoMat.push(undoClone);
			undoCount++;
			break;
		}
		imshow(useMouse, mouseImage);
	}

	else if (brushcount == 2) {
		switch (event) {
		case EVENT_LBUTTONDOWN:
			drawRect = true;
			cpX = x;
			cpY = y;
			break;
		case EVENT_LBUTTONUP:
			if (drawRect == true) {
				if (x < cpX) {
					swapNumber(&x, &cpX);
				}
				if (y < cpY) {
					swapNumber(&y, &cpY);
				}
				rectangle(mouseImage, Point(cpX, cpY), Point(x, y), Scalar(blueset, greenset, redset), Pensize);
				undoClone = secondImageRst.clone();
				undoMat.push(undoClone);
				undoCount++;
			}
			break;
		}
		imshow(useMouse, mouseImage);
	}

	else if (brushcount == 3) {
		switch (event) {
		case EVENT_LBUTTONDOWN:
			drawCir = true;
			cpX = x;
			cpY = y;
			break;
		case EVENT_LBUTTONUP:
			if (drawCir == true) {
				if (x < cpX) {
					swapNumber(&x, &cpX);
				}
				if (y < cpY) {
					swapNumber(&y, &cpY);
				}
				if (x > (x + cpX)/2) {
					if (x < cpX) {
						swapNumber(&x, &cpX);
					}
					if (y < cpY) {
						swapNumber(&y, &cpY);
					}
					circle(mouseImage, Point((x + cpX) / 2, (y + cpY) / 2), x - ((x + cpX) / 2), Scalar(blueset, greenset, redset), Pensize);
				}
				else {
					circle(mouseImage, Point((x + cpX) / 2, (y + cpY) / 2), cpX - ((x + cpX) / 2), Scalar(blueset, greenset, redset), Pensize);
				}
				undoClone = secondImageRst.clone();
				undoMat.push(undoClone);
				undoCount++;
			}
			break;
		}
		imshow(useMouse, mouseImage);
	}

	else if (brushcount == -1) {
		if (!mouseImage.data) {
			QMessageBox messagebox;
			messagebox.setText("none image");
		}
		switch (event) {
		case EVENT_LBUTTONDOWN:
			areaSelect = true;
			areaX = x;
			areaY = y;
			break;
		case EVENT_LBUTTONUP:
			if (areaSelect == true) {
				if (x < areaX) {
					swapNumber(&x, &areaX);
				}
				if (y < areaY) {
					swapNumber(&y, &areaY);
				}
				Rect rect(areaX, areaY, x, y);

				Mat cutImage = mouseImage(rect);
				imshow("Cut Image", cutImage);
			}
			areaSelect = false;
			break;
		}
	}
	else if (brushcount == -2) {
		switch (event) {
		case EVENT_LBUTTONDOWN:
			eraseSelect = true;
			break;
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				if (eraseSelect == true) {
					eraseX = x;
					eraseY = y;
					for (int i = eraseX -Pensize; i < eraseX + Pensize; i++) {
						for (int j = eraseY - Pensize; j < eraseY + Pensize; j++) {
							if ((i > 0 && i < copyWidth) || (j > 0 && j < copyHeight)) {
								secondImageRst.at<Vec3b>(j, i)[0] = imageClone.at<Vec3b>(j, i)[0];
								secondImageRst.at<Vec3b>(j, i)[1] = imageClone.at<Vec3b>(j, i)[1];
								secondImageRst.at<Vec3b>(j, i)[2] = imageClone.at<Vec3b>(j, i)[2];
							}
						}
					}
				}
				undoClone = secondImageRst.clone();
				undoMat.push(undoClone);
				undoCount++;
			}
			break;
		case EVENT_LBUTTONUP:
			eraseSelect = false;
			imshow("result", secondImageRst);
			break;
		}
		imshow(useMouse, mouseImage);
	}

	else if (brushcount == -3) {
		if (event == EVENT_LBUTTONDOWN) {
			extractX = x;
			extractY = y;
			floodFill(mouseImage, Point(extractX, extractY), Scalar(blueset, greenset, redset));
		}
		imshow(useMouse, mouseImage);
	}
}

void QTProject::imageOpen() {
	QString filePath = QFileDialog::getOpenFileName(this, "Open Image File", QDir::currentPath());
	QString fileName = filePath.section("/", -1);


	string stdstring;

	stdstring = filePath.toStdString();

	firstImage = imread(stdstring, IMREAD_UNCHANGED);
	if (firstImage.empty()) {
		messagebox.setText("none image");
		return;
	}
	cv::resize(firstImage, firstImageRst, Size(512, 512), 0, 0, INTER_LINEAR);
	namedWindow("OriginImage");
	imshow("OriginImage", firstImageRst);
	int w = image.width();
	ui.WidthLabel->setText(QString::number(w));

	int h = image.height();
	ui.HeightLabel->setText(QString::number(h));
	ui.FileLabel->setText(fileName);

}

void QTProject::brushcountfunc() {
	QString filePath = QFileDialog::getOpenFileName(this, "Open Image File", QDir::currentPath());
	QString fileName = filePath.section("/", -1);

	string stdstring;

	stdstring = filePath.toStdString();

	secondImage = imread(stdstring, IMREAD_UNCHANGED);
	if (firstImage.empty() && secondImage.empty()) {
		messagebox.setText("none image");
		return;
	}
	cv::resize(secondImage, secondImageRst, Size(512, 512), 0, 0, INTER_LINEAR);
	namedWindow("PaintImage");
	imshow("PaintImage", secondImageRst);

	cv::addWeighted(firstImageRst, 0.8, secondImageRst, 0.6, 0, secondImageRst);
	namedWindow("result");
	imageClone = secondImageRst.clone();
	copyHeight = secondImageRst.rows;
	copyWidth = secondImageRst.cols;
	imshow("result", secondImageRst);
	setMouseCallback("OriginImage", onMouseEvent, (void*)& firstImageRst);
	setMouseCallback("PaintImage", onMouseEvent, (void*)& secondImageRst);
	setMouseCallback("result", onMouseEvent, (void*)& secondImageRst);
	undoClone = secondImageRst.clone();
	undoMat.push(undoClone);
	undoCount++;
}


void QTProject::closeClicked() {
	messagebox.setText("Do you want to exit?");
	messagebox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
	messagebox.setDefaultButton(QMessageBox::Ok);

	if (messagebox.exec() == QMessageBox::Ok)
	{
		this->close();
	}
}

void QTProject::AreaButton() {
	brushcount = -1;
}

void QTProject::Erase() {
	brushcount = -2;
	ui.Pencolor->setText("Erase");
}

void QTProject::extract() {
	brushcount = -3;
	ui.Pencolor->setText("Extract");
}

void QTProject::DrawLine() {
	brushcount = 1;
	ui.Penmode->setText("Line");
}

void QTProject::DrawRect() {
	brushcount = 2;
}

void QTProject::DrawCir() {
	brushcount = 3;
}

void QTProject::Ellipse() {
	brushcount = 4;
}


void QTProject::imageSaveAs(){

	QString filePath = imgSave.getSaveFileName(this, "Save Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);
	
	string stdstring;

	stdstring = filePath.toStdString();

	imwrite(stdstring, secondImageRst);
}

void QTProject::Newfile(){
	ui.testView->scene()->clear();
	ui.WidthLabel->setText("");
	ui.HeightLabel->setText("");
	ui.FileLabel->setText("");
}

void QTProject::version(){
	QMessageBox::information(this, "Version", "Version : 0.0.1(Alpha)");
}

void QTProject::undo(){
	if (undoMat.empty()) {
	QMessageBox::information(this, "none", "image none");
	}
	else {
		secondImageRst = undoMat.top();
		imshow("result", secondImageRst);
		redoMat.push(undoMat.top());
		undoMat.pop();
		undoCount--;
		redoCount++;
	}
}

void QTProject::redo(){
	if (redoMat.empty()) {
		QMessageBox::information(this, "none", "can't redo");
	}
	else {
		secondImageRst = redoMat.top();
		imshow("result", secondImageRst);
		undoMat.push(redoMat.top());
		redoMat.pop();
		redoCount--;
		undoCount++;
	}
}

void QTProject::Screenshot() {

}