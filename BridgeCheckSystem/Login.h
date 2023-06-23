#pragma once

#include <QtWidgets/QWidget>
#include "ui_Login.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>

#include "DatabaseManager.hpp"
#include "AccountDao.h"
#include "MainWindow.h"

class Login : public QWidget
{
	Q_OBJECT

public:
	Login(QWidget* parent = nullptr);
	~Login();

	void clearEdit();

private:
	QSqlDatabase database;

private:
	Ui::LoginClass ui;
};
