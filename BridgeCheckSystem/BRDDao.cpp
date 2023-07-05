#include "BRDDao.h"


void BRDDao::insertBRD(const QString& bridgeNumber, const BRD& brd) {
	auto sql = QString("INSERT INTO brd (bridgeNumber, designDrawings, designDoc, \
recordDrawings, acceptanceDoc, ADDoc, PMS, SIS, RRR, otherArchive, archiveType, \
FilingDate) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);
	query.addBindValue(static_cast<int>(brd.getDesignDrawings()));
	query.addBindValue(static_cast<int>(brd.getDesignDoc()));
	query.addBindValue(static_cast<int>(brd.getRecordDrawings()));
	query.addBindValue(static_cast<int>(brd.getAcceptanceDoc()));
	query.addBindValue(static_cast<int>(brd.getADDoc()));
	query.addBindValue(static_cast<int>(brd.getPMS()));
	query.addBindValue(static_cast<int>(brd.getSIS()));
	query.addBindValue(static_cast<int>(brd.getRRR()));
	query.addBindValue(brd.getOtherArchive());
	query.addBindValue(static_cast<int>(brd.getArchiveType()));
	query.addBindValue(brd.getFilingDate());

	bool flag = query.exec();
	if (!flag) {
		CRITICAL("Failed to insert brd");
	}
}

void BRDDao::deleteBRD(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM brd WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	query.exec();
}

std::optional<BRD::BRDType> BRDDao::queryDesignDrawings(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return static_cast<BRD::BRDType>(query.value("designDrawings").toInt());
	}

	return std::nullopt;
}

//TODO: 编写剩下的 query


void BRDDao::updateDesignDrawings(const QString& bridgeNumber, BRD::BRDType designDrawings) {
	auto sql = QString("UPDATE brd SET designDrawings = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(static_cast<int>(designDrawings));

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update '%1'").arg(static_cast<int>(designDrawings)));
	}
}

//TODO: 编写剩下的 update