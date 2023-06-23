#include "BridgeProfileWidget.h"

BridgeProfileWidget::BridgeProfileWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Set to delete this object when the window is closed
	setAttribute(Qt::WA_DeleteOnClose);
}

BridgeProfileWidget::~BridgeProfileWidget()
{}
