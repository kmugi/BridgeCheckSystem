#pragma once

#include <QWidget>
#include "ui_BTIWidget.h"

#include <QValidator>
#include <QRegularExpressionValidator>
#include <QCloseEvent>
#include <QMessageBox>

#include "BTI.h"

class BTIWidget : public QWidget
{
	Q_OBJECT

signals:
	// to BridgeProfileWidget
	void send_BTI_Info(const BTI& info);

public:
	BTIWidget(QWidget* parent = nullptr);
	~BTIWidget();

	bool isEditNotEmpty();

	bool isEditsEmpty();

	void closeEvent(QCloseEvent* event);

	void clearEdits();

	void receive_BTI_info(const BTI& info);

private:
	Ui::BTIWidgetClass ui;
};
