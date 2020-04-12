#pragma once
#include "Qt.h"
#include "opencv.h"
#include "C++Header.h"

QBrush Pencolor = Qt::black;
qreal Pensize = 10;
bool drawRect = false;
bool drawCir = false;
bool areaSelect = false;
cv::Mat firstImage, secondImage;
cv::Mat firstImageRst, secondImageRst;
cv::Mat imageCloneOver;
cv::Mat imageClonePaint;
cv::Mat imageCloneOrigin;

int brushcount = 1;
int Colorselect = 1;
int redset = 0;
int greenset = 0;
int blueset = 0;
int cpX = -1;
int cpY = -1;
int areaX = -1;
int areaY = -1;

int copyHeightOrigin = 0;
int copyWidthOrigin = 0;

int copyHeightPaint = 0;
int copyWidthPaint = 0;

int copyHeightOver = 0;
int copyWidthOver = 0;

bool eraseSelect = false;

int eraseX = -1;
int eraseY = -1;

bool drawEllipse = false;
int ellipseX = -1;
int ellipseY = -1;

vector<Mat> createMat;
int createMatNumber = 0;

Mat undoClone;
stack<Mat> undoMat;

stack<Mat> redoMat;

int extractX = 0;
int extractY = 0;
