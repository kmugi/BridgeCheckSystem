#pragma once

#include <QString>

#define GASR(type, funcname, valname) \
void set##funcname(const type& valname) noexcept { valname##_ = valname; } \
void set##funcname(type&& valname) noexcept { valname##_ = std::move(valname); } \
type get##funcname() const noexcept { return valname##_; }


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

	void setMainGirder(const QString& mainGirder) noexcept { mainGirder_ = mainGirder; }
	void setMainGirder(QString&& mainGirder) noexcept { mainGirder_ = std::move(mainGirder); }
	QString getMainGirder() const noexcept { return mainGirder_; }

	void setMainArchRib(const QString& mainArchRib) noexcept { mainArchRib_ = mainArchRib; }
	void setMainArchRib(QString&& mainArchRib) noexcept { mainArchRib_ = std::move(mainArchRib); }
	QString getMainArchRib() const noexcept { return mainArchRib_; }

	void setBridgeTower(const QString& bridgeTower) noexcept { bridgeTower_ = bridgeTower; }
	void setBridgeTower(QString&& bridgeTower) noexcept { bridgeTower_ = std::move(bridgeTower); }
	QString getBridgeTower() const noexcept { return bridgeTower_; }

	void setStructureAboveArch(const QString& structureAboveArch) noexcept { structureAboveArch_ = structureAboveArch; }
	void setStructureAboveArch(QString&& structureAboveArch) noexcept { structureAboveArch_ = std::move(structureAboveArch); }
	QString getStructureAboveArch() const noexcept { return structureAboveArch_; }

	void setMainCable(const QString& mainCable) noexcept { mainCable_ = mainCable; }
	void setMainCable(QString&& mainCable) noexcept { mainCable_ = std::move(mainCable); }
	QString getMainCable() const noexcept { return mainCable_; }

	void setBridgeSurfaceCoating(const QString& bridgeSurfaceCoating) noexcept { bridgeSurfaceCoating_ = bridgeSurfaceCoating; }
	void setBridgeSurfaceCoating(QString&& bridgeSurfaceCoating) noexcept { bridgeSurfaceCoating_ = std::move(bridgeSurfaceCoating); }
	QString getBridgeSurfaceCoating() const noexcept { return bridgeSurfaceCoating_; }

	void setSidewalk(const QString& sidewalk) noexcept { sidewalk_ = sidewalk; }
	void setSidewalk(QString&& sidewalk) noexcept { sidewalk_ = std::move(sidewalk); }
	QString getSidewalk() const noexcept { return sidewalk_; };

	void setLighting(const QString& lighting) noexcept { lighting_ = lighting; }
	void setLighting(QString&& lighting) noexcept { lighting_ = std::move(lighting); }
	QString getLighting() const noexcept { return lighting_; }

	void setConeSlope(const QString& coneSlope) noexcept { coneSlope_ = coneSlope; }
	void setConeSlope(QString&& coneSlope) noexcept { coneSlope_ = std::move(coneSlope); }
	QString getConeSlope() const noexcept { return coneSlope_; }

	void setWingWall(const QString& wingWall) noexcept { wingWall_ = wingWall; }
	void setWingWall(QString&& wingWall) noexcept { wingWall_ = std::move(wingWall); }
	QString getWingWall() const noexcept { return wingWall_; }

	void setFoundation(const QString& foundation) noexcept { foundation_ = foundation; }
	void setFoundation(QString&& foundation) noexcept { foundation_ = std::move(foundation); }
	QString getFoundation() const noexcept { return foundation_; }

	void setBearing(const QString& bearing) noexcept { bearing_ = bearing; }
	void setBearing(QString&& bearing) noexcept { bearing_ = std::move(bearing); }
	QString getBearing() const noexcept { return bearing_; }

	void setCrashBarrier(const QString& crashBarrier) noexcept { crashBarrier_ = crashBarrier; }
	void setCrashBarrier(QString&& crashBarrier) noexcept { crashBarrier_ = std::move(crashBarrier); }
	QString getCrashBarrier() const noexcept { return crashBarrier_; }

	void setBeacon(const QString& beacon) noexcept { beacon_ = beacon; }
	void setBeacon(QString&& beacon) noexcept { beacon_ = std::move(beacon); }
	QString getBeacon() const noexcept { return beacon_; }


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

