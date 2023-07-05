#pragma once

#include <QString>
#include <optional>
#include <QSqlQuery>

#include "BTI.h"
#include "Logger.hpp"

class BTIDao {
public:
	// insert
	static void insertBTI(const QString& bridgeNumber, const BTI& bti);

	// delete
	static void deleteBTI(const QString& bridgeNumber);

	// query
	static std::optional<float> queryLength(const QString& bridgeNumber);
	static std::optional<float> queryWidth(const QString& bridgeNumber);
	static std::optional<float> queryLaneWidth(const QString& bridgeNumber);
	static std::optional<float> querySidewalkWidth(const QString& bridgeNumber);
	static std::optional<float> queryGuardrailHeight(const QString& bridgeNumber);
	static std::optional<float> queryMedianWidth(const QString& bridgeNumber);
	static std::optional<float> queryBVC(const QString& bridgeNumber);
	static std::optional<float> queryABC(const QString& bridgeNumber);
	static std::optional<float> queryAUC(const QString& bridgeNumber);
	static std::optional<float> queryARW(const QString& bridgeNumber);

	// update
	static void updateLength(const QString& bridgeNumber, float length);
	static void updateWidth(const QString& bridgeNumber, float width);
	static void updateLaneWidth(const QString& bridgeNumber, float laneWidth);
	static void updateSidewalkWidth(const QString& bridgeNumber, float sidewalkWidth);
	static void updateGuardrailHeight(const QString& bridgeNumber, float guardrailHeight);
	static void updateMedianWidth(const QString& bridgeNumber, float medianWidth);
	static void updateBVC(const QString& bridgeNumber, float BVC);
	static void updateABC(const QString& bridgeNumber, float ABC);
	static void updateAUC(const QString& bridgeNumber, float AUC);
	static void updateARW(const QString& bridgeNumber, float ARW);
};

