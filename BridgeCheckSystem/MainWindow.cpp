#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	// Set to delete this object when the window is closed
	setAttribute(Qt::WA_DeleteOnClose);

	// show the amap on miniblink webview
	showAmap();

	connect(ui.newProfileBtn, &QPushButton::clicked, this, &MainWindow::on_newProfileBtn_clicked);
	connect(ui.showProfileBtn, &QPushButton::clicked, this, &MainWindow::on_showProfileBtn_clicked);
}

void MainWindow::showAmap() {
	const QString mapPath = "H:\\QTprogarm\\BridgeCheckSystem\\BridgeCheckSystem\\BridgeCheckSystem\\amap\\amap.html";
	webView = wkeCreateWebWindow(WKE_WINDOW_TYPE_CONTROL, (HWND)ui.mapWidget->winId(), 0, 0, 1100, 800);
	wkeShowWindow(webView, TRUE);
	QFile file(mapPath);
	file.open(QIODevice::ReadOnly);
	wkeLoadHTML(webView, file.read(file.bytesAvailable()));
}

void MainWindow::on_newProfileBtn_clicked() {
	BridgeProfileWidget* bpWidget = new BridgeProfileWidget();
	bpWidget->setWindowModality(Qt::ApplicationModal);	// 模态窗口，阻塞一切窗口
	auto title = QString("新建资料卡 类型: %1").arg(ui.bridgeTypes->currentText());
	bpWidget->setWindowTitle(title);
	// send bridge type to bpWidget
	connect(this, &MainWindow::send_bridgeType, bpWidget, &BridgeProfileWidget::receive_bridgeType);
	emit send_bridgeType(ui.bridgeTypes->currentText());
	bpWidget->show();
}

void MainWindow::on_showProfileBtn_clicked() {
	// TODO: 写完接口以后写这个
}