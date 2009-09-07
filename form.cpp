#include "form.h"
#include <algorithm>
#include <cstdio>
#define Tr(X) QObject::tr(X) 
using std::max;

MatrixForm::MatrixForm(QWidget *parent/*=0*/)
{
	Q_UNUSED(parent)

	int i;
	QStringList slist;

	MA=NA=MB=NB=beginSize;
	I=J=1;
	fileName="";
	clipMatrix=new ClipMatrix;
	naLabel=new QLabel(Tr("Кол-во строк A"));
	maLabel=new QLabel(Tr("Кол-во столбцов A"));
	naBox=new QSpinBox();
	naBox->setRange(1, 10);
	naBox->setValue(beginSize);
	maBox=new QSpinBox();
	maBox->setRange(1, 10);
	maBox->setValue(beginSize);
	nbLabel=new QLabel(Tr("Кол-во строк B"));
	mbLabel=new QLabel(Tr("Кол-во столбцов B"));
	nbBox=new QSpinBox();
	nbBox->setRange(1, 10);
	nbBox->setValue(beginSize);
	mbBox=new QSpinBox();
	mbBox->setRange(1, 10);
	mbBox->setValue(beginSize);
	QObject::connect(naBox, SIGNAL(valueChanged(int)), this, SLOT(resizeMatrixNA(int)));
	QObject::connect(maBox, SIGNAL(valueChanged(int)), this, SLOT(resizeMatrixMA(int)));
	QObject::connect(nbBox, SIGNAL(valueChanged(int)), this, SLOT(resizeMatrixNB(int)));
	QObject::connect(mbBox, SIGNAL(valueChanged(int)), this, SLOT(resizeMatrixMB(int)));
	iLabel=new QLabel(Tr("Номер строки i"));
	jLabel=new QLabel(Tr("Номер столбца j"));
	iBox=new QSpinBox();
	iBox->setRange(1, beginSize);
	iBox->setValue(1);
	jBox=new QSpinBox();
	jBox->setRange(1, beginSize);
	jBox->setValue(1);

	calcButton=new QPushButton(Tr("&Вычислить"));
	QObject::connect(calcButton, SIGNAL(clicked()), this, SLOT(calculateMatrix()));

	names << Tr("Матрица A") << Tr("Матрица В") << Tr("Транспонированная матрица At") << Tr("Союзная матрица A*") << Tr("Обратная матрица A^-1") << Tr("Минор Mij") << Tr("Сумма матриц A+B") << Tr("Произведение матриц A*B") << Tr("Решение СЛАУ матричным методом");
	slist << Tr("Определитель") << Tr("Aij");

	matrixes.insert(0, names.size(), newMatrix(beginSize, beginSize));
	numericTable=new QMatrixView(1, 2);
	numericTable->setHorizontalHeaderLabels(slist);
	numericTable->setFixedHeight(numericTable->rowHeight(0)*2);

	fileMenu=this->menuBar()->addMenu(Tr("Файл"));
	runMenu=this->menuBar()->addMenu(Tr("Вычислить"));		
	helpMenu=this->menuBar()->addMenu(Tr("Помощь"));
	
	fileTool=addToolBar(Tr("Файл"));
	runTool=addToolBar(Tr("Вычислить"));
	actFileNew=new QAction(QIcon(":/document-new.png"), Tr("Новый расчет"), fileMenu);
	actClearAll=new QAction(QIcon(":/edit-clear.png"), Tr("Очистить все"), fileMenu);
	actFileOpen=new QAction(QIcon(":/document-open.png"), Tr("Открыть расчет..."), fileMenu);
	actFileSave=new QAction(QIcon(":/document-save.png"), Tr("Сохранить"), fileMenu);
	actFileSaveAs=new QAction(QIcon(":/document-save-as.png"), Tr("Сохранить как..."), fileMenu);
	actRun=new QAction(QIcon(":/arrow-right-double.png"), Tr("Вычислить"), runMenu);
	actExit=new QAction(QIcon(":/application-exit.png"), Tr("Выход"), fileMenu);
	actAboutThis=new QAction(QIcon(":/help-about.png"), Tr("О программе..."), helpMenu);
	actAboutQt=new QAction(Tr("О Qt..."), helpMenu);

	fileMenu->addAction(actFileNew);
	fileMenu->addAction(actClearAll);
	fileMenu->addSeparator();
	//fileMenu->addAction(actFileOpen);
	fileMenu->addAction(actFileSave);
	fileMenu->addAction(actFileSaveAs);
	fileMenu->addSeparator();
	fileMenu->addAction(actExit);
	runMenu->addAction(actRun);
	helpMenu->addAction(actAboutThis);
	helpMenu->addAction(actAboutQt);
	fileTool->addAction(actFileNew);
	fileTool->addSeparator();
	//fileTool->addAction(actFileOpen);
	fileTool->addAction(actFileSave);
	fileTool->addAction(actFileSaveAs);
	runTool->addAction(actRun);
	connect(actFileNew, SIGNAL(triggered()), this, SLOT(fileNew()));
	connect(actClearAll, SIGNAL(triggered()), this, SLOT(clearAll()));
	//connect(actFileOpen, SIGNAL(triggered()), this, SLOT(fileOpen()));
	connect(actFileSave, SIGNAL(triggered()), this, SLOT(fileSave()));
	connect(actFileSaveAs, SIGNAL(triggered()), this, SLOT(fileSaveAs()));
	connect(actAboutThis, SIGNAL(triggered()), this, SLOT(aboutThis()));
	connect(actExit, SIGNAL(triggered()), this, SLOT(close()));
	connect(actRun, SIGNAL(triggered()), this, SLOT(calculateMatrix()));
	connect(actAboutQt, SIGNAL(triggered()), this, SLOT(aboutQt()));

	tables.resize(names.size());
	tables[0]=new QMatrixView(beginSize, beginSize);
	tables[1]=new QMatrixView(beginSize, beginSize);
	tables[0]->setMatrix(&matrixes[0]);
	tables[0]->setClipMatrix(clipMatrix);
	tables[1]->setMatrix(&matrixes[1]);
	tables[1]->setClipMatrix(clipMatrix);
	QObject::connect(tables[0], SIGNAL(rowCountChanged(int)), naBox, SLOT(setValue(int)));
	QObject::connect(tables[0], SIGNAL(columnCountChanged(int)), maBox, SLOT(setValue(int)));
	QObject::connect(tables[1], SIGNAL(rowCountChanged(int)), nbBox, SLOT(setValue(int)));
	QObject::connect(tables[1], SIGNAL(columnCountChanged(int)), mbBox, SLOT(setValue(int)));
#ifdef _TOOLBOX
 	answers=new QToolBox();	
	answers->insertItem(0, numericTable, Tr("Определитель и алгебраическое дополнение"));
	for (i=2; i<names.size(); i++)
	{
		tables[i]=new QMatrixView(beginSize, beginSize);
		tables[i]->setMatrix(&matrixes[i]);
		tables[i]->setClipMatrix(clipMatrix);
		answers->addItem(tables[i], names[i]);
	}
#else
	answers=new QMatrixView();
	for (i=2; i<names.size(); i++)
	{
		tables[i]=new QTableWidget(beginSize, beginSize);
		tables[i]->setMatrix(&matrixes[i]);
		tables[i]->setClipMatrix(clipMatrix);
		answers->addTab(tables[i], names[i]);
	}
#endif
	numericTable->setColumnWidth(0, defaultColWidth*3/2);
	numericTable->setColumnWidth(1, defaultColWidth*3/2);
	numericTable->setGridStyle(Qt::NoPen);
	//la=new QGridLayout();
	la.addWidget(naLabel, 0, 0);	
	la.addWidget(maLabel, 0, 1);
	la.addWidget(nbLabel, 0, 2);
	la.addWidget(mbLabel, 0, 3);
	la.addWidget(iLabel, 2, 0);
	la.addWidget(jLabel, 2, 1);
	la.addWidget(naBox, 1, 0);
	la.addWidget(maBox, 1, 1);
	la.addWidget(nbBox, 1, 2);
	la.addWidget(mbBox, 1, 3);
	la.addWidget(iBox, 3, 0);
	la.addWidget(jBox, 3, 1);
	la.addWidget(calcButton, 3, 2, 1, 2);
	la.addWidget(tables[0], 4, 0, 2, 2);
	la.addWidget(tables[1], 4, 2, 2, 2);
	la.addWidget(answers, 4-4, 4, 2+4, 2);

	for (i=0; i<6; i++)
		la.setRowStretch(i, i>4);	

	ui=new QWidget();
	ui->setLayout(&la);
	this->setCentralWidget(ui);
	updateWindowTitle();
}

