#include "BTIDao.h"

void BTIDao::insertBTI(const QString& bridgeNumber, const BTI& bti) {
	auto sql = QString("INSERT INTO bti (bridgeNumber, length, width, laneWidth, sidewalkWidth, \
guardrailHeight, medianWidth, BVC, ABC, AUC, ARW) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?);");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);
	query.addBindValue(bti.getLength());
	query.addBindValue(bti.getWidth());
	query.addBindValue(bti.getLaneWidth());
	query.addBindValue(bti.getSidewalkWidth());
	query.addBindValue(bti.getGuardrailHeight());
	query.addBindValue(bti.getMedianWidth());
	query.addBindValue(bti.getBVC());
	query.addBindValue(bti.getABC());
	query.addBindValue(bti.getAUC());
	query.addBindValue(bti.getARW());

	bool flag = query.exec();
	if (!flag) {
		CRITICAL("Failed to insert bti");
	}
}

void BTIDao::deleteBTI(const QString& bridgeNumber) {
	auto sql = QString("DELETE FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	query.exec();
}

std::optional<BTI> BTIDao::queryBTI(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return BTI(
			query.value("length").toFloat(),
			query.value("width").toFloat(),
			query.value("laneWidth").toFloat(),
			query.value("sidewalkWidth").toFloat(),
			query.value("guardrailHeight").toFloat(),
			query.value("medianWidth").toFloat(),
			query.value("BVC").toFloat(),
			query.value("ABC").toFloat(),
			query.value("AUC").toFloat(),
			query.value("ARW").toFloat()
		);
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryLength(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("length").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryWidth(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("width").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryLaneWidth(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("laneWidth").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::querySidewalkWidth(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("sidewalkWidth").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryGuardrailHeight(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("guardrailHeight").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryMedianWidth(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("medianWidth").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryBVC(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("bvc").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryABC(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("abc").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryAUC(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("auc").toFloat();
	}

	return std::nullopt;
}

std::optional<float> BTIDao::queryARW(const QString& bridgeNumber) {
	auto sql = QString("SELECT * FROM bti WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(bridgeNumber);

	if (query.exec() && query.next()) {
		return query.value("arw").toFloat();
	}

	return std::nullopt;
}

void BTIDao::updateBTI(const QString& bridgeNumber, const BTI& info) {
	auto sql = QString("UPDATE bti SET length = ?, width = ?, laneWidth = ?, sidewalkWidth = ?, \
guardrailHeight = ?, medianWidth = ?, BVC = ?, ABC = ?, AUC = ?, ARW = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(info.getLength());
	query.addBindValue(info.getWidth());
	query.addBindValue(info.getLaneWidth());
	query.addBindValue(info.getSidewalkWidth());
	query.addBindValue(info.getGuardrailHeight());
	query.addBindValue(info.getMedianWidth());
	query.addBindValue(info.getBVC());
	query.addBindValue(info.getABC());
	query.addBindValue(info.getAUC());
	query.addBindValue(info.getARW());
	query.addBindValue(bridgeNumber);

	bool isSuccess = query.exec();
	if (!isSuccess) {
		CRITICAL(QString("Failed to update data for bridge '%1'").arg(bridgeNumber));
	}
}


void BTIDao::updateLength(const QString& bridgeNumber, float length) {
	auto sql = QString("UPDATE bti SET length = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(length);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update '%1'").arg(length));
	}
}


void BTIDao::updateWidth(const QString& bridgeNumber, float width) {
	auto sql = QString("UPDATE bti SET width = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(width);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update width '%1'").arg(width));
	}
}

void BTIDao::updateLaneWidth(const QString& bridgeNumber, float laneWidth) {
	auto sql = QString("UPDATE bti SET laneWidth = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(laneWidth);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update laneWidth '%1'").arg(laneWidth));
	}
}

void BTIDao::updateSidewalkWidth(const QString& bridgeNumber, float sidewalkWidth) {
	auto sql = QString("UPDATE bti SET sidewalkWidth = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(sidewalkWidth);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update sidewalkWidth '%1'").arg(sidewalkWidth));
	}
}

void BTIDao::updateGuardrailHeight(const QString& bridgeNumber, float guardrailHeight) {
	auto sql = QString("UPDATE bti SET guardrailHeight = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(guardrailHeight);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update guardrailHeight '%1'").arg(guardrailHeight));
	}
}

void BTIDao::updateMedianWidth(const QString& bridgeNumber, float medianWidth) {
	auto sql = QString("UPDATE bti SET medianWidth = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(medianWidth);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update medianWidth '%1'").arg(medianWidth));
	}
}

void BTIDao::updateBVC(const QString& bridgeNumber, float BVC) {
	auto sql = QString("UPDATE bti SET BVC = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(BVC);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update BVC '%1'").arg(BVC));
	}
}

void BTIDao::updateABC(const QString& bridgeNumber, float ABC) {
	auto sql = QString("UPDATE bti SET ABC = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(ABC);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update ABC '%1'").arg(ABC));
	}
}

void BTIDao::updateAUC(const QString& bridgeNumber, float AUC) {
	auto sql = QString("UPDATE bti SET AUS = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(AUC);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update AUC '%1'").arg(AUC));
	}
}

void BTIDao::updateARW(const QString& bridgeNumber, float ARW) {
	auto sql = QString("UPDATE bti SET ARW = ? WHERE bridgeNumber = ?;");
	DEBUG(sql);

	QSqlQuery query{};
	query.prepare(sql);
	query.addBindValue(ARW);
	query.addBindValue(bridgeNumber);

	bool flag = query.exec();
	if (!flag) {
		CRITICAL(QString("Failed to update ARW '%1'").arg(ARW));
	}
}