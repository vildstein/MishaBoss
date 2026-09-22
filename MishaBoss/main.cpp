#include <QApplication>
#include <QQmlApplicationEngine>

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	auto db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName("staff.db");

	if (!db.open() && db.lastError().isValid()) {
		qInfo() << db.lastError();
	} else {
		db.open();
	}

	QQmlApplicationEngine engine;
	QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, qApp,
					 []() { QCoreApplication::exit(-1); },
	Qt::QueuedConnection);
	engine.loadFromModule("MishaBoss", "Main");

	return app.exec();
}
