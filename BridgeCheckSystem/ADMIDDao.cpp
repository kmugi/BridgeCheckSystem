#include "ADMIDDao.h"

void ADMIDDao::insertADMID(const ADMID& admid) {
	auto sql = QString("INSERT INTO admid (bridgeName, bridgeNumber, \
routeName, routeNumber, HSAC, type, routeLevel, functionType, lng, lat, \
buildTime, designLoad, grade, designUnit, constructorUnit, supervisoryUnit, \
ownerUnit, managementUnit) VALUES ('%1', '%2', '%3', '%4', '%5', %6, %7, %8, %9, %10, \
'%11', %12, %13, '%14', '%15', '%16', '%17', '%18');")
.arg(admid.getBridgeName())
.arg(admid.getBridgeNumber())
.arg(admid.getRouteName())
.arg(admid.getRouteNumber())
.arg(admid.getHASC())
.arg(static_cast<int>(admid.getType()))
.arg(static_cast<int>(admid.getRouteLevel()))
.arg(static_cast<int>(admid.getFuncType()))
.arg(admid.getLnglat().first)
.arg(admid.getLnglat().second)
.arg(admid.getBuildTime().toString("yyyy-MM-dd HH:mm:ss"))
.arg(admid.getDesignLoad())
.arg(admid.getGrade())
.arg(admid.getDesignUnit())
.arg(admid.getConstructorUnit())
.arg(admid.getSupervisoryUnit())
.arg(admid.getOwnerUnit())
.arg(admid.getManagementUnit());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL("Failed to insert ADMID");
	}
}

void ADMIDDao::deleteADMID(const QString& bridgeNumber) {
	auto sql = QString("DELETE * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL("Failed to delete ADMID");
	}
}

std::optional<QString> ADMIDDao::queryBridgeNumber(const QString& bridgeName) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeName = '%1';").arg(bridgeName.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("bridgeNumber").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryBridgeName(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("bridgeName").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryRouteName(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("routeName").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryRouteNumber(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("routeNumber").toString();
	}

	return std::nullopt;
}

std::optional<ADMID::Type> ADMIDDao::queryType(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return static_cast<ADMID::Type>(query.value("type").toInt());
	}

	return std::nullopt;
}

std::optional<ADMID::RouteLevel> ADMIDDao::queryRouteLevel(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return static_cast<ADMID::RouteLevel>(query.value("routeLevel").toInt());
	}

	return std::nullopt;
}

std::optional<ADMID::FunctionType> ADMIDDao::queryFunctionType(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return static_cast<ADMID::FunctionType>(query.value("functionType").toInt());
	}

	return std::nullopt;
}

std::optional<QPair<float, float>> ADMIDDao::queryLnglat(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return std::make_pair(query.value("lng").toFloat(), query.value("lat").toFloat());
	}

	return std::nullopt;
}

std::optional<QDateTime> ADMIDDao::queryBuildTime(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("buildTime").toDateTime();
	}

	return std::nullopt;
}

std::optional<float> ADMIDDao::queryDesignLoad(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("designLoad").toFloat();
	}

	return std::nullopt;
}

std::optional<float> ADMIDDao::queryGrade(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("grade").toFloat();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryDesignUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("designUnit").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryConstructorUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("constructorUnit").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::querySupervisoryUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("supervisoryUnit").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryOwnerUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("ownerUnit").toString();
	}

	return std::nullopt;

}

std::optional<QString> ADMIDDao::queryManagementUnit(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1';").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("managementUnit").toString();
	}

	return std::nullopt;
}

void ADMIDDao::updataBridgeName(const QString& bridgeNumber, const QString& bridgeName) {
	auto sql = QString("UPDATA admid SET bridgeName = '%1', WHERE bridgeNumber = '%2';")
		.arg(bridgeName.trimmed())
		.arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(bridgeName.trimmed()));
	}
}
void ADMIDDao::updataRouteName(const QString& bridgeNumber, const QString& routeName) {
	auto sql = QString("UPDATA admid SET routeName = '%1', WHERE bridgeNumber = '%2';")
		.arg(routeName.trimmed())
		.arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(routeName.trimmed()));
	}
}
void ADMIDDao::updataDesignUnit(const QString& bridgeNumber, const QString& designUnit) {
	auto sql = QString("UPDATA admid SET routeName = '%1', WHERE bridgeNumber = '%2';")
		.arg(designUnit.trimmed())
		.arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(designUnit.trimmed()));
	}

}
void ADMIDDao::updataSupervisoryUnit(const QString& bridgeNumber, const QString& supervisoryUnit) {
	auto sql = QString("UPDATA admid SET routeName = '%1', WHERE bridgeNumber = '%2';")
		.arg(supervisoryUnit.trimmed())
		.arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(supervisoryUnit.trimmed()));
	}
}
void ADMIDDao::updataConstructorUnit(const QString & bridgeNumber, const QString & constructorUnit) {
	auto sql = QString("UPDATA admid SET routeName = '%1', WHERE bridgeNumber = '%2';")
		.arg(constructorUnit.trimmed())
		.arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(constructorUnit.trimmed()));
	}
}
void ADMIDDao::updataOwnerUnit(const QString& bridgeNumber, const QString& ownerUnit) {
	auto sql = QString("UPDATA admid SET routeName = '%1', WHERE bridgeNumber = '%2';")
		.arg(ownerUnit.trimmed())
		.arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(ownerUnit.trimmed()));
	}
}
void ADMIDDao::updataManagementUnit(const QString& bridgeNumber, const QString& managementUnit) {
	auto sql = QString("UPDATA admid SET routeName = '%1', WHERE bridgeNumber = '%2';")
		.arg(managementUnit.trimmed())
		.arg(bridgeNumber.trimmed());

	DEBUG(sql);

	bool isSuccess = QSqlQuery(sql).exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to updata '%1'").arg(managementUnit.trimmed()));
	}
}
	
