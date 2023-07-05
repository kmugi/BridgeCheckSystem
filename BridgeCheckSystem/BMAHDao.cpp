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

//TODO: query


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

//TODO: update