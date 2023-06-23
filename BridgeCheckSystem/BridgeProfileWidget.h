#pragma once

#include <QWidget>
#include "ui_BridgeProfileWidget.h"

class BridgeProfileWidget : public QWidget
{
	Q_OBJECT

public:
	BridgeProfileWidget(QWidget* parent = nullptr);
	~BridgeProfileWidget();

	void on_ADMIDBtn_clicked();
	void on_BTSBtn_clicked();
	void on_BSInfoBtn_clicked();
	void on_BRDBtn_clicked();
	void on_BMAHBtn_clicked();
	void on_MDRBtn_clicked();
	void on_OtherBtn_clicked();

private:
	Ui::BridgeProfileWidgetClass ui;
};
