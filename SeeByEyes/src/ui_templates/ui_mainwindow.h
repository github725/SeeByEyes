#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QAction>
#include <QCoreApplication>


QT_BEGIN_NAMESPACE

class UI_MainWindow 
{
public:
	QMenuBar* menuBar;
	QToolBar* mainToolBar;
	QAction* actionOpen;
	QAction* actionClose;
	QAction* actionSave;
	QMenu* menuFile;
	void setupUi(QMainWindow* MainWindow)
	{
		//MainWindow设置
		if (MainWindow->objectName().isEmpty())
			MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
		MainWindow->resize(1024, 768);
		//action
		actionOpen = new QAction(MainWindow);
		QIcon iconOpen;
		iconOpen.addFile(QString::fromUtf8(":/SBE/images/open.svg"), QSize(), QIcon::Normal, QIcon::Off);
		actionOpen->setIcon(iconOpen);
		actionClose = new QAction(MainWindow);
		QIcon iconClose;
		iconClose.addFile(QString::fromUtf8(":/SBE/images/close.svg"), QSize(), QIcon::Normal, QIcon::Off);
		actionClose->setIcon(iconClose);
		actionSave = new QAction(MainWindow);
		QIcon iconSave;
		iconSave.addFile(QString::fromUtf8(":/SBE/images/save.svg"), QSize(), QIcon::Normal, QIcon::Off);
		actionSave->setIcon(iconSave);
		//菜单栏设置
		menuBar = new QMenuBar(MainWindow);
		menuBar->setGeometry(QRect(0, 0, 1024, 21));
		//文件菜单
		menuFile = new QMenu(menuBar);
		MainWindow->setMenuBar(menuBar);

		menuFile->addSeparator();
		menuFile->addAction(actionOpen);
		menuFile->addAction(actionSave);
		menuFile->addAction(actionClose);
		
		menuBar->addAction(menuFile->menuAction());
		//主工具栏
		mainToolBar = new QToolBar(MainWindow);
		//mainToolBar->setGeometry(QRect(0, 21, 1024, 21));
		MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
		mainToolBar->addAction(actionOpen);
		mainToolBar->addAction(actionSave);
		mainToolBar->addAction(actionClose);
		
		
		retranslateUi(MainWindow);
		QMetaObject::connectSlotsByName(MainWindow);
	}
	void retranslateUi(QMainWindow* MainWindow)
	{
		/*actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
		actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));*/
		menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));

	}

};
namespace Ui {
	class MainWindow : public UI_MainWindow {};
} // namespace Ui


QT_END_NAMESPACE
#endif