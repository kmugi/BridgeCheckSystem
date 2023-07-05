#include "BTIDao.h"

void BTIDao::insertBTI(const QString& bridgeNumber, const BTI& bti) {
	auto sql = QString("INSERT INTO bti (length, width, laneWidth, sidewalkWidth, \
guardrailHeight, medianWidth, BVC, ABC, AUC, ARW) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);
	query.addBindValue(bti.getLength());
	query.addBindValue(bti.getWidth());
	query.addBindValue(bti.getLaneWidth());
	query.addBindValue(bti.getSidewalkWidth());
	query.addBindValue(bti.getGuardrailHeight());
	query.addBindValue(bti.getMedianWidth());
	query.addBindValue(bti.getBVC());
	query.addBindValue(bti.getABC());
	query.addBindValue(bti.getAUC());
	query.addBindValue(bti.getARW());

	bool flag = query.exec();
	if (!flag) {
		CRITICAL("Failed to insert bti");
	}
}

void BTIDao::deleteBTI(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	query.exec();
}

std::optional<float> BTIDao::queryLength(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("length").toFloat();
	}

	return std::nullopt;
}

// TODO: 补充剩下的 query


void BTIDao::updateLength(const QString& bridgeNumber, float length) {
	auto sql = QString("UPDATE bti SET length = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(length);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update '%1'").arg(length));
	}
}

// TODO: 补充剩下的 update