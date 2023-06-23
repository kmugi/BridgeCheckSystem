#include "Login.h"

Login::Login(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// initialize Database
	DatabaseManager::instance().init(database);

	// bind keyboard key
	ui.loginBtn->setShortcut(Qt::Key_Enter);
	ui.exitBtn->setShortcut(Qt::Key_Escape);

	connect(ui.loginBtn, &QPushButton::clicked,
		[this] {
			if (ui.usernameEdit->text().isEmpty() || ui.passwordEdit->text().isEmpty()) {
				QMessageBox::critical(this, "错误", "账号或密码不能为空");
				clearEdit();
				return;
			}

			if (AccountDao::isAccountExist(ui.usernameEdit->text(), ui.passwordEdit->text())) {
				MainWindow* mainWindow = new MainWindow();
				mainWindow->show();
				this->close();
			} else {
				QMessageBox::critical(this, "错误", "账号或密码错误");
				clearEdit();
			}
		}
	);

	connect(ui.exitBtn, &QPushButton::clicked, this, &Login::close);
}

Login::~Login()
{}

void Login::clearEdit() {
	ui.usernameEdit->clear();
	ui.passwordEdit->clear();
}