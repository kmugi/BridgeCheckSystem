#include "ADMIDWidget.h"

ADMIDWidget::ADMIDWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Set to delete this object when the window is closed
	setAttribute(Qt::WA_DeleteOnClose);

}

ADMIDWidget::~ADMIDWidget()
{}


void ADMIDWidget::receive_type(ADMID::Type type) {
	ui.typeEdit->setText(ADMID::typeToStr[type]);
}