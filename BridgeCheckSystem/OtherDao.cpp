#include "OtherDao.h"


void OtherDao::insertOther(const QString& bridgeNumber, const Other& other) {
	auto sql = QString("INSERT INTO other (bridgeNumber, bridgeEngineer, cardFiller, \
cardTime) VALUES (?, ?, ?, ?)");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);
	query.addBindValue(other.getBridgeEngineer());
	query.addBindValue(other.getCardFiller());
	query.addBindValue(other.getCardTime());

	if (!query.exec()) {
		CRITICAL("Failed to insert other");
	}
}

void OtherDao::deleteOther(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM other WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	query.exec();
}

std::optional<QString> OtherDao::queryBridgeEngineer(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM other WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("bridgeEngineer").toString();
	}

	return std::nullopt;
}

//TODO: query


void OtherDao::updateBridgeEngineer(const QString& bridgeNumber, const QString& bridgeEngineer) {
	auto sql = QString("UPDATE other SET bridgeEngineer = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeEngineer);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update '%1'").arg(bridgeEngineer));
	}
}

//TODO: update