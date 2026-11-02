#include <QApplication>
#include <QQmlApplicationEngine>

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

#include "ViewWidget.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	// auto db = QSqlDatabase::addDatabase("QSQLITE");
	// db.setDatabaseName("staff.db");

	// if (!db.open() && db.lastError().isValid()) {
	// 	qInfo() << db.lastError();
	// } else {
	// 	db.open();
	// 	qInfo() << "Db opened";
	// }

	// auto tableList = db.tables();

	// if (!tableList.empty()) {
	// 	qInfo() << tableList;

	// } else {

	// 	QApplication::quit();
	// 	return 1;
	// }

	// ViewWidget wid(db);
	// wid.show();

//	db.close();

	QQmlApplicationEngine engine;
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, qApp,
					 []() { QCoreApplication::exit(-1); },
	Qt::QueuedConnection);
	engine.loadFromModule("MishaBoss", "Main");

	return app.exec();
}
