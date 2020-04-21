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
	connect(ui.roiButton, SIGNAL(clicked()), this, SLOT(roiButton()));
	connect(ui.InputButton, SIGNAL(clicked()), this, SLOT(inputButton()));

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

void createMatImage(Mat img) {
	img = createMat[createMatNumber];
	createMatNumber++;
}

void swapNumber(int* a, int* b) {
	int* temp;
	temp = a;
	a = b;
	b = temp;
}

#if 1
void onMouseEvent(int event, int x, int y, int flags, void* param) {
	Mat mouseImage = *(Mat*)param;
	Scalar scolor;
	if (brushcount == 1) { //Line draw
		switch (event) {
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				circle(mouseImage, Point(x, y), Pensize, Scalar(blueset, greenset, redset), -1);
			}
			break;
		case EVENT_LBUTTONUP:
			undoClone = secondImageRst.clone();
			undoMat.push(undoClone);
			break;
		}
		imshow(useMouse, mouseImage);
	}

	else if (brushcount == 2) { //Rectangle draw
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
			}
			break;
		}
		imshow(useMouse, mouseImage);
	}

	else if (brushcount == 3) { //Circle draw
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
				if (x > (x + cpX) / 2) {
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
			}
			break;
		}
		imshow(useMouse, mouseImage);
	}

	else if (brushcount == -1) { //cut Image
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
				Rect cutrect(areaX, areaY, x, y);

				Mat cutImage = mouseImage(cutrect);
				imshow("Cut Image", cutImage);
			}
			areaSelect = false;
			break;
		}
	}
	else if (brushcount == -2) { //erase drawing
		switch (event) {
		case EVENT_LBUTTONDOWN:
			eraseSelect = true;
			break;
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				if (eraseSelect == true) {
					eraseX = x;
					eraseY = y;
					for (int i = eraseX - Pensize; i < eraseX + Pensize; i++) {
						if (eraseX - Pensize > 0 && eraseX + Pensize < copyWidthOver) {
							for (int j = eraseY - Pensize; j < eraseY + Pensize; j++) {
								if (eraseY - Pensize > 0 && eraseY + Pensize < copyHeightOver) {
									secondImageRst.at<Vec3b>(j, i)[0] = imageCloneOver.at<Vec3b>(j, i)[0];
									secondImageRst.at<Vec3b>(j, i)[1] = imageCloneOver.at<Vec3b>(j, i)[1];
									secondImageRst.at<Vec3b>(j, i)[2] = imageCloneOver.at<Vec3b>(j, i)[2];
								}
							}
						}
					}
				}
				undoClone = secondImageRst.clone();
				undoMat.push(undoClone);
			}
			break;
		case EVENT_LBUTTONUP:
			eraseSelect = false;
			imshow("result", secondImageRst);
			break;
		}
		imshow(useMouse, mouseImage);
	}
}
#endif

#if 1
void onMouseEventOrigin(int event, int x, int y, int flags, void* param) {
	Mat mouseImageOrigin = *(Mat*)param;
	Scalar scolor;
	if (brushcount == 1) { //Line draw
		switch (event) {
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				circle(mouseImageOrigin, Point(x, y), Pensize, Scalar(blueset, greenset, redset), -1);
			}
			break;
		}
		imshow("OriginImage", firstImage);
	}

	else if (brushcount == 2) { //Rectangle draw
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
				rectangle(mouseImageOrigin, Point(cpX, cpY), Point(x, y), Scalar(blueset, greenset, redset), Pensize);
			}
			break;
		}
		imshow("OriginImage", firstImage);
	}

	else if (brushcount == 3) { //Circle draw
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
				if (x > (x + cpX) / 2) {
					if (x < cpX) {
						swapNumber(&x, &cpX);
					}
					if (y < cpY) {
						swapNumber(&y, &cpY);
					}
					circle(mouseImageOrigin, Point((x + cpX) / 2, (y + cpY) / 2), x - ((x + cpX) / 2), Scalar(blueset, greenset, redset), Pensize);
				}
				else {
					circle(mouseImageOrigin, Point((x + cpX) / 2, (y + cpY) / 2), cpX - ((x + cpX) / 2), Scalar(blueset, greenset, redset), Pensize);
				}
			}
			break;
		}
		imshow("OriginImage", firstImage);
	}

	else if (brushcount == -1) { //cut Image
		if (!mouseImageOrigin.data) {
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

				Mat cutImage = mouseImageOrigin(rect);
				imshow("Cut Image (Origin)", cutImage);
			}
			areaSelect = false;
			break;
		}
	}
	else if (brushcount == -2) { //erase drawing
		switch (event) {
		case EVENT_LBUTTONDOWN:
			eraseSelect = true;
			break;
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				if (eraseSelect == true) {
					eraseX = x;
					eraseY = y;
					for (int i = eraseX - Pensize; i < eraseX + Pensize; i++) {
						if (eraseX - Pensize > 0 && eraseX + Pensize < copyWidthOrigin) {
							for (int j = eraseY - Pensize; j < eraseY + Pensize; j++) {
								if (j > 0 && j < copyHeightOrigin) {
									firstImage.at<Vec3b>(j, i)[0] = imageCloneOrigin.at<Vec3b>(j, i)[0];
									firstImage.at<Vec3b>(j, i)[1] = imageCloneOrigin.at<Vec3b>(j, i)[1];
									firstImage.at<Vec3b>(j, i)[2] = imageCloneOrigin.at<Vec3b>(j, i)[2];
								}
							}
						}
					}
				}
			}
			break;
		case EVENT_LBUTTONUP:
			eraseSelect = false;
			imshow("OriginImage", firstImage);
			break;
		}
		imshow("OriginImage", firstImage);
	}

	else if (brushcount == -3) { // floodFill image
		if (event == EVENT_LBUTTONDOWN) {
			extractX = x;
			extractY = y;
			//	floodFill(mouseImage, Point(extractX, extractY), Scalar(blueset, greenset, redset));
			floodFill(firstImageRst, Point(extractX, extractY), Scalar(blueset, greenset, redset));
			floodFill(secondImageRst, Point(extractX, extractY), Scalar(blueset, greenset, redset));
		}
		imshow("OriginImage", firstImage);
	}
}
#endif

