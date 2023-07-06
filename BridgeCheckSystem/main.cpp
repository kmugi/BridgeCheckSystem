#include "Login.h"
#include <QtWidgets/QApplication>

#include <QFile>
#include <QString>

#include "wke.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	// load qss
	QString qss{};
	QFile qssFile{ "H:\\QTprogarm\\BridgeCheckSystem\\BridgeCheckSystem\\BridgeCheckSystem\\qss\\Ubuntu.qss" };
	qssFile.open(QIODeviceBase::ReadOnly);
	if (qssFile.isOpen()) {
		qss = QLatin1String(qssFile.readAll());
		qApp->setStyleSheet(qss);
		qssFile.close();
		qDebug() << "Successfully loaded the QSS resource file";
	} else {
		qDebug() << "Can't open the qss resource file";
	}

	// load wke dll and initialize
	wkeSetWkeDllPath(L"H:\\QTprogarm\\BridgeCheckSystem\\BridgeCheckSystem\\BridgeCheckSystem\\miniblink_4975_x64.dll");
	wkeInit();

	Login w;
	w.show();
	return a.exec();
}
