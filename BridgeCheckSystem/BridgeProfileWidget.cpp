#include "BridgeProfileWidget.h"

BridgeProfileWidget::BridgeProfileWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Set to delete this object when the window is closed
	setAttribute(Qt::WA_DeleteOnClose);

	// test
	connect(ui.ADMIDBtn, &QPushButton::clicked,
		[this] {
			qDebug() << static_cast<int>(type.value());
		}
	);
}

BridgeProfileWidget::~BridgeProfileWidget()
{}

void BridgeProfileWidget::receive_bridgeType(const QString& typeStr) {
	type = std::make_optional<ADMID::Type>(ADMID::strToType[typeStr]);
}
