#pragma once
#include "Qt.h"
#include "opencv.h"

QBrush Pencolor = Qt::black;
qreal Pensize = 10;
bool drawRect = false;
bool drawCir = false;
bool areaSelect = false;
cv::Mat firstImage, secondImage;
cv::Mat firstImageRst, secondImageRst;
cv::Mat imageClone;

int brushcount = 1;
int Colorselect = 1;
int redset = 0;
int greenset = 0;
int blueset = 0;
int cpX = -1;
int cpY = -1;
int areaX = -1;
int areaY = -1;

int copyHeight = 0;
int copyWidth = 0;
bool eraseSelect = false;

int eraseX = -1;
int eraseY = -1;