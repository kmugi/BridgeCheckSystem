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