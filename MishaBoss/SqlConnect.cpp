#include <QSqlDatabase>
#include <QSqlError>

#include <QDebug>
#include "SqlConnect.h"


SqlConnect::SqlConnect(QObject* parent) : QObject(parent)
{

}

SqlConnect::~SqlConnect() = default;

void SqlConnect::tryToConnect(const QString& dbName)
{
	qInfo() << dbName << " from CPP SqlConnect";

	auto db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);

	if (!db.open() && db.lastError().isValid()) {
		qInfo() << db.lastError();
		qInfo() << "Make return";
		return;
	}

	auto tableList = db.tables();

	if (tableList.empty()) {
//		m_tables = tableList;
//		emit tablesInDataBase(tableList);
		qInfo() << "Empty";
		return;
	}

	foreach (const auto& table, tableList) {
//		qInfo() << table;
		emit tableReaded(table);
	}

}
