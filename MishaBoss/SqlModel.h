#ifndef SQL_MODEL_H
#define SQL_MODEL_H

#include <QSqlTableModel>
#include <QtQmlIntegration/qqmlintegration.h>

class SqlModel : public QSqlTableModel
{
	Q_OBJECT
	QML_ELEMENT
//	Q_PROPERTY(QString table WRITE setTable)
//	Q_PROPERTY(QStringList tables MEMBER m_tables NOTIFY tablesInDataBase)
//	Q_PROPERTY(QString tableName MEMBER m_tables NOTIFY tablesInDataBase)

public:
	explicit SqlModel(QObject* parent = nullptr);
	virtual ~SqlModel();

	Q_INVOKABLE void loadDB(const QString& dbName);
	QStringList tables() const;

signals:

private:
	QStringList m_tables;

};

#endif // SQL_MODEL_H
