#include <QSqlTableModel>


#include <QTableView>
#include <QVBoxLayout>

#include "ViewWidget.h"

ViewWidget::ViewWidget(const QString& tableName, QWidget* parent) : QWidget(parent)
{
	auto tableModel = new QSqlTableModel(this);
	tableModel->setTable(tableName);
	tableModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
	tableModel->select();

	QTableView* view = new QTableView;
	view->setModel(tableModel);
	view->show();

	auto lay = new QVBoxLayout;
	lay->addWidget(view);

	setLayout(lay);
}

ViewWidget::~ViewWidget() = default;
