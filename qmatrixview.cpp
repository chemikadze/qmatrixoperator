#include <algorithm>
#include "qmatrixview.h"

using std::min;

QMatrixView::QMatrixView(int rows, int cols, QWidget *parent):QTableWidget(rows, cols, parent)
{
	int i;
	matrix=NULL;
	clipMatrix=NULL;
	
	pMenu=new QMenu();
	actCopySelection=new QAction(Tr("Копировать выделенное"), this);
	actPaste=new QAction(Tr("Вставить"), this);
	actCopyAll=new QAction(Tr("Копировать полностью"), this);
	actPasteAll=new QAction(Tr("Вставить полностью"), this);
	actClearSelection=new QAction(Tr("Очистить выделенное"), this);
	actClearAll=new QAction(Tr("Очистить все"), this);
	
	QObject::connect(actCopySelection, SIGNAL(triggered()), this, SLOT(copySelection()));
	QObject::connect(actPaste, SIGNAL(triggered()), this, SLOT(paste()));
	QObject::connect(actCopyAll, SIGNAL(triggered()), this, SLOT(copyAll()));
	QObject::connect(actPasteAll, SIGNAL(triggered()), this, SLOT(pasteAll()));
	QObject::connect(actClearSelection, SIGNAL(triggered()), this, SLOT(clearSelection()));
	QObject::connect(actClearAll, SIGNAL(triggered()), this, SLOT(clearAll()));

	pMenu->addAction(actCopySelection);
	pMenu->addAction(actPaste);
	pMenu->addSeparator();
	pMenu->addAction(actCopyAll);
	pMenu->addAction(actPasteAll);
	pMenu->addSeparator();
	pMenu->addAction(actClearSelection);
	pMenu->addAction(actClearAll);
	
	for (i=0; i<columnCount(); i++)
                        setColumnWidth(i, defaultColWidth);
	setContextMenuPolicy(Qt::DefaultContextMenu);
}

QMatrixView::QMatrixView(QWidget *parent):QTableWidget(parent)
{
	int i;
	matrix=NULL;
	clipMatrix=NULL;
	
	pMenu=new QMenu();
	actCopySelection=new QAction(Tr("Копировать выделенное"), this);
	actPaste=new QAction(Tr("Вставить"), this);
	actCopyAll=new QAction(Tr("Копировать полностью"), this);
	actPasteAll=new QAction(Tr("Вставить полностью"), this);
	actClearSelection=new QAction(Tr("Очистить выделенное"), this);
	actClearAll=new QAction(Tr("Очистить все"), this);
	
	QObject::connect(actCopySelection, SIGNAL(triggered()), this, SLOT(copySelection()));
	QObject::connect(actPaste, SIGNAL(triggered()), this, SLOT(paste()));
	QObject::connect(actCopyAll, SIGNAL(triggered()), this, SLOT(copyAll()));
	QObject::connect(actPasteAll, SIGNAL(triggered()), this, SLOT(pasteAll()));
	QObject::connect(actClearSelection, SIGNAL(triggered()), this, SLOT(clearSelection()));
	QObject::connect(actClearAll, SIGNAL(triggered()), this, SLOT(clearAll()));

	
	setContextMenuPolicy(Qt::DefaultContextMenu);
	for (i=0; i<columnCount(); i++)
                        setColumnWidth(i, defaultColWidth);
}

void QMatrixView::setMatrix(Matrix *matr)
{
	matrix=matr;
}

void QMatrixView::setClipMatrix(ClipMatrix *matr)
{
	clipMatrix=matr;
}

