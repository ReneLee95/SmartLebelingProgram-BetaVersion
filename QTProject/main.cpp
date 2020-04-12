#include "QTProject.h"
#include <QtWidgets/QApplication>

using namespace std;

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	QTProject w;
	w.show();
	a.exec();

	return 0;
}
