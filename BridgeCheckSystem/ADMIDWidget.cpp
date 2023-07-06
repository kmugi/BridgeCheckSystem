#include "ADMIDWidget.h"

ADMIDWidget::ADMIDWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Set to delete this object when the window is closed
	setAttribute(Qt::WA_DeleteOnClose);

	ui.HASCEdit->setValidator(new QRegularExpressionValidator(QRegularExpression("^[0-9]{6}$"), this));
	auto matchNumber = new QRegularExpressionValidator(QRegularExpression("^[+-]?\\d+(\\.\\d+)?$"), this);
	ui.lngEdit->setValidator(matchNumber);
	ui.latEdit->setValidator(matchNumber);
	auto matchPositiveNumber = new QRegularExpressionValidator(QRegularExpression("^[1-9]\\d*(\\.\\d+)?$"), this);
	ui.designLoadEdit->setValidator(matchPositiveNumber);
	ui.gradeEdit->setValidator(matchPositiveNumber);

	connect(ui.saveBtn, &QPushButton::clicked,
		[this] {
			if (isEditsEmpty()) {
				QMessageBox::warning(this, "保存失败", "有未填入的数据项");
				return;
			}

			emit send_ADMID_Info(ADMID(
				ui.HASCEdit->text(),
				ui.bridgeNameEdit->text().trimmed(),
				ui.bridgeNumberEdit->text().trimmed(),
				ui.routeNameEdit->text().trimmed(),
				ui.routeNumberEdit->text().trimmed(),
				ADMID::strToType[ui.typeEdit->text()],
				ADMID::strToRouteLevel[ui.routeLevelEdit->currentText()],
				ADMID::strToFunctionType[ui.funcTypeEdit->currentText()],
				{ ui.lngEdit->text().toFloat(), ui.latEdit->text().toFloat() },
				ui.buildTime->dateTime(),
				ui.designLoadEdit->text().toFloat(),
				ui.gradeEdit->text().toFloat(),
				ui.designUnitEdit->text().trimmed(),
				ui.constructorUnitEdit->text().trimmed(),
				ui.supervisoryUnitEdit->text().trimmed(),
				ui.ownerUnitEdit->text().trimmed(),
				ui.managementUnitEdit->text().trimmed()
			));

			clearEdits();

			this->close();
		}
	);

	connect(ui.exitBtn, &QPushButton::clicked, this, &ADMIDWidget::close);
}

ADMIDWidget::~ADMIDWidget()
{}


void ADMIDWidget::receive_type(ADMID::Type type) {
	ui.typeEdit->setText(ADMID::typeToStr[type]);
}

void ADMIDWidget::closeEvent(QCloseEvent* event) {
	if (isEditNotEmpty()) {
		auto result = QMessageBox::question(this, "确认", "有未提交的表单，确定要退出吗？", QMessageBox::Yes | QMessageBox::Cancel);
		if (result == QMessageBox::Yes) {
			event->accept();
		} else {
			event->ignore();
		}
	}
}

bool ADMIDWidget::isEditNotEmpty() const {
	/*
	* findChildren<QLineEdit*> 会带一个 QDateEdit进来
	* 所以选择最笨的方法
	*/

	if (!ui.HASCEdit->text().isEmpty() ||
		!ui.bridgeNameEdit->text().isEmpty() ||
		!ui.bridgeNumberEdit->text().isEmpty() ||
		!ui.routeNameEdit->text().isEmpty() ||
		!ui.routeNumberEdit->text().isEmpty() ||
		!ui.lngEdit->text().isEmpty() ||
		!ui.latEdit->text().isEmpty() ||
		!ui.designLoadEdit->text().isEmpty() ||
		!ui.gradeEdit->text().isEmpty() ||
		!ui.designUnitEdit->text().isEmpty() ||
		!ui.constructorUnitEdit->text().isEmpty() ||
		!ui.supervisoryUnitEdit->text().isEmpty() ||
		!ui.managementUnitEdit->text().isEmpty() ||
		!ui.ownerUnitEdit->text().isEmpty()
		) {
		return true;
	}

	return false;

}

bool ADMIDWidget::isEditsEmpty() const {
	if (!ui.HASCEdit->text().isEmpty() &&
		!ui.bridgeNameEdit->text().isEmpty() &&
		!ui.bridgeNumberEdit->text().isEmpty() &&
		!ui.routeNameEdit->text().isEmpty() &&
		!ui.routeNumberEdit->text().isEmpty() &&
		!ui.lngEdit->text().isEmpty() &&
		!ui.latEdit->text().isEmpty() &&
		!ui.designLoadEdit->text().isEmpty() &&
		!ui.gradeEdit->text().isEmpty() &&
		!ui.designUnitEdit->text().isEmpty() &&
		!ui.constructorUnitEdit->text().isEmpty() &&
		!ui.supervisoryUnitEdit->text().isEmpty() &&
		!ui.managementUnitEdit->text().isEmpty() &&
		!ui.ownerUnitEdit->text().isEmpty()
		) {
		return false;
	}

	return true;
}

void ADMIDWidget::clearEdits() {
	ui.HASCEdit->clear();
	ui.bridgeNameEdit->clear();
	ui.bridgeNumberEdit->clear();
	ui.routeNameEdit->clear();
	ui.routeNumberEdit->clear();
	ui.lngEdit->clear();
	ui.latEdit->clear();
	ui.designLoadEdit->clear();
	ui.gradeEdit->clear();
	ui.designUnitEdit->clear();
	ui.constructorUnitEdit->clear();
	ui.supervisoryUnitEdit->clear();
	ui.managementUnitEdit->clear();
	ui.ownerUnitEdit->clear();
}

void ADMIDWidget::receive_ADMID_info(const ADMID& info) {
	qDebug() << info.getHASC();
	ui.HASCEdit->setText(info.getHASC());
	ui.bridgeNameEdit->setText(info.getBridgeName());
	ui.bridgeNumberEdit->setText(info.getBridgeNumber());
	ui.routeNameEdit->setText(info.getRouteName());
	ui.routeNumberEdit->setText(info.getRouteNumber());
	ui.typeEdit->setText(ADMID::typeToStr[info.getType()]);
	ui.routeLevelEdit->setCurrentText(ADMID::routeLevelToStr[info.getRouteLevel()]);
	ui.funcTypeEdit->setCurrentText(ADMID::functionTypeToStr[info.getFuncType()]);
	ui.lngEdit->setText(QString::number(info.getLnglat().first));
	ui.latEdit->setText(QString::number(info.getLnglat().second));
	ui.buildTime->setDateTime(info.getBuildTime());
	ui.designLoadEdit->setText(QString::number(info.getDesignLoad(), 'f', 5));
	ui.gradeEdit->setText(QString::number(info.getGrade(), 'f', 5));
	ui.designUnitEdit->setText(info.getDesignUnit());
	ui.constructorUnitEdit->setText(info.getConstructorUnit());
	ui.supervisoryUnitEdit->setText(info.getSupervisoryUnit());
	ui.managementUnitEdit->setText(info.getManagementUnit());
	ui.ownerUnitEdit->setText(info.getOwnerUnit());
}