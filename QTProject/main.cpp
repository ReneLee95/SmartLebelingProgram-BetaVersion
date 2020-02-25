#include "QTProject.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	QTProject w;
	w.show();
	return a.exec();
}
