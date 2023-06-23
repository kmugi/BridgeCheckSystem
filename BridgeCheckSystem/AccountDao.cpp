#include "AccountDao.h"

bool AccountDao::isAccountExist(const QString& username, const QString& password) {
	auto sql = QString("SELECT * FROM account WHERE username = '%1' && password = '%2'")
		.arg(username.trimmed())
		.arg(password.trimmed());

	DEBUG(sql);

	return QSqlQuery(sql).next();
}