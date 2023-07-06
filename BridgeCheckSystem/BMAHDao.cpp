#include "BMAHDao.h"


void BMAHDao::insertBMAH(const QString& bridgeNumber, const BMAH& bmah) {
	auto sql = QString("INSERT INTO bmah (bridgeNumber, assessmentTime, type, result, remedialMeasures, \
nextInspectionTime) VALUES(?, ?, ?, ?, ?, ?);");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);
	query.addBindValue(bmah.getAssessmentTime());
	query.addBindValue(static_cast<int>(bmah.getType()));
	query.addBindValue(bmah.getResult());
	query.addBindValue(bmah.getRemedialMeasures());
	query.addBindValue(bmah.getNextInspectionTime());

	bool flag = query.exec();
	if (!flag) {
		CRITICAL("Failed to insert bmah");
	}
}

void BMAHDao::deleteBMAH(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM bmah WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	query.exec();
}

std::optional<BMAH> BMAHDao::queryBMAH(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bmah WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return BMAH(
			query.value("assessmentTime").toDateTime(),
			static_cast<BMAH::InspectionType>(query.value("type").toInt()),
			query.value("result").toString(),
			query.value("remedialMeasures").toString(),
			query.value("nextInspectionTime").toDateTime()
		);
	}

	return std::nullopt;
}

std::optional<QDateTime> BMAHDao::queryAssessmentTime(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bmah WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("assessmentTime").toDateTime();
	}

	return std::nullopt;
}

std::optional<BMAH::InspectionType> BMAHDao::queryType(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bmah WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return static_cast<BMAH::InspectionType>(query.value("type").toInt());
	}

	return std::nullopt;
}
std::optional<QString> BMAHDao::queryResult(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bmah WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("result").toString();
	}

	return std::nullopt;
}

std::optional<QString> BMAHDao::queryRemedialMeasures(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bmah WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("remedialMeasures").toString();
	}

	return std::nullopt;
}

std::optional<QDateTime> BMAHDao::queryNextInspectionTime(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bmah WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("nextInspectionTime").toDateTime();
	}

	return std::nullopt;
}


void BMAHDao::updateBMAH(const QString& bridgeNumber, const BMAH& info) {
	auto sql = QString("UPDATE bmah SET assessmentTime = ?, type = ?, result = ?, \
remedialMeasures = ?, nextInspectionTime = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(info.getAssessmentTime());
	query.addBindValue(static_cast<int>(info.getType()));
	query.addBindValue(info.getResult());
	query.addBindValue(info.getRemedialMeasures());
	query.addBindValue(info.getNextInspectionTime());
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to update data for bridge '%1'").arg(bridgeNumber));
	}
}


void BMAHDao::updateAssessmentTime(const QString& bridgeNumber, const QDateTime& assessmentTime) {
	auto sql = QString("UPDATE bmah SET assessmentTime = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(assessmentTime);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update '%1'").arg(assessmentTime.toString()));
	}
}

void BMAHDao::updateType(const QString& bridgeNumber, BMAH::InspectionType type) {
	auto sql = QString("UPDATE bmah SET type = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(static_cast<int>(type));
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update '%1'").arg(static_cast<int>(type)));
	}
}
void BMAHDao::updateResult(const QString& bridgeNumber, const QString& result) {
	auto sql = QString("UPDATE bmah SET result = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(result);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update result '%1'").arg(result));
	}
}

void BMAHDao::updateRemedialMeasures(const QString& bridgeNumber, const QString& remedialMeasures) {
	auto sql = QString("UPDATE bmah SET remedialMeasures = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(remedialMeasures);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update remedial measures '%1'").arg(remedialMeasures));
	}
}

void BMAHDao::updateNextInspectionTime(const QString& bridgeNumber, const QDateTime& nextInspectionTime) {
	auto sql = QString("UPDATE bmah SET nextInspectionTime = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(nextInspectionTime);
	query.addBindValue(bridgeNumber);

	if (!query.exec()) {
		CRITICAL(QString("Failed to update next inspection time '%1'").arg(nextInspectionTime.toString()));
	}
}