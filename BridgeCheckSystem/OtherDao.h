#pragma once

#include <QString>
#include <QDateTime>
#include <optional>

#include "Other.h"

class OtherDao {
	// insert
	static void insertOther(const QString& bridgeNumber, const Other& other);

	// delete
	static void deleteOther(const QString& bridgeNumber);

	// query
	static std::optional<QString> queryBridgeEngineer(const QString& bridgeNumber);
	static std::optional<QString> queryCardFiller(const QString& bridgeNumber);
	static std::optional<QDateTime> queryCardTime(const QString& bridgeNumber);

	// update
	static void updateBridgeEngineer(const QString& bridgeNumber, const QString& bridgeEngineer);
	static void updateCardFiller(const QString& bridgeNumber, const QString& cardFiller);
	static void updateCardTime(const QString& bridgeNumber, const QDateTime& cardTime);
};

