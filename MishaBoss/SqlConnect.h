#ifndef SQL_CONNECT_H
#define SQL_CONNECT_H

#include <QObject>
#include <QtQmlIntegration/qqmlintegration.h>

class SqlConnect : public QObject
{
	Q_OBJECT
	QML_ELEMENT

	//Q_PROPERTY(QString tableName WRITE setTable)
	Q_PROPERTY(QString tableName NOTIFY tableReaded)

public:
	explicit SqlConnect(QObject* parent = nullptr);
	virtual ~SqlConnect();

	Q_INVOKABLE void tryToConnect(const QString& dbName);

signals:
	//void tablesInDataBase(const QStringList& tablesInDb);

	void tableReaded(const QString& tableName);



};



#endif // SQL_CONNECT_H
