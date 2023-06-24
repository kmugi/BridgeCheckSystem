#include "ADMIDDao.h"

std::optional<QString> ADMIDDao::queryBridgeNumber(const QString& bridgeName) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeName = '%1'").arg(bridgeName.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("bridgeNumber").toString();
	}

	return std::nullopt;
}

std::optional<QString> ADMIDDao::queryBridgeName(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	DEBUG(sql);

	QSqlQuery query{ sql };
	if (query.next()) {
		return query.value("bridgeName").toString();
	}

	return std::nullopt;
}
 std::optional<QString> ADMIDDao::queryRouteName(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("routeName").toString();
	 }

	 return std::nullopt;
}
 std::optional<QString> ADMIDDao::queryRouteNumber(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("routeNumber").toString();
	 }

	 return std::nullopt;
}
 std::optional<QDateTime> ADMIDDao::queryBuildTime(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("buildTime").toDateTime();
	 }

	 return std::nullopt;
 }
 std::optional<float> ADMIDDao::queryDesignLoad(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("designLoad").toFloat();
	 }

	 return std::nullopt;
  }
 std::optional<float> ADMIDDao::queryGrade(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("grade").toFloat();
	 }

	 return std::nullopt;
  }
 std::optional<QString> ADMIDDao::queryDesignUnit(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("designUnit").toString();
	 }

	 return std::nullopt;
  }
 std::optional<QString> ADMIDDao::queryConstructorUnit(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("constructorUnit").toString();
	 }

	 return std::nullopt;
 }
 std::optional<QString> ADMIDDao::querySupervisoryUnit(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("supervisoryUnit").toString();
	 }

	 return std::nullopt;
 }
 std::optional<QString> ADMIDDao::queryOwnerUnit(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("ownerUnit").toString();
	 }

	 return std::nullopt;

 }
 std::optional<QString> ADMIDDao::queryManagementUnit(const QString& bridgeNumber) {
	 auto sql = QString("SELECT * FROM admid WHERE bridgeNumber = '%1'").arg(bridgeNumber.trimmed());
	 DEBUG(sql);

	 QSqlQuery query{ sql };
	 if (query.next()) {
		 return query.value("managementUnit").toString();
	 }

	 return std::nullopt;
 }