#if 1
void onMouseEventPaint(int event, int x, int y, int flags, void* param) {
	Mat mouseImagePaint = *(Mat*)param;
	Scalar scolor;
	if (brushcount == 1) { //Line draw
		switch (event) {
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				circle(mouseImagePaint, Point(x, y), Pensize, Scalar(blueset, greenset, redset), -1);
			}
			break;
		}
		imshow("PaintImage", secondImage);
	}

	else if (brushcount == 2) { //Rectangle draw
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
				rectangle(mouseImagePaint, Point(cpX, cpY), Point(x, y), Scalar(blueset, greenset, redset), Pensize);
			}
			break;
		}
		imshow("PaintImage", secondImage);
	}

	else if (brushcount == 3) { //Circle draw
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
				if (x > (x + cpX) / 2) {
					if (x < cpX) {
						swapNumber(&x, &cpX);
					}
					if (y < cpY) {
						swapNumber(&y, &cpY);
					}
					circle(mouseImagePaint, Point((x + cpX) / 2, (y + cpY) / 2), x - ((x + cpX) / 2), Scalar(blueset, greenset, redset), Pensize);
				}
				else {
					circle(mouseImagePaint, Point((x + cpX) / 2, (y + cpY) / 2), cpX - ((x + cpX) / 2), Scalar(blueset, greenset, redset), Pensize);
				}
			}
			break;
		}
		imshow("PaintImage", secondImage);
	}

	else if (brushcount == -1) { //cut Image
		if (!mouseImagePaint.data) {
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

				Mat cutImage = mouseImagePaint(rect);
				imshow("Cut Image (secondImage)", cutImage);
			}
			areaSelect = false;
			break;
		}
	}
	else if (brushcount == -2) { //erase drawing
		switch (event) {
		case EVENT_LBUTTONDOWN:
			eraseSelect = true;
			break;
		case EVENT_MOUSEMOVE:
			if (flags & EVENT_LBUTTONDOWN) {
				if (eraseSelect == true) {
					eraseX = x;
					eraseY = y;
					for (int i = eraseX - Pensize; i < eraseX + Pensize; i++) {
						if (eraseX - Pensize > 0 && eraseX + Pensize < copyWidthOrigin) {
							for (int j = eraseY - Pensize; j < eraseY + Pensize; j++) {
								if (j > 0 && j < copyHeightPaint) {
									secondImage.at<Vec3b>(j, i)[0] = imageClonePaint.at<Vec3b>(j, i)[0];
									secondImage.at<Vec3b>(j, i)[1] = imageClonePaint.at<Vec3b>(j, i)[1];
									secondImage.at<Vec3b>(j, i)[2] = imageClonePaint.at<Vec3b>(j, i)[2];
								}
							}
						}
					}
				}
			}
			break;
		case EVENT_LBUTTONUP:
			eraseSelect = false;
			break;
		}
		imshow("PaintImage", secondImage);
	}

	else if (brushcount == -3) { // floodFill image
		if (event == EVENT_LBUTTONDOWN) {
			extractX = x;
			extractY = y;
			//	floodFill(mouseImage, Point(extractX, extractY), Scalar(blueset, greenset, redset));
			floodFill(firstImageRst, Point(extractX, extractY), Scalar(blueset, greenset, redset));
			floodFill(secondImageRst, Point(extractX, extractY), Scalar(blueset, greenset, redset));
		}
		imshow(useMouse, mouseImagePaint);
	}
}
#endif

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
	cv::resize(firstImage, firstImage, Size(512, 512), 0, 0, INTER_LINEAR);
	imageCloneOrigin = firstImage.clone();
	copyHeightOrigin = firstImage.rows;
	copyWidthOrigin = firstImage.cols;
	//namedWindow("OriginImage");
	imshow("OriginImage", firstImage);
	setMouseCallback("OriginImage", onMouseEventOrigin, (void*)& firstImage);
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
	cv::resize(secondImage, secondImage, Size(512, 512), 0, 0, INTER_LINEAR);
	imageClonePaint = secondImage.clone();
	copyHeightPaint = secondImage.rows;
	copyWidthPaint = secondImage.cols;
	imshow("PaintImage", secondImage);
	setMouseCallback("PaintImage", onMouseEventPaint, (void*)& secondImage);

	cv::addWeighted(firstImage, 0.8, secondImage, 0.6, 0, secondImageRst);
	imageCloneOver = secondImageRst.clone();
	copyHeightOver = secondImageRst.rows;
	copyWidthOver = secondImageRst.cols;
	imshow("result", secondImageRst);
	setMouseCallback("result", onMouseEvent, (void*)& secondImageRst);
	undoClone = secondImageRst.clone();
	undoMat.push(undoClone);

	ROIImage = Mat::zeros(imageCloneOver.rows, imageCloneOver.cols, CV_8UC3);
	setMouseCallback("roi", onMouseEvent, (void*)& ROIImage);
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
	ui.Penmode->setText("Erase");
}

void QTProject::extract() {
	//brushcount = -3;
	ui.Penmode->setText("ROI");
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

void QTProject::roiButton() {

	for (int i = 0; i <secondImageRst.cols; i++) {
		for (int j = 0; j < secondImageRst.rows; j++) {
//			cv::Vec3b OriginVec = firstImage.at<cv::Vec3b>(i, j);
//			cv::Vec3b PaintVec = secondImage.at<cv::Vec3b>(i, j);
			/*
			if (imageCloneOver.at<Vec3b>(i, j)[0] != secondImageRst.at<Vec3b>(i, j)[0] &&
				imageCloneOver.at<Vec3b>(i, j)[1] != secondImageRst.at<Vec3b>(i, j)[1] &&
				imageCloneOver.at<Vec3b>(i, j)[2] != secondImageRst.at<Vec3b>(i, j)[2]) {
				ROIImage.at<Vec3b>(i, j)[0] = 50;
				ROIImage.at<Vec3b>(i, j)[1] = 100;
				ROIImage.at<Vec3b>(i, j)[2] = 150;
			}
			*/

			if ((ROIImage.at<Vec3b>(i, j)[0] != 0 || ROIImage.at<Vec3b>(i, j)[1] != 0 || ROIImage.at<Vec3b>(i, j)[2] != 0)
				&&(imageCloneOver.at<Vec3b>(i, j)[0] ==0 || imageCloneOver.at<Vec3b>(i, j)[1] ==0 || imageCloneOver.at<Vec3b>(i, j)[2] ==0 )){
				ROIImage.at<Vec3b>(i, j)[0] = 50;
				ROIImage.at<Vec3b>(i, j)[1] = 100;
				ROIImage.at<Vec3b>(i, j)[2] = 150;

				secondImageRst.at<Vec3b>(i, j) = ROIImage.at<Vec3b>(i, j);
			}
			/*
			if (ROIImage.at<Vec3b>(i, j) != secondImageRst.at<Vec3b>(i, j)) {
				ROIImage.at<Vec3b>(i, j)[0] = imageCloneOver.at<Vec3b>(i, j)[0];
				ROIImage.at<Vec3b>(i, j)[1] = imageCloneOver.at<Vec3b>(i, j)[1];
				ROIImage.at<Vec3b>(i, j)[2] = imageCloneOver.at<Vec3b>(i, j)[2];
			}
			secondImageRst.at<Vec3b>(i, j) = ROIImage.at<Vec3b>(i, j);
			*/
		}
	}

	QFileDialog ROIsave;
	QString filePath = ROIsave.getSaveFileName(this, "ROI Image", "", "Image Files(*.png *.jpg *.bmp *.raw)");
	QString fileName = filePath.section("/", -1);

	string stdstring;

	stdstring = filePath.toStdString();

	imwrite(stdstring, secondImageRst);
}


void QTProject::inputButton() {
	QString filePath = QFileDialog::getOpenFileName(this, "Open Image File", QDir::currentPath());
	QString fileName = filePath.section("/", -1);
	Mat inputImage;

	string stdstring;

	stdstring = filePath.toStdString();

	inputImage = imread(stdstring, IMREAD_UNCHANGED);

	cv::addWeighted(secondImageRst, 0.5, inputImage, 0.5, 0, secondImageRst);
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
	QMessageBox::information(this, "Version", "Version : 0.1(Alpha)");
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
	}
}

void QTProject::Screenshot() {

}