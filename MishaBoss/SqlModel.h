#ifndef SQL_MODEL_H
#define SQL_MODEL_H

#include <QSqlTableModel>
#include <QtQmlIntegration/qqmlintegration.h>

class SqlModel : public QSqlTableModel
{
	Q_OBJECT
	QML_ELEMENT
	Q_PROPERTY(QString table WRITE setTable)

public:
	explicit SqlModel(QObject* parent = nullptr);
	virtual ~SqlModel();

	Q_INVOKABLE void lodDB(const QString& dbName);

};

#endif // SQL_MODEL_H