void MatrixForm::resizeMatrixNA(int n)
{
	NA=n;
	iBox->setMaximum(NA);
	resizeMatrix(matrixes[0], NA, MA);
	tables[0]->setRowCount(NA);
}

void MatrixForm::resizeMatrixMA(int m)
{
	MA=m;
	jBox->setMaximum(MA);
	resizeMatrix(matrixes[0], NA, MA);
	tables[0]->setColumnCount(MA);
}

void MatrixForm::resizeMatrixNB(int n)
{
	NB=n;
	resizeMatrix(matrixes[1], NB, MB);
	tables[1]->setRowCount(NB);
}

void MatrixForm::resizeMatrixMB(int m)
{
	MB=m;
	resizeMatrix(matrixes[1], NB, MB);
	tables[1]->setColumnCount(MB);
}

void MatrixForm::setTextToItem(QTableWidget* widget, int i, int j, QString &s)
{
        QTableWidgetItem *item=widget->item(i, j);
        if (item==NULL)
        {
                item=new QTableWidgetItem();
                item->setText(s);
                widget->setItem(i, j, item);
        }
        else
                item->setText(s);
}

void MatrixForm::calculateMatrix()
{
	int i;

	if ((matrixes[0].size()==1 && matrixes[0][0].size()==1) || (matrixes[1].size()==1 && matrixes[1][0].size()==1))
	{	
		QMessageBox message;
		message.setText(Tr("В матрице должно быть больше одного элемента!"));
		message.setStandardButtons(QMessageBox::Ok);
		message.exec();
		return;
	}
	for (i=0; i<2; i++)
		tables[i]->readMatrix();	
	I=iBox->value()-1;
	J=jBox->value()-1;

	matrixTransposing(matrixes[0], matrixes[2]);
	matrixFriendly(matrixes[0], matrixes[3]);
	matrixAntipod(matrixes[0], matrixes[4]);
	matrixMinor(matrixes[0], I, J, matrixes[5]);
	matrixSum(matrixes[0], matrixes[1], matrixes[6]);
	matrixMultiply(matrixes[0], matrixes[1], matrixes[7]);
	solveLinearSystemMatrix(matrixes[0], matrixes[1], matrixes[8]);
	det=matrixDet(matrixes[0]);
	algebraicAddition=matrixAlgebraicAddition(matrixes[0], I, J);
	setTextToItem(numericTable, 0, 0,  QString().setNum(det));
	setTextToItem(numericTable, 0, 1,  QString().setNum(algebraicAddition));

	for (i=0; i<tables.count(); i++)
		tables[i]->refreshTable();
}

