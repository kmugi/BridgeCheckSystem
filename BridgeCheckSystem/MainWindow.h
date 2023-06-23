#pragma once

#include <QWidget>
#include <QFile>

#include "ui_MainWindow.h"
#include "wke.h"
#include "BridgeProfileWidget.h"

class MainWindow : public QWidget
{
	Q_OBJECT

signals:
	void send_bridgeType(const QString& typeStr);
	// TODO: 编写传输桥梁数据的信号函数

public:
	MainWindow(QWidget* parent = nullptr);
	~MainWindow() {}

	void showAmap();

	void on_newProfileBtn_clicked();
	void on_showProfileBtn_clicked();

private:
	wkeWebView webView{}; // miniblink container

private:
	Ui::MainWindowClass ui;
};
