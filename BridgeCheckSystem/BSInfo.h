#pragma once

#include <QString>

// 桥梁结构信息
// bridge structural information
class BSInfo {
public:
	BSInfo() = delete;
	BSInfo(
		const QString& mainGirder,
		const QString& maiArchRib,
		const QString& bridgeTower,
		const QString& structureAboveArch,
		const QString& mainCable,
		const QString& bridgeSurfaceCoating,
		const QString& sidewalk,
		const QString& lighting,
		const QString& coneSlope,
		const QString& wingWall,
		const QString& foundation,
		const QString& bearing,
		const QString& crashBarrier,
		const QString& beacon
	) noexcept;

	BSInfo(
		QString&& mainGirder,
		QString&& mainArchRib,
		QString&& bridgeTower,
		QString&& structureAboveArch,
		QString&& mainCable,
		QString&& bridgeSurfaceCoating,
		QString&& sidewalk,
		QString&& lighting,
		QString&& coneSlope,
		QString&& wingWall,
		QString&& foundation,
		QString&& bearing,
		QString&& crashBarrier,
		QString&& beacon
	) noexcept;

	// TODO: getter and setter

private:
	// 上部
	QString mainGirder_;				// 主梁
	QString mainArchRib_;				// 主拱圈
	QString bridgeTower_;				// 桥塔
	QString structureAboveArch_;		// 拱上建筑
	QString mainCable_;					// 主缆

	// 桥面
	QString bridgeSurfaceCoating_;		// 桥面铺装
	QString sidewalk_;					// 人行道
	QString lighting_;					// 照明

	// 下部
	QString coneSlope_;					// 锥坡
	QString wingWall_;					// 翼墙

	// 基础
	QString foundation_;				// 基础

	// 支座
	QString bearing_;					// 支座
	QString crashBarrier_;				// 防撞设施
	QString beacon_;					// 航标
};

