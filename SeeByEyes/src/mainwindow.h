#ifndef MAINWINDOW_H
#define MAINWINDOW_H

//QT5
#include <QMainWindow>
#include "ui_templates/ui_mainwindow.h"
namespace Ui {
	class MainWindow;
}
class SMainwindow : public QMainWindow
	
{
	Q_OBJECT
protected:
	SMainwindow(QWidget* parent = nullptr);
	~SMainwindow() override;
public:
	static SMainwindow* getInstance();
	static void destroyInstance();

private slots:
	void doLoadFile();
private:
	Ui::MainWindow* m_UI;
};
#endif