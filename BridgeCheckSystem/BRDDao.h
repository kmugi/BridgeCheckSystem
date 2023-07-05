#pragma once

#include <QString>
#include <QDateTime>
#include <optional>
#include <QSqlQuery>

#include "BRD.h"
#include "Logger.hpp"

class BRDDao {
public:
	// insert
	static void insertBRD(const QString& bridgeNumber, const BRD& brd);

	// delete
	static void deleteBRD(const QString& bridgeNumber);

	// query
	static std::optional<BRD::BRDType> queryDesignDrawings(const QString& bridgeNumber);
	static std::optional<BRD::BRDType> queryDesignDoc(const QString& bridgeNumber);
	static std::optional<BRD::BRDType> queryRecordDrawings(const QString& bridgeNumber);
	static std::optional<BRD::BRDType> queryAcceptanceDoc(const QString& bridgeNumber);
	static std::optional<BRD::BRDType> queryADDoc(const QString& bridgeNumber);
	static std::optional<BRD::BRDType> queryPMS(const QString& bridgeNumber);
	static std::optional<BRD::BRDType> querySIS(const QString& bridgeNumber);
	static std::optional<BRD::BRDType> queryRRR(const QString& bridgeNumber);
	static std::optional<QString> queryOtherArchive(const QString& bridgeNumber);
	static std::optional<BRD::ArchiveType> queryArchiveType(const QString& bridgeNumber);
	static std::optional<QDateTime> queryFilingDate(const QString& bridgeNumber);

	// update
	static void updateDesignDrawings(const QString& bridgeNumber, BRD::BRDType designDrawings);
	static void updateDesignDoc(const QString& bridgeNumber, BRD::BRDType designDoc);
	static void updateRecordDrawings(const QString& bridgeNumber, BRD::BRDType recordDrawings);
	static void updateAcceptanceDoc(const QString& bridgeNumber, BRD::BRDType acceptanceDoc);
	static void updateADDoc(const QString& bridgeNumber, BRD::BRDType ADDoc);
	static void updatePMS(const QString& bridgeNumber, BRD::BRDType PMS);
	static void updateSIS(const QString& bridgeNumber, BRD::BRDType SIS);
	static void updateRRR(const QString& bridgeNumber, BRD::BRDType RRR);
	static void updateOtherArchive(const QString& bridgeNumber, const QString& otherArchive);
	static void updateArchiveType(const QString& bridgeNumber, BRD::ArchiveType archiveType);
	static void updateFilingDate(const QString& bridgeNumber, const QDateTime& filingDate);
};

