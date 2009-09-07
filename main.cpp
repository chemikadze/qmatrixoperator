#include "form.h"
// from "form.h"
//#include <QtCore>
//#include <QtGui>

int main(int argc, char **argv)
{
	QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));
	QApplication app(argc, argv);
	MatrixForm form;

	form.show();
	return app.exec();
}
