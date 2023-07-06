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

std::optional<MDR> MDRDao::queryMDR(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return MDR(
			query.value("time").toDateTime(),
			static_cast<MDR::RemedialActionType>(query.value("type").toInt()),
			query.value("remedialActionReason").toString(),
			query.value("remedialActionScope").toString(),
			query.value("projectCost").toInt(),
			query.value("fundingSource").toString(),
			query.value("RAQA").toString()
		);
	}

	return std::nullopt;
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


std::optional<MDR::RemedialActionType> MDRDao::queryType(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return static_cast<MDR::RemedialActionType>(query.value("type").toInt());
	}

	return std::nullopt;
}

std::optional<QString> MDRDao::queryRemedialActionReason(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("remedialActionReason").toString();
	}

	return std::nullopt;
}

std::optional<QString> MDRDao::queryRemedialActionScope(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("remedialActionScope").toString();
	}

	return std::nullopt;
}

std::optional<uint32_t> MDRDao::queryProjectCost(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("projectCost").toUInt();
	}

	return std::nullopt;
}

std::optional<QString> MDRDao::queryFundingSource(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("fundingSource").toString();
	}

	return std::nullopt;
}

std::optional<QString> MDRDao::queryRAQA(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM mdr WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("raqa").toString();
	}

	return std::nullopt;
}


void MDRDao::updateMDR(const QString& bridgeNumber, const MDR& info) {
	auto sql = QString("UPDATE mdr SET time = ?, type = ?, remedialActionReason = ?, remedialActionScope = ?, projectCost = ?, fundingSource = ?, RAQA = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(info.getTime());
	query.addBindValue(static_cast<int>(info.getType()));
	query.addBindValue(info.getRemedialActionReason());
	query.addBindValue(info.getRemedialActionScope());
	query.addBindValue(info.getProjectCost());
	query.addBindValue(info.getFundingSource());
	query.addBindValue(info.getRAQA());
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to update data for bridge '%1'").arg(bridgeNumber));
	}
}

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

void MDRDao::updateType(const QString& bridgeNumber, const MDR::RemedialActionType type) {
	auto sql = QString("UPDATE mdr SET type = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(static_cast<int>(type));
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update type '%1'").arg(static_cast<int>(type)));
	}
}

void MDRDao::updateRemedialActionReason(const QString& bridgeNumber, const QString& remedialActionReason) {
	auto sql = QString("UPDATE mdr SET remedialActionReason = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(remedialActionReason);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update remedial action reason '%1'").arg(remedialActionReason));
	}
}

void MDRDao::updateRemedialActionScope(const QString& bridgeNumber, const QString& remedialActionScope) {
	auto sql = QString("UPDATE mdr SET remedialActionScope = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(remedialActionScope);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update remedial action scope '%1'").arg(remedialActionScope));
	}
}

void MDRDao::updateProjectCost(const QString& bridgeNumber, uint32_t projectCost) {
	auto sql = QString("UPDATE mdr SET projectCost = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(projectCost);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update project cost '%1'").arg(projectCost));
	}
}

void MDRDao::updateFundingSource(const QString& bridgeNumber, const QString& fundingSource) {
	auto sql = QString("UPDATE mdr SET fundingSource = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(fundingSource);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update funding source '%1'").arg(fundingSource));
	}
}

void MDRDao::updateRAQA(const QString& bridgeNumber, const QString& RAQA) {
	auto sql = QString("UPDATE mdr SET raqa = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(RAQA);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update RAQA '%1'").arg(RAQA));
	}
}