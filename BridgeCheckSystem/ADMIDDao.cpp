#include "ADMIDDao.h"

void ADMIDDao::insertADMID(const ADMID& admid) {
	auto sql = QString("INSERT INTO admid (bridgeName, bridgeNumber, \
routeName, routeNumber, HSAC, type, routeLevel, functionType, lng, lat, \
buildTime, designLoad, grade, designUnit, constructorUnit, supervisoryUnit, \
ownerUnit, managementUnit) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, \
?, ?, ?, ?, ?);");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(admid.getBridgeName());
	query.addBindValue(admid.getBridgeNumber());
	query.addBindValue(admid.getRouteName());
	query.addBindValue(admid.getRouteNumber());
	query.addBindValue(admid.getHASC());
	query.addBindValue(static_cast<int>(admid.getType()));
	query.addBindValue(static_cast<int>(admid.getRouteLevel()));
	query.addBindValue(static_cast<int>(admid.getFuncType()));
	query.addBindValue(admid.getLnglat().first);
	query.addBindValue(admid.getLnglat().second);
	query.addBindValue(admid.getBuildTime());
	query.addBindValue(admid.getDesignLoad());
	query.addBindValue(admid.getGrade());
	query.addBindValue(admid.getDesignUnit());
	query.addBindValue(admid.getConstructorUnit());
	query.addBindValue(admid.getSupervisoryUnit());
	query.addBindValue(admid.getOwnerUnit());
	query.addBindValue(admid.getManagementUnit());

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL("Failed to insert ADMID");
	}
}

void ADMIDDao::deleteADMID(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL("Failed to delete ADMID");
	}
}

std::optional<QVector<QString>> ADMIDDao::queryAllBridgeNames() {
	auto sql = QString("SELECT * FROM admid");
	DEBUG(sql);

	QSqlQuery query{};
	QVector<QString> res;
	query.prepare(sql);

	query.exec();
	while (query.next()) {
		res.emplace_back(
			query.value("bridgeName").toString()
		);
	}

	return res.isEmpty() ? std::nullopt : std::make_optional(res);
}

std::optional<ADMID> ADMIDDao::queryADMID(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return ADMID(
			query.value("HSAC").toString(),
			query.value("bridgeName").toString(),
			query.value("bridgeNumber").toString(),
			query.value("routeName").toString(),
			query.value("routeNumber").toString(),
			static_cast<ADMID::Type>(query.value("type").toInt()),
			static_cast<ADMID::RouteLevel>(query.value("routeLevel").toInt()),
			static_cast<ADMID::FunctionType>(query.value("functionType").toInt()),
			{ query.value("lng").toFloat(), query.value("lat").toFloat() },
			query.value("buildTime").toDateTime(),
			query.value("designLoad").toFloat(),
			query.value("grade").toFloat(),
			query.value("designUnit").toString(),
			query.value("constructorUnit").toString(),
			query.value("supervisoryUnit").toString(),
			query.value("ownerUnit").toString(),
			query.value("managementUnit").toString()
		);
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryBridgeNumber(const QString& bridgeName) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeName = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeName);

	if (query.exec() && query.next()) {
		return query.value("bridgeNumber").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryBridgeName(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("bridgeName").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryRouteName(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("routeName").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryRouteNumber(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("routeNumber").toString();
	}

	return std::nullopt;
}

std::optional<ADMID::Type> ADMIDDao::queryType(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return static_cast<ADMID::Type>(query.value("type").toInt());
	}

	return std::nullopt;
}

std::optional<ADMID::RouteLevel> ADMIDDao::queryRouteLevel(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return static_cast<ADMID::RouteLevel>(query.value("routeLevel").toInt());
	}

	return std::nullopt;
}

std::optional<ADMID::FunctionType> ADMIDDao::queryFunctionType(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return static_cast<ADMID::FunctionType>(query.value("functionType").toInt());
	}

	return std::nullopt;
}

std::optional<QPair<float, float>> ADMIDDao::queryLnglat(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return std::make_pair(query.value("lng").toFloat(), query.value("lat").toFloat());
	}

	return std::nullopt;
}

std::optional<QDateTime> ADMIDDao::queryBuildTime(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("buildTime").toDateTime();
	}

	return std::nullopt;
}

std::optional<float> ADMIDDao::queryDesignLoad(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("designLoad").toFloat();
	}

	return std::nullopt;
}

std::optional<float> ADMIDDao::queryGrade(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("grade").toFloat();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryDesignUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("designUnit").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryConstructorUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("constructorUnit").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::querySupervisoryUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("supervisoryUnit").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryOwnerUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("ownerUnit").toString();
	}

	return std::nullopt;

}

std::optional<QString> ADMIDDao::queryManagementUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("managementUnit").toString();
	}

	return std::nullopt;
}

void ADMIDDao::updateADMID(const QString& bridgeNumber, const ADMID& info) {
	auto sql = QString("UPDATE admid SET bridgeName = ?, routeName = ?, routeNumber = ?, HSAC = ?, type = ?, \
routeLevel = ?, functionType = ?, lng = ?, lat = ?, buildTime = ?, designLoad = ?, grade = ?, designUnit = ?, \
constructorUnit = ?, supervisoryUnit = ?, ownerUnit = ?, managementUnit = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(info.getBridgeName());
	query.addBindValue(info.getRouteName());
	query.addBindValue(info.getRouteNumber());
	query.addBindValue(info.getHASC());
	query.addBindValue(static_cast<int>(info.getType()));
	query.addBindValue(static_cast<int>(info.getRouteLevel()));
	query.addBindValue(static_cast<int>(info.getFuncType()));
	query.addBindValue(info.getLnglat().first);
	query.addBindValue(info.getLnglat().second);
	query.addBindValue(info.getBuildTime());
	query.addBindValue(info.getDesignLoad());
	query.addBindValue(info.getGrade());
	query.addBindValue(info.getDesignUnit());
	query.addBindValue(info.getConstructorUnit());
	query.addBindValue(info.getSupervisoryUnit());
	query.addBindValue(info.getOwnerUnit());
	query.addBindValue(info.getManagementUnit());
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to update fields for bridge '%1'").arg(bridgeNumber));
	}
}

void ADMIDDao::updateBridgeName(const QString& bridgeNumber, const QString& bridgeName) {
	auto sql = QString("UPDATE admid SET bridgeName = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeName);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(bridgeName.trimmed()));
	}
}

void ADMIDDao::updateRouteName(const QString& bridgeNumber, const QString& routeName) {
	auto sql = QString("UPDATE admid SET routeName = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(routeName);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(routeName.trimmed()));
	}
}

void ADMIDDao::updateType(const QString& bridgeNumber, ADMID::Type type) {
	auto sql = QString("UPDATE admid SET type = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(static_cast<int>(type));
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(QString::number(static_cast<int>(type))));
	}
}

void ADMIDDao::updateRouteLevel(const QString& bridgeNumber, ADMID::RouteLevel routeLevel) {
	auto sql = QString("UPDATE admid SET routeLevel = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(static_cast<int>(routeLevel));
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(QString::number(static_cast<int>(routeLevel))));
	}
}

void ADMIDDao::updateFunctionType(const QString& bridgeNumber, ADMID::FunctionType functionType) {
	auto sql = QString("UPDATE admid SET functionType = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(static_cast<int>(functionType));
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(QString::number(static_cast<int>(functionType))));
	}
}

void ADMIDDao::updateLnglat(const QString& bridgeNumber, const QPair<float, float>& lnglat) {
	auto sql = QString("UPDATE admid SET lng = ?, lat = ? WHERE bridgeNumber = ?");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(lnglat.first);
	query.addBindValue(lnglat.second);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1', '%2'")
			.arg(QString::number(lnglat.first, 'f', 3))
			.arg(QString::number(lnglat.second, 'f', 3))
		);
	}
}

void ADMIDDao::updateBuildTime(const QString& bridgeNumber, const QDateTime& buildTime) {
	auto sql = QString("UPDATE admid SET buildTime = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(buildTime);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(buildTime.toString("yyyy-MM-dd HH:mm:ss")));
	}
}

void ADMIDDao::updateDesignLoad(const QString& bridgeNumber, float designLoad) {
	auto sql = QString("UPDATE admid SET designLoad = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(designLoad);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(QString::number(designLoad, 'f', 5)));
	}
}

void ADMIDDao::updateGrade(const QString& bridgeNumber, float grade) {
	auto sql = QString("UPDATE admid SET grade = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(grade);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(QString::number(grade, 'f', 5)));
	}
}

void ADMIDDao::updateDesignUnit(const QString& bridgeNumber, const QString& designUnit) {
	auto sql = QString("UPDATE admid SET designUnit = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(designUnit);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(designUnit.trimmed()));
	}
}

void ADMIDDao::updateSupervisoryUnit(const QString& bridgeNumber, const QString& supervisoryUnit) {
	auto sql = QString("UPDATE admid SET supervisoryUnit = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(supervisoryUnit);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(supervisoryUnit.trimmed()));
	}
}

void ADMIDDao::updateConstructorUnit(const QString& bridgeNumber, const QString& constructorUnit) {
	auto sql = QString("UPDATE admid SET constructorUnit = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(constructorUnit);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(constructorUnit.trimmed()));
	}
}

void ADMIDDao::updateOwnerUnit(const QString& bridgeNumber, const QString& ownerUnit) {
	auto sql = QString("UPDATE admid SET ownerUnit = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(ownerUnit);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(ownerUnit.trimmed()));
	}
}

void ADMIDDao::updateManagementUnit(const QString& bridgeNumber, const QString& managementUnit) {
	auto sql = QString("UPDATE admid SET managementUnit = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(managementUnit);
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(managementUnit.trimmed()));
	}
}

