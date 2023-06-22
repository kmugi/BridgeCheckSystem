#pragma once

#include <QString>
#include <QDateTime>

#define GAS(type, funcname, valname) \
void set##funcname(type valname) noexcept { valname##_ = valname; } \
type get##funcname() const noexcept { return valname##_; }

#define GASR(type, funcname, valname) \
void set##funcname(const type& valname) noexcept { valname##_ = valname; } \
void set##funcname(type&& valname) noexcept { valname##_ = std::move(valname); } \
type get##funcname() const noexcept { return valname##_; }

// 行政识别数据
// administrative identification data
class ADMID {
public:
	enum class Type {
		Beam = 0,			 // 梁式桥
		BoardArch,			 // 板拱桥
		DoubleCurvedArch,    // 双曲拱桥
		RigidConcreteArch,	 // 钢-混凝土组合拱桥
		CableStayed,		 // 斜拉桥
		Suspension,			 // 悬索桥
	};

	enum class RouteLevel {
		National,	// 国道
		Provincial, // 省道
		County,		// 县道
	};

	enum class FunctionType {
		Road = 1 << 0,		// 公路
		RailWay = 1 << 1,	// 铁路
	};

public:
	ADMID() = delete;
	ADMID(
		const QString& HASC,
		const QString& bridgeName,
		const QString& bridgeNumber,
		const QString& routeName,
		const QString& routeNumber,
		Type type,
		RouteLevel routeLevel,
		const QPair<float, float>& lnglat,
		const QString& designUnit,
		const QString& constructorUnit,
		const QString& supervisoryUnit,
		const QString& ownerUnit,
		const QString& managementUnit
	) noexcept;

	ADMID(
		QString&& HASC,
		QString&& bridgeName,
		QString&& bridgeNumber,
		QString&& routeName,
		QString&& routeNumber,
		Type type,
		RouteLevel routeLevel,
		QPair<float, float>&& lnglat,
		QString&& designUnit,
		QString&& constructorUnit,
		QString&& supervisoryUnit,
		QString&& ownerUnit,
		QString&& managementUnit
	) noexcept;

	void setHASC(const QString& HASC) noexcept { HASC_ = HASC; }
	void setHASC(QString&& HASC) noexcept { HASC_ = std::move(HASC); }
	QString getHASC() const noexcept { return HASC_; }

	void setBridgeName(const QString& bridgeName) noexcept { bridgeName_ = bridgeName; }
	void setBridgeName(QString&& bridgeName) noexcept { bridgeName_ = std::move(bridgeName); }
	QString getBridgeName() const noexcept { return bridgeName_; }

	void setBridgeNumber(const QString& bridgeNumber) noexcept { bridgeNumber_ = bridgeNumber; }
	void setBridgeNumber(QString&& bridgeNumber) noexcept { bridgeNumber_ = std::move(bridgeNumber); }
	QString getBridgeNumber() const noexcept { return bridgeNumber_; }

	void setRouteName(const QString& routeName) noexcept { routeName_ = routeName; }
	void setRouteName(QString&& routeName) noexcept { routeName_ = std::move(routeName); }
	QString getRouteName() const noexcept { return routeName_; }

	void setRouteNumber(const QString& routeNumber) noexcept { routeNumber_ = routeNumber; }
	void setRouteNumber(QString&& routeNumber) noexcept { routeNumber_ = std::move(routeNumber); }
	QString getRouteNumber() const noexcept { return routeNumber_; }

	void setType(Type type) noexcept { type_ = type; }
	Type getType() const noexcept { return type_; }

	void setRouteLevel(RouteLevel routeLevel) noexcept { routeLevel_ = routeLevel; }
	RouteLevel getRouteLevel() const noexcept { return routeLevel_; }

	void setFuncType(FunctionType funcType) noexcept { funcType_ = funcType; }
	FunctionType getFuncType() const noexcept { return funcType_; }

	void setLnglat(const QPair<float, float>& lnglat) noexcept { lnglat_ = lnglat; }
	void setLnglat(QPair<float, float>&& lnglat) noexcept { lnglat_ = std::move(lnglat); }
	QPair<float, float> getLnglat() const noexcept { return lnglat_; }

	void setBuildTime(const QDateTime& buildTime) noexcept { buildTime_ = buildTime; }
	void setBuildTime(QDateTime&& buildTime) noexcept { buildTime_ = std::move(buildTime); }
	QDateTime getBuildTime() const noexcept { return buildTime_; }

	void setDesignLoad(float designLoad) noexcept { designLoad_ = designLoad; }
	float getDesignLoad() const noexcept { return designLoad_; }

	void setGrade(float grade) noexcept { grade_ = grade; }
	float getGrade() const noexcept { return grade_; }

	void setDesignUnit(const QString& designUnit) noexcept { designUnit_ = designUnit; }
	void setDesignUnit(QString&& designUnit) noexcept { designUnit_ = std::move(designUnit); }
	QString getDesignUnit() const noexcept { return designUnit_; }

	void setConstructorUnit(const QString& constructorUnit) noexcept { constructorUnit_ = constructorUnit; }
	void setConstructorUnit(QString&& constructorUnit) noexcept { constructorUnit_ = std::move(constructorUnit); }
	QString getConstructorUnit() const noexcept { return constructorUnit_; }

	void setSupervisoryUnit(const QString& supervisoryUnit) noexcept { supervisoryUnit_ = supervisoryUnit; }
	void setSupervisoryUnit(QString&& supervisoryUnit) noexcept { supervisoryUnit_ = std::move(supervisoryUnit); }
	QString getSupervisoryUnit() const noexcept { return supervisoryUnit_; }

	void setOwnerUnit(const QString& ownerUnit) noexcept { ownerUnit_ = ownerUnit; }
	void setOwnerUnit(QString&& ownerUnit) noexcept { ownerUnit_ = std::move(ownerUnit); }
	QString getOwnerUnit() const noexcept { return ownerUnit_; }

	void setManagementUnit(const QString& managementUnit) noexcept { managementUnit_ = managementUnit; }
	void setManagementUnit(QString&& managementUnit) noexcept { managementUnit_ = std::move(managementUnit); }
	QString getManagementUnit() const noexcept { return managementUnit_; }

private:
	QString HASC_;	// 行政区划代码

	QString bridgeName_;
	QString bridgeNumber_;

	QString routeName_;
	QString routeNumber_;

	Type type_;
	RouteLevel routeLevel_;
	FunctionType funcType_;

	QPair<float, float> lnglat_;

	QDateTime buildTime_;

	float designLoad_;	// 设计承载重量
	float grade_;		// 坡度

	// 单位
	QString designUnit_;		// 设计
	QString constructorUnit_;	// 施工
	QString supervisoryUnit_;	// 监理
	QString ownerUnit_;			// 业主
	QString managementUnit_;	// 管养
};

