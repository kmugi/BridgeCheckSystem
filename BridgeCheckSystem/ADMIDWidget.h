#pragma once

#include <QWidget>
#include "ui_ADMIDWidget.h"

#include <QValidator>
#include <QRegularExpressionValidator>
#include <QList>
#include <QMessageBox>
#include <QCloseEvent>

#include "ADMID.h"

class ADMIDWidget : public QWidget
{
	Q_OBJECT

signals:
	// to BridgeProfileWidget
	void send_ADMID_Info(const ADMID& info);

public:
	ADMIDWidget(QWidget* parent = nullptr);
	~ADMIDWidget();

	void receive_type(ADMID::Type type);

	// 是否有 LineEdit 不为空
	bool isEditNotEmpty() const;

	// 是否全部的 LineEdit 都为空
	bool isEditsEmpty() const;

	void closeEvent(QCloseEvent* event);

	void clearEdits();

	void receive_ADMID_info(const ADMID& info);

private:
	Ui::ADMIDWidgetClass ui;
};
