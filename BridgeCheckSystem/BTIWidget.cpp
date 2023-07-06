#include "BTIWidget.h"

BTIWidget::BTIWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Set to delete this object when the window is closed
	setAttribute(Qt::WA_DeleteOnClose);

	// lineEdit filter
	auto matchNumber = new QRegularExpressionValidator(QRegularExpression("^[+-]?\\d+(\\.\\d+)?$"), this);
	auto edits = findChildren<QLineEdit*>();
	for (auto& edit : edits) {
		edit->setValidator(matchNumber);
	}


	connect(ui.saveBtn, &QPushButton::clicked,
		[this] {
			if (isEditsEmpty()) {
				QMessageBox::warning(this, "保存失败", "有未填入的数据项");
				return;
			}

			emit send_BTI_Info(BTI(
				ui.lengthEdit->text().toFloat(),
				ui.widthEdit->text().toFloat(),
				ui.laneWidthEdit->text().toFloat(),
				ui.sidewalkWidthEdit->text().toFloat(),
				ui.guardrailHeightEdit->text().toFloat(),
				ui.medianWidthEdit->text().toFloat(),
				ui.BVCEdit->text().toFloat(),
				ui.ABCEdit->text().toFloat(),
				ui.AUCEdit->text().toFloat(),
				ui.ARWEdit->text().toFloat()
			));

			clearEdits();

			this->close();
		}
	);

	connect(ui.exitBtn, &QPushButton::clicked, this, &BTIWidget::close);
}

BTIWidget::~BTIWidget()
{}

bool BTIWidget::isEditNotEmpty() {
	auto edits = findChildren<QLineEdit*>();
	for (auto& edit : edits) {
		if (!edit->text().isEmpty()) {
			return true;
		}
	}

	return false;
}

bool BTIWidget::isEditsEmpty() {
	auto edits = findChildren<QLineEdit*>();
	for (auto& edit : edits) {
		if (edit->text().isEmpty()) {
			return true;
		}
	}

	return false;
}

void BTIWidget::closeEvent(QCloseEvent* event) {
	if (isEditNotEmpty()) {
		auto result = QMessageBox::question(this, "确认", "有未提交的表单，确定要退出吗？", QMessageBox::Yes | QMessageBox::Cancel);
		if (result == QMessageBox::Yes) {
			event->accept();
		} else {
			event->ignore();
		}
	}
}

void BTIWidget::clearEdits() {
	auto edits = findChildren<QLineEdit*>();
	for (auto& edit : edits) {
		edit->clear();
	}
}