#ifndef _FORM_H
#define _FORM_H
#include <QtGui>
#include <QtCore>
#include "matrix.h"
#include "qmatrixview.h"

#define BUILD "0.1.5"
#define _TOOLBOX

const QString defaultFileName("noname.qmo");

class MatrixForm:public QMainWindow
{
	static const int beginSize=3;
	static const int defaultColWidth=75;

	Q_OBJECT
	int NA, MA;
	int NB, MB;
	int I, J;
	QString fileName;
	QGridLayout la;
	ClipMatrix *clipMatrix;
	QVector < Matrix > matrixes; // at -- обратная; b -- a+at+a*at
	void setTextToItem(QTableWidget* widget, int i, int j, QString &s);
	void updateWindowTitle();
	void writeData();

 public slots:
	void resizeMatrixNA(int n);
	void resizeMatrixMA(int m);
	void resizeMatrixNB(int n);
	void resizeMatrixMB(int m);
	void calculateMatrix();
	void aboutQt();
	void fileNew();
	void clearAll();
	void fileOpen();
	void fileSave();
	void fileSaveAs();
	void aboutThis();

 public:
	double det;
	double algebraicAddition;

	QLabel *naLabel;
	QLabel *maLabel;
	QSpinBox *naBox;
	QSpinBox *maBox;
	QLabel *nbLabel;
	QLabel *mbLabel;
	QSpinBox *nbBox;
	QSpinBox *mbBox;
	QLabel *iLabel;
	QLabel *jLabel;
	QSpinBox *iBox;
	QSpinBox *jBox;
	QPushButton *calcButton;
	QMatrixView *numericTable;
	QVector <QString> names;
	QVector <QMatrixView*> tables;
	QMenu *runMenu;
	QMenu *fileMenu;
	QMenu *helpMenu;
	QToolBar *fileTool, *runTool;
	
	QAction *actFileNew;
	QAction *actClearAll;
	QAction *actFileOpen;
	QAction *actFileSave;
	QAction *actFileSaveAs;
	QAction *actExit;
	QAction *actAboutThis;
	QAction *actAboutQt;
		
	QAction *actRun;

	QWidget *ui;
	// ("Матрица A") ("Матрица В") ("Транспонированная матрица At") ("Союзная матрица A*") ("Обратная матрица A^-1") ("Минор Mij") ("Сумма матриц A+B") ("Произведение матриц A*B")
#ifdef _TOOLBOX
	QToolBox *answers;
#else
	QTabWidget *answers;
#endif

	MatrixForm(QWidget *parent=0);
	//~MatrixForm();
};

#endif
