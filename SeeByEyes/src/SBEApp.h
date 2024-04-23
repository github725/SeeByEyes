#ifndef SBEAPP_H
#define SBEAPP_H

//QT
#include <QApplication>

class SBEApp : public QApplication
{
	Q_OBJECT
public:
	SBEApp(int& argc, char** argv);
	~SBEApp();
};

#endif