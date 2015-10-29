#include "iattool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	IATTool w;
	w.show();
	return a.exec();
}
