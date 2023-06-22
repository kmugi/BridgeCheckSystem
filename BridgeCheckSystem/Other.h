#pragma once

#include <QString>
#include <QDateTime>

// 其他项 
// others
class Other {
public:

	// TODO: add constructor

	void setBridgeEngineer(const QString& bridgeEngineer) { bridgeEngineer_ = bridgeEngineer; }
	void setBridgeEngineer(QString&& bridgeEngineer) { bridgeEngineer_ = std::move(bridgeEngineer); }
	QString getBridgeEngineer() const { return bridgeEngineer_; }

	void setCardFiller(const QString& cardFiller) { cardFiller_ = cardFiller; }
	void setCardFiller(QString&& cardFiller) { cardFiller_ = std::move(cardFiller); }
	QString getCardFiller() const { return cardFiller_; }

	void setCardTime(const QDateTime& cardTime) { cardTime_ = cardTime; }
	void setCardTime(QDateTime&& cardTime) { cardTime_ = std::move(cardTime); }
	QDateTime getCardTime() const { return cardTime_; }

private:
	QString bridgeEngineer_;
	QString cardFiller_;			// 填卡人
	QDateTime cardTime_;			// 填卡时间
};