void QMatrixView::refreshTable()
{
	QTableWidgetItem *tabItem;
	int i, j;
	int oldRowCount=rowCount();
	int oldColCount=columnCount();

	if (matrix != NULL)
	{
		setRowCount(matrix->size());
		if (oldRowCount!=rowCount())
			emit rowCountChanged(rowCount());
		if (matrix->size())
			 setColumnCount((*matrix)[0].size());
		else
			setColumnCount(0);
		if (oldColCount!=columnCount())
                        emit columnCountChanged(columnCount());
		for (i=0; i < matrix->size(); i++)
		{
			for (j=0; j < (*matrix)[0].size(); j++)
			{
				tabItem=item(i, j);
				if (tabItem==NULL)
				{
					tabItem=new QTableWidgetItem(QString().setNum((*matrix)[i][j]));
					setItem(i, j, tabItem);
				}
				else
					tabItem->setText(QString().setNum((*matrix)[i][j]));
				
			}
		}
	}
	for (i=0; i<columnCount(); i++)
                        setColumnWidth(i, defaultColWidth);
}

void QMatrixView::copySelection()
{
	int i;
	int startPX, startPY;
	if (clipMatrix == NULL || matrix==NULL)
		return;
	clipMatrix->indexes=selectedIndexes();
	clipMatrix->matrix=matrix;

	readMatrix();
	if (! selectedIndexes().size())
		return;
	
	startPX=clipMatrix->indexes[0].column();
	startPY=clipMatrix->indexes[0].row();
	for (i=1; i<clipMatrix->indexes.size(); i++)
	{
		startPX=min(startPX, clipMatrix->indexes[i].column());
		startPY=min(startPY, clipMatrix->indexes[i].row());
	}
	clipMatrix->startPoint=QPoint(startPX, startPY);
}

void QMatrixView::paste()
{
	if (clipMatrix == NULL || matrix==NULL || clipMatrix->matrix==NULL)
		return;
	int i;
	int itemAtR=rowAt(pMenuPosition.y());
	int itemAtC=columnAt(pMenuPosition.x());
	int oldR, oldC;
	int newR, newC;

	for (i=0; i < clipMatrix->indexes.size(); i++)
	{
		oldR=clipMatrix->indexes[i].row();
		oldC=clipMatrix->indexes[i].column();
		newR=oldR-clipMatrix->startPoint.y()+itemAtR;
		newC=oldC-clipMatrix->startPoint.x()+itemAtC;
		if (newR >= 0 && newR < matrix->size() && newC >= 0 && newC < (*matrix)[0].size() )
			(*matrix)[newR][newC]=(*clipMatrix->matrix)[oldR][oldC];
	}
	refreshTable();	
}

void QMatrixView::copyAll()
{
	if (clipMatrix==NULL || matrix==NULL)
		return;
	readMatrix();
	clipMatrix->matrix=matrix;
	clipMatrix->startPoint=QPoint(0, 0);
}

void QMatrixView::contextMenuEvent(QContextMenuEvent *event)
{
	pMenuPosition=event->pos();
	pMenu->exec(event->globalPos());
}

void QMatrixView::pasteAll()
{
	*matrix=*(clipMatrix->matrix);
	refreshTable();
}

void QMatrixView::clearSelection()
{
	int i;
	QTableWidgetItem *item;
	QModelIndexList list=selectedIndexes();
	for (i=0; i<list.size(); i++)
	{
		item=takeItem(list[i].row(), list[i].column());
		if (item!=NULL)
			 delete item;
		setItem(list[i].row(), list[i].column(), new QTableWidgetItem());
	}
}

void QMatrixView::clearAll()
{
	*matrix=newMatrix(rowCount(), columnCount());
	refreshTable();
}

void QMatrixView::readMatrix()
{
	QTableWidgetItem *tabItem;
	if (matrix==NULL)
		return;
	int i, j;
	setRowCount(matrix->size());
	if ((*matrix)[0].size())
		setColumnCount((*matrix)[0].size());
	else
	{
		setColumnCount(0);
		return;
	}
	for (i=0; i<matrix->size(); i++)
		for (j=0; j<(*matrix)[0].size(); j++)
		{
			tabItem=item(i, j);
			if (tabItem==NULL)
			{
				tabItem=new QTableWidgetItem;
				tabItem->setText("0");
				(*matrix)[i][j]=0;
				setItem(i, j, tabItem);
			}
			(*matrix)[i][j]=tabItem->text().toDouble();
		}
}
