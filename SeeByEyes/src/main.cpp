#include "mainwindow.h"
#include "SBEApp.h"
//QT5
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QStyleFactory>
#include <QThread>
#include <QMessageBox>

int main(int argc, char* argv[])
{



	SBEApp app(argc, argv);
    app.setStyle(QStyleFactory::create("fusion"));
    app.setQuitOnLastWindowClosed(true);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString& locale : uiLanguages) {
        const QString baseName = "SBE_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
        }
    }
	SMainwindow* mainwindow = SMainwindow::getInstance();
	mainwindow->show();
	int result = 0;
	result = QApplication::exec();
	return 0;
	try
	{
		result = QApplication::exec();
	}
	catch (const std::exception& e)
	{
		QMessageBox::warning(nullptr, "SBE ", QString(":)\n") + e.what());
	}
	catch (...)
	{
		QMessageBox::warning(nullptr, "SBE ", "������Ϣ:)");
	}
	return result;
	SMainwindow::destroyInstance();
}
