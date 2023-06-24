#pragma once

#include <QString>
#include <QDateTime>
#include <optional>
#include <QSqlQuery>

#include "ADMID.h"
#include "Logger.hpp"

class ADMIDDao {
public:
	// query
	static std::optional<QString> queryBridgeNumber(const QString& bridgeName);
	static std::optional<QString> queryBridgeName(const QString& bridgeNumber);
	static std::optional<QString> queryRouteName(const QString& bridgeNumber);
	static std::optional<QString> queryRouteNumber(const QString& bridgeNumber);
	static std::optional<ADMID::Type> queryType(const QString& bridgeNumber);
	static std::optional<ADMID::RouteLevel> queryRouteLevel(const QString& bridgeNumber);
	static std::optional<ADMID::FunctionType> queryFunctionType(const QString& bridgeNumber);
	static std::optional<QPair<float, float>> queryLnglat(const QString& bridgeNumber);
	static std::optional<QDateTime> queryBuildTime(const QString& bridgeNumber);
	static std::optional<float> queryDesignLoad(const QString& bridgeNumber);
	static std::optional<float> queryGrade(const QString& bridgeNumber);
	static std::optional<QString> queryDesignUnit(const QString& bridgeNumber);
	static std::optional<QString> queryConstructorUnit(const QString& bridgeNumber);
	static std::optional<QString> querySupervisoryUnit(const QString& bridgeNumber);
	static std::optional<QString> queryOwnerUnit(const QString& bridgeNumber);
	static std::optional<QString> queryManagementUnit(const QString& bridgeNumber);
};

