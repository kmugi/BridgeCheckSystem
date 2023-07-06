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

 std::optional<BRD::BRDType> BRDDao::queryDesignDoc(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::BRDType>(query.value("designDoc").toInt());
    }

    return std::nullopt;
}

 std::optional<BRD::BRDType> BRDDao::queryRecordDrawings(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::BRDType>(query.value("recordDrawings").toInt());
    }

    return std::nullopt;
}

 std::optional<BRD::BRDType> BRDDao::queryAcceptanceDoc(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::BRDType>(query.value("acceptanceDoc").toInt());
    }

    return std::nullopt;
}

 std::optional<BRD::BRDType> BRDDao::queryADDoc(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::BRDType>(query.value("adDoc").toInt());
    }

    return std::nullopt;
}

 std::optional<BRD::BRDType> BRDDao::queryPMS(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::BRDType>(query.value("pms").toInt());
    }

    return std::nullopt;
}

std::optional<BRD::BRDType> BRDDao::querySIS(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::BRDType>(query.value("sis").toInt());
    }

    return std::nullopt;
}

 std::optional<BRD::BRDType> BRDDao::queryRRR(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::BRDType>(query.value("rrr").toInt());
    }

    return std::nullopt;
}

 std::optional<QString> BRDDao::queryOtherArchive(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return query.value("otherArchive").toString();
    }

    return std::nullopt;
}

 std::optional<BRD::ArchiveType> BRDDao::queryArchiveType(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return static_cast<BRD::ArchiveType>(query.value("archiveType").toInt());
    }

    return std::nullopt;
}

 std::optional<QDateTime> BRDDao::queryFilingDate(const QString& bridgeNumber) {
    auto sql = QString("SELECT * FROM brd WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(bridgeNumber);

    if (query.exec() && query.next()) {
        return query.value("filingDate").toDateTime();
    }

    return std::nullopt;
}




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


void BRDDao::updateDesignDoc(const QString& bridgeNumber, BRD::BRDType designDoc) {
    auto sql = QString("UPDATE brd SET designDoc = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(designDoc));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update design doc '%1'").arg(static_cast<int>(designDoc)));
    }
}

void BRDDao::updateRecordDrawings(const QString& bridgeNumber, BRD::BRDType recordDrawings) {
    auto sql = QString("UPDATE brd SET recordDrawings = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(recordDrawings));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update record drawings '%1'").arg(static_cast<int>(recordDrawings)));
    }
}

void BRDDao::updateAcceptanceDoc(const QString& bridgeNumber, BRD::BRDType acceptanceDoc) {
    auto sql = QString("UPDATE brd SET acceptanceDoc = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(acceptanceDoc));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update acceptance doc '%1'").arg(static_cast<int>(acceptanceDoc)));
    }
}

void BRDDao::updateADDoc(const QString& bridgeNumber, BRD::BRDType ADDoc) {
    auto sql = QString("UPDATE brd SET adDoc = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(ADDoc));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update AD doc '%1'").arg(static_cast<int>(ADDoc)));
    }
}

void BRDDao::updatePMS(const QString& bridgeNumber, BRD::BRDType PMS) {
    auto sql = QString("UPDATE brd SET PMS = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(PMS));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update PMS '%1'").arg(static_cast<int>(PMS)));
    }
}
void BRDDao::updateSIS(const QString& bridgeNumber, BRD::BRDType SIS) {
    auto sql = QString("UPDATE brd SET SIS = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(SIS));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update SIS '%1'").arg(static_cast<int>(SIS)));
    }
}

void BRDDao::updateRRR(const QString& bridgeNumber, BRD::BRDType RRR) {
    auto sql = QString("UPDATE brd SET RRR = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(RRR));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update RRR '%1'").arg(static_cast<int>(RRR)));
    }
}

void BRDDao::updateOtherArchive(const QString& bridgeNumber, const QString& otherArchive) {
    auto sql = QString("UPDATE brd SET otherArchive = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(otherArchive);
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update other archive '%1'").arg(otherArchive));
    }
}

void BRDDao::updateArchiveType(const QString& bridgeNumber, BRD::ArchiveType archiveType) {
    auto sql = QString("UPDATE brd SET archiveType = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(static_cast<int>(archiveType));
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update archive type '%1'").arg(static_cast<int>(archiveType)));
    }
}

void BRDDao::updateFilingDate(const QString& bridgeNumber, const QDateTime& filingDate) {
    auto sql = QString("UPDATE brd SET filingDate = ? WHERE bridgeNumber = ?;");
    DEBUG(sql);

    QSqlQuery query{};
    query.prepare(sql);
    query.addBindValue(filingDate);
    query.addBindValue(bridgeNumber);

    bool flag = query.exec();
    if (!flag) {
        CRITICAL(QString("Failed to update filing date '%1'").arg(filingDate.toString()));
    }
}