#pragma once

#include <QString>
#include <QDateTime>
#include <optional>
#include <QSqlQuery>

#include "BMAH.h"
#include "Logger.hpp"

class BMAHDao {
public:
	// insert
	static void insertBMAH(const QString& bridgeNumber, const BMAH& bmah);

	// delete
	static void deleteBMAH(const QString& bridgeNumber);

	// query
	static std::optional<BMAH> queryBMAH(const QString& bridgeNumber);
	static std::optional<QDateTime> queryAssessmentTime(const QString& bridgeNumber);
	static std::optional<BMAH::InspectionType> queryType(const QString& bridgeNumber);
	static std::optional<QString> queryResult(const QString& bridgeNumber);
	static std::optional<QString> queryRemedialMeasures(const QString& bridgeNumber);
	static std::optional<QDateTime> queryNextInspectionTime(const QString& bridgeNumber);

	// update
	static void updateBMAH(const QString& bridgeNumber, const BMAH& info);
	static void updateAssessmentTime(const QString& bridgeNumber, const QDateTime& assessmentTime);
	static void updateType(const QString& bridgeNumber, BMAH::InspectionType type);
	static void updateResult(const QString& bridgeNumber, const QString& result);
	static void updateRemedialMeasures(const QString& bridgeNumber, const QString& remedialMeasures);
	static void updateNextInspectionTime(const QString& bridgeNumber, const QDateTime& nextInspectionTime);
};

