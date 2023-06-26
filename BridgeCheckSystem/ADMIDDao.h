#pragma once

#include <QString>
#include <QDateTime>
#include <optional>
#include <QSqlQuery>

#include "ADMID.h"
#include "Logger.hpp"

class ADMIDDao {
public:
	// insert
	static void insertADMID(const ADMID& admid);

	// delete
	static void deleteADMID(const QString& bridgeNumber);

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

	// updata
	static void updateBridgeName(const QString& bridgeNumber, const QString& bridgeName);
	static void updateRouteName(const QString& bridgeNumber, const QString& routeName);
	static void updateType(const QString& bridgeNumber, ADMID::Type type);
	static void updateRouteLevel(const QString& bridgeNumber, ADMID::RouteLevel routeLevel);
	static void updateFunctionType(const QString& bridgeNumber, ADMID::FunctionType functionType);
	static void updateLnglat(const QString& bridgeNumber, const QPair<float, float>& lnglat);
	static void updateBuildTime(const QString& bridgeNumber, const QDateTime& buildTime);
	static void updateDesignLoad(const QString& bridgeNumber, float designLoad);
	static void updateGrade(const QString& bridgeNumber, float grade);
	static void updateDesignUnit(const QString& bridgeNumber, const QString& designUnit);
	static void updateConstructorUnit(const QString& bridgeNumber, const QString& constructorUnit);
	static void updateSupervisoryUnit(const QString& bridgeNumber, const QString& supervisoryUnit);
	static void updateOwnerUnit(const QString& bridgeNumber, const QString& ownerUnit);
	static void updateManagementUnit(const QString& bridgeNumber, const QString& managementUnit);
};

