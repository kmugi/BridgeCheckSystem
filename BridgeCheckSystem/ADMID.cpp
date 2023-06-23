#include "ADMID.h"

ADMID::ADMID(
	const QString& HASC,
	const QString& bridgeName,
	const QString& bridgeNumber,
	const QString& routeName,
	const QString& routeNumber,
	Type type,
	RouteLevel routeLevel,
	FunctionType funcType,
	const QPair<float, float>& lnglat,
	const QDateTime& buildTime,
	float designLoad,
	float grade,
	const QString& designUnit,
	const QString& constructorUnit,
	const QString& supervisoryUnit,
	const QString& ownerUnit,
	const QString& managementUnit
) noexcept :
	HASC_(HASC),
	bridgeName_(bridgeName),
	bridgeNumber_(bridgeNumber),
	routeName_(routeName),
	routeNumber_(routeNumber),
	type_(type),
	routeLevel_(routeLevel),
	funcType_(funcType),
	lnglat_(lnglat),
	buildTime_(buildTime),
	designLoad_(designLoad),
	grade_(grade),
	designUnit_(designUnit),
	constructorUnit_(constructorUnit),
	supervisoryUnit_(supervisoryUnit),
	ownerUnit_(ownerUnit),
	managementUnit_(managementUnit)
{}

ADMID::ADMID(
	QString&& HASC,
	QString&& bridgeName,
	QString&& bridgeNumber,
	QString&& routeName,
	QString&& routeNumber,
	Type type,
	RouteLevel routeLevel,
	FunctionType funcType,
	QPair<float, float>&& lnglat,
	QDateTime&& buildTime,
	float designLoad,
	float grade,
	QString&& designUnit,
	QString&& constructorUnit,
	QString&& supervisoryUnit,
	QString&& ownerUnit,
	QString&& managementUnit
) noexcept :
	HASC_(std::move(HASC)),
	bridgeName_(std::move(bridgeName)),
	bridgeNumber_(std::move(bridgeNumber)),
	routeName_(std::move(routeName)),
	routeNumber_(std::move(routeNumber)),
	type_(type),
	routeLevel_(routeLevel),
	funcType_(funcType),
	lnglat_(std::move(lnglat)),
	buildTime_(std::move(buildTime)),
	designLoad_(designLoad),
	grade_(grade),
	designUnit_(std::move(designUnit)),
	constructorUnit_(std::move(constructorUnit)),
	supervisoryUnit_(std::move(supervisoryUnit)),
	ownerUnit_(std::move(ownerUnit)),
	managementUnit_(std::move(managementUnit))
{}