#pragma once

#include <QString>
#include <QDateTime>

// 其他项 
// others
class Other {
public:
	//set函数
	void setBridgeEngineer(QString bridgeEngineer_) { bridgeEngineer = bridgeEngineer_; }
	void setCardFiller(QString cardFiller_) { cardFiller = cardFiller_; }
	void setCardTime(QDateTime cardTime_) { cardTime = cardTime_; }
	//get函数
	QString getBridgeEngineer() const { return bridgeEngineer; }
	QString getCardFiller() const { return cardFiller; }
	QDateTime getCardTime() const { return cardTime; }
private:
	QString bridgeEngineer;
	QString cardFiller;			// 填卡人
	QDateTime cardTime;			// 填卡时间
};

