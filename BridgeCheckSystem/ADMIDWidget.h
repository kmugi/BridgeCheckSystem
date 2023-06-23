#pragma once

#include <QWidget>
#include "ui_ADMIDWidget.h"

#include <optional>

#include "ADMID.h"

class ADMIDWidget : public QWidget
{
	Q_OBJECT

public:
	ADMIDWidget(QWidget* parent = nullptr);
	~ADMIDWidget();

	void receive_type(ADMID::Type type);

private:
	Ui::ADMIDWidgetClass ui;
};
