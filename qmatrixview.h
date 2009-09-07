#ifndef _QMATRIXVIEW_H
#define _QMATRIXVIEW
#include <QtGui>
#include <QtCore>
#include "matrix.h"

#define Tr(X) QObject::tr(X)

struct ClipMatrix
{
	QPoint startPoint;
	QModelIndexList indexes;
	Matrix *matrix;
};

class  QMatrixView: public QTableWidget
{
	Q_OBJECT

	static const int defaultColWidth=80;
	
	QPoint pMenuPosition;	
	Matrix *matrix;
	ClipMatrix *clipMatrix;

	QMenu *pMenu;
	QAction *actCopySelection;
	QAction *actPaste;

	QAction *actCopyAll;
	QAction *actPasteAll;

	QAction *actClearSelection;
	QAction *actClearAll;

 private:
	void contextMenuEvent(QContextMenuEvent *event);

 signals:
	void rowCountChanged(int rows);
	void columnCountChanged(int cols);

 public slots:
	void copySelection();
	void paste();

	void copyAll();
	void pasteAll();
	
	void clearSelection();
	void clearAll();

 public:
	void setMatrix(Matrix *matr);
	void setClipMatrix(ClipMatrix *matr);
	void refreshTable();
	void readMatrix();

	QMatrixView(QWidget *parent=0);
	QMatrixView(int rows, int cols, QWidget *parent=0);
};

//<< Tr("Копировать выделенное") << Tr("Вставить") << Tr("Копировать таблицу") << Tr("Вставить таблицу") << Tr("Очистить выделенное") << Tr("Очистить все");

#endif
