#include "BridgeProfileWidget.h"

BridgeProfileWidget::BridgeProfileWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Set to delete this object when the window is closed
	setAttribute(Qt::WA_DeleteOnClose);

	// test
	connect(ui.ADMIDBtn, &QPushButton::clicked, this, &BridgeProfileWidget::on_ADMIDBtn_clicked);
}

BridgeProfileWidget::~BridgeProfileWidget()
{}

void BridgeProfileWidget::receive_bridgeType(const QString& typeStr) {
	type = std::make_optional<ADMID::Type>(ADMID::strToType[typeStr]);
}

void BridgeProfileWidget::on_ADMIDBtn_clicked() {
	ADMIDWidget* admidWidget = new ADMIDWidget();
	admidWidget->setWindowModality(Qt::ApplicationModal);	// 模态窗口，阻塞一切窗口
	connect(this, &BridgeProfileWidget::send_type, admidWidget, &ADMIDWidget::receive_type);
	if (type) {
		emit send_type(type.value());
	} else {
		DEBUG("type stored no value");
	}
	admidWidget->show();
}