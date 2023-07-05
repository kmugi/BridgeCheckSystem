#include "BSInfoDao.h"


void BSInfoDao::insertBSInfo(const QString& bridgeNumber, const BSInfo& bsInfo) {
	auto sql = QString("INSERT INTO bsinfo (bridgeNumber, mainGirder, mainArchRib, \
bridgeTower, structureAboveArch, mainCable, bridgeSurfaceCoating, sidewalk, lighting, \
coneSlope, wingWall, foundation, bearing, crashBarrier, beacon) VALUES (?, ?, ?, ?, ?, \
?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);
	query.addBindValue(bsInfo.getMainGirder());
	query.addBindValue(bsInfo.getMainArchRib());
	query.addBindValue(bsInfo.getBridgeTower());
	query.addBindValue(bsInfo.getStructureAboveArch());
	query.addBindValue(bsInfo.getMainCable());
	query.addBindValue(bsInfo.getBridgeSurfaceCoating());
	query.addBindValue(bsInfo.getSidewalk());
	query.addBindValue(bsInfo.getLighting());
	query.addBindValue(bsInfo.getConeSlope());
	query.addBindValue(bsInfo.getWingWall());
	query.addBindValue(bsInfo.getFoundation());
	query.addBindValue(bsInfo.getBearing());
	query.addBindValue(bsInfo.getCrashBarrier());
	query.addBindValue(bsInfo.getBeacon());

	bool flag = query.exec();
	if (!flag) {
		CRITICAL("Failed to insert bsInfo");
	}
}

void BSInfoDao::deleteBSInfo(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM bsinfo WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	query.exec();
}

std::optional<QString> BSInfoDao::queryMainGirder(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bsinfo WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("mainGirder").toString();
	}

	return std::nullopt;
}

// TODO: 编写剩下的 query


void BSInfoDao::updateMainGirder(const QString& bridgeNumber, const QString& mainGirder) {
	auto sql = QString("UPDATE bsinfo SET mainGirder = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(mainGirder);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update '%1'").arg(mainGirder));
	}
}

// TODO: 编写剩下的 update