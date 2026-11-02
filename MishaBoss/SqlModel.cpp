
#include <QDebug>

#include "SqlModel.h"

SqlModel::SqlModel(QObject* parent) : QSqlTableModel(parent)
{

}


SqlModel::~SqlModel() = default;


void SqlModel::loadDB(const QString& dbName)
{


//	setTable(tableList[0]);
	setEditStrategy(QSqlTableModel::OnManualSubmit);
	select();
}

QStringList SqlModel::tables() const
{
	return m_tables;
}
