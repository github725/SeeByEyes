#include "mainwindow.h"
static SMainwindow* s_instance = nullptr;

SMainwindow::SMainwindow(QWidget* parent)
	:QMainWindow(parent),
	m_UI(new Ui::MainWindow)
{
	m_UI->setupUi(this);
}
SMainwindow::~SMainwindow()
{

}
SMainwindow* SMainwindow::getInstance()
{
	if (s_instance == nullptr)
	{
		s_instance = new SMainwindow();
		
	}
	return s_instance;
}
void SMainwindow::destroyInstance()
{
	if (s_instance != nullptr)
	{
		delete s_instance;
		s_instance = nullptr;
	}
}

void SMainwindow::doLoadFile()
{
	
}
