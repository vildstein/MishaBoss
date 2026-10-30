#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

#include "SqlModel.h"

SqlModel::SqlModel(QObject* parent) : QSqlTableModel(parent)
{

}


SqlModel::~SqlModel() = default;


void SqlModel::lodDB(const QString& dbName)
{
	qInfo() << dbName << " from CPP";

//	tableModel->setTable(tableName);
//	tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
//	tableModel->select();

	auto db = QSqlDatabase::addDatabase("QSQLITE");
	db.setDatabaseName(dbName);

	if (!db.open() && db.lastError().isValid()) {
		qInfo() << db.lastError();
	} else {
		db.open();
		qInfo() << "Db opened";
	}

}
