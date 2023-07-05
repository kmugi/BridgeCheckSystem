#include "MDRDao.h"


void MDRDao::insertMDR(const QString& bridgeNumber, const MDR& mdr) {
	auto sql = QString("INSERT INTO mdr (bridgeNumber, time, type, remedialActionReason, \
remedialActionScope, projectCost, fundingSource, RAQA) VALUES (?, ?, ?, ?, ?, ?, ?, ?);");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);
	query.addBindValue(mdr.getTime());
	query.addBindValue(static_cast<int>(mdr.getType()));
	query.addBindValue(mdr.getRemedialActionReason());
	query.addBindValue(mdr.getRemedialActionScope());
	query.addBindValue(mdr.getProjectCost());
	query.addBindValue(mdr.getFundingSource());
	query.addBindValue(mdr.getRAQA());

	if (!query.exec()) {
		CRITICAL("Failed to insert mdr");
	}
}

void MDRDao::deleteMDR(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	query.exec();
}

std::optional<QDateTime> MDRDao::queryTime(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("time").toDateTime();
	}

	return std::nullopt;
}

//TODO: query

void MDRDao::updateTime(const QString& bridgeNumber, const QDateTime& time) {
	auto sql = QString("UPDATE mdr SET time = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(time);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update '%1'").arg(time.toString()));
	}
}

//TODO: update