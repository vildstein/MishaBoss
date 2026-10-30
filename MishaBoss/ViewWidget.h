#ifndef VIEW_WIDGET_H
#define VIEW_WIDGET_H

#include <QWidget>

class ViewWidget : public QWidget
{
public:
	explicit ViewWidget(const QString& tableName, QWidget* parent = nullptr);
	virtual ~ViewWidget();
};


#endif // VIEW_WIDGET_H
