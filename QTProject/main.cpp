#include "QTProject.h"
#include <QtWidgets/QApplication>

using namespace std;
using namespace cv::dnn;
using namespace cv;

int main(int argc, char *argv[]) {

	QApplication a(argc, argv);
	QTProject w;
	w.show();
	a.exec();

	return 0;
}
