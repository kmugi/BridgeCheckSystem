#pragma once

#include <QString>
#include <optional>
#include <QSqlQuery>

#include "BSInfo.h"
#include "Logger.hpp"

class BSInfoDao {
public:
	// insert
	static void insertBSInfo(const QString& bridgeNumber, const BSInfo& bsInfo);

	// delete
	static void deleteBSInfo(const QString& bridgeNumber);

	// query
	static std::optional<BSInfo> queryBSInfo(const QString& bridgeNumber);
	static std::optional<QString> queryMainGirder(const QString& bridgeNumber);
	static std::optional<QString> queryMainArchRib(const QString& bridgeNumber);
	static std::optional<QString> queryBridgeTower(const QString& bridgeNumber);
	static std::optional<QString> queryStructureAboveArch(const QString& bridgeNumber);
	static std::optional<QString> queryMainCable(const QString& bridgeNumber);
	static std::optional<QString> queryBridgeSurfaceCoating(const QString& bridgeNumber);
	static std::optional<QString> querySidewalk(const QString& bridgeNumber);
	static std::optional<QString> queryLighting(const QString& bridgeNumber);
	static std::optional<QString> queryConeSlope(const QString& bridgeNumber);
	static std::optional<QString> queryWingWall(const QString& bridgeNumber);
	static std::optional<QString> queryFoundation(const QString& bridgeNumber);
	static std::optional<QString> queryBearing(const QString& bridgeNumber);
	static std::optional<QString> queryCrashBarrier(const QString& bridgeNumber);
	static std::optional<QString> queryBeacon(const QString& bridgeNumber);

	// update
	static void updateBSInfo(const QString& bridgeNumber, const BSInfo& info);
	static void updateMainGirder(const QString& bridgeNumber, const QString& mainGirder);
	static void updateMainArchRib(const QString& bridgeNumber, const QString& mainArchRib);
	static void updateBridgeTower(const QString& bridgeNumber, const QString& bridgeTower);
	static void updateStructureAboveArch(const QString& bridgeNumber, const QString& structureAboveArch);;
	static void updateMainCable(const QString& bridgeNumber, const QString& mainCable);
	static void updateBridgeSurfaceCoating(const QString& bridgeNumber, const QString& bridgeSurfaceCoating);
	static void updateSidewalk(const QString& bridgeNumber, const QString& sidewalk);
	static void updateLighting(const QString& bridgeNumber, const QString& lighting);
	static void updateConeSlope(const QString& bridgeNumber, const QString& coneSlope);
	static void updateWingWall(const QString& bridgeNumber, const QString& wingWall);
	static void updateFoundation(const QString& bridgeNumber, const QString& foundation);
	static void updateBearing(const QString& bridgeNumber, const QString& bearing);
	static void updateCrashBarrier(const QString& bridgeNumber, const QString& crashBarrier);
	static void updateBeacon(const QString& bridgeNumber, const QString& beacon);
};

