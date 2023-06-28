#pragma once

#include <QString>
#include <QDateTime>
#include <optional>

#include "MDR.h"

class MDRDao {
	// insert
	static void insertMDR(const QString& bridgeNumber, const MDR& mdr);

	// delete
	static void deleteMDR(const QString& bridgeNumber);

	// query
	static std::optional<QDateTime> queryTime(const QString& bridgeNumber);
	static std::optional<MDR::RemedialActionType> queryType(const QString& bridgeNumber);
	static std::optional<QString> queryRemedialActionReason(const QString& bridgeNumber);
	static std::optional<QString> queryRemedialActionScope(const QString& bridgeNumber);
	static std::optional<uint32_t> queryProjectCost(const QString& bridgeNumber);
	static std::optional<QString> queryFundingSource(const QString& bridgeNumber);
	static std::optional<QString> queryRAQA(const QString& bridgeNumber);

	// update
	static void updateTime(const QString& bridgeNumber, const QDateTime& time);
	static void updateType(const QString& bridgeNumber, const MDR::RemedialActionType type);
	static void updateRemedialActionReason(const QString& bridgeNumber, const QString& remedialActionReason);
	static void updateRemedialActionScope(const QString& bridgeNumber, const QString& remedialActionScope);
	static void updateProjectCost(const QString& bridgeNumber, uint32_t projectCost);
	static void updateFundingSource(const QString& bridgeNumber, const QString& fundingSource);
	static void updateRAQA(const QString& bridgeNumber, const QString& RAQA);
};