void MatrixForm::aboutQt()
{
	QApplication::aboutQt();
}

void MatrixForm::fileNew()
{
	fileName="";
	clearAll();
	updateWindowTitle();
}

void MatrixForm::updateWindowTitle()
{
	setWindowTitle(Tr("QMatrixOperator "BUILD" | ")+((fileName=="")?(defaultFileName):(fileName)));
}

void MatrixForm::clearAll()
{
	int i;
	for (i=0; i<tables.size(); i++)
	{
		matrixes[i]=newMatrix(matrixes[i].size(), matrixes[i][0].size());
		tables[i]->refreshTable();
	}
}

void MatrixForm::fileOpen()
{/*
	QString openFileName=QNameDialog::getOpenFileName();
	if (getOpenFileName=="")
		return;

	int matrI;
	int i, j;
	QString buffer;
	QFile file(openFileName);
	QString numStr;
	QByteArray str;
	QByteArray::iterator itb, ite;
	
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		QMessageBox::critical(this, Tr("Не могу открыть файл "+openFileName+Tr("для чтения!")), Tr("Ошибка открытия файла"));
		return;
	}
	for (matrI=0; matrI<matrixes.size(); matrI++)
	{
		file.readLine();
		str=file.readLine();
		for (itb=ite=str.begin(); itb<str.end();)
		{
			while ( *itb != ' ' && *itb != '\n' )
				itb++;
			
		}
	}*/
}

void MatrixForm::writeData()
{
	int matrI, i, j;
	QString buffer;	
	QFile file(fileName);
	
	if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
	{
		QMessageBox::critical(this, Tr("Не могу открыть файл ")+fileName+Tr(" для сохранения"), Tr("Ошибка открытия файла"));
		return;
	}
	for (matrI=0; matrI<matrixes.size(); matrI++)
	{
		for (i=0, file.write(QString(names[matrI]+"\n").toLocal8Bit()); i<matrixes[matrI].size(); i++, file.write("\n"))
			for (j=0; j<matrixes[0].size(); j++)
				file.write(QString("%1 ").arg(matrixes[matrI][i][j]).toLocal8Bit());
		if (matrI==1)
		{
			file.write(Tr("Определитель: %1\nАлгебраическое дополнение: %2").arg(det).arg(algebraicAddition).toLocal8Bit());
		}
	}
	file.close();
}

void MatrixForm::fileSave()
{
	if (fileName=="")
		fileSaveAs();
	else
		writeData();
}

void MatrixForm::fileSaveAs()
{
	QString openFileName=QFileDialog::getSaveFileName();

	if (openFileName=="")
		return;
	fileName=openFileName;
	writeData();
	updateWindowTitle();
}

void MatrixForm::aboutThis()
{
/*	QDialog *aboutBox=new QDialog(this);
	QLabel *label=new QLabel(aboutBox);
	//QPushButton *okButton=new QPushButton(Tr("Закрыть"), aboutBox);
	QVBoxLayout *aboutLa=new QVBoxLayout();
	
	aboutLa->addWidget(label);
	label->setText(Tr("QMatrixOperator "BUILD" by chemikadze (c) 2009\n\nПрограмма для вычислений с матрицами.\nРаспространяется по лицензии GPLv3\nE-mail: chemikadze@gmail.com\n"));
	//la->addWidget(okButton);
	aboutBox->setLayout(aboutLa);
	//connect(okButton, SIGNAL(clicked()), aboutBox, SLOT(close()));
	//aboutBox->setModal(true);
	aboutBox->exec();
	delete label;
	delete aboutLa;
	delete aboutBox;
*/
	QMessageBox::about(0, Tr("О программе"), Tr("<h3>QMatrixOperator "BUILD"</h3> <h5>by chemikadze (c) 2009</h5>Программа для вычислений с матрицами.<br>Распространяется по лицензии GPLv3<br>E-mail: <a href=\"mailto:chemikadze@gmail.com\">chemikadze@gmail.com</a>"));
}
