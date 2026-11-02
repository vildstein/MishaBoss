#include <QSqlTableModel>

#include <QTableView>
#include <QVBoxLayout>

#include "ViewWidget.h"

//ViewWidget::ViewWidget(const QString& tableName, QWidget* parent) : QWidget(parent)
ViewWidget::ViewWidget(const QSqlDatabase &db, QWidget* parent) : QWidget(parent)
{
	auto tableModel = new QSqlTableModel(this, db);

//	foreach (const auto& table, db.tables()) {
//		tableModel->setTable(table);
//	}

	tableModel->setTable(db.tables().at(0));
	tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	tableModel->select();

	auto view = new QTableView;
	view->setModel(tableModel);
	view->show();

	auto lay = new QVBoxLayout;
	lay->addWidget(view);

	setLayout(lay);
}

ViewWidget::~ViewWidget() = default;
