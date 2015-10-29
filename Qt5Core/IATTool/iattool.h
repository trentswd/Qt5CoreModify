#ifndef IATTOOL_H
#define IATTOOL_H

#include <QtWidgets/QMainWindow>
#include "ui_iattool.h"

class IATTool : public QMainWindow
{
	Q_OBJECT

public:
	IATTool(QWidget *parent = 0);
	~IATTool();

private:
	Ui::IATToolClass ui;

	QString outText;
public slots:
	void on_pushButtonGen_clicked();
};

#endif // IATTOOL_H
