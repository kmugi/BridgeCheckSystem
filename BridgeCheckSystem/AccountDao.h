#pragma once

#include <QString>
#include <QSqlQuery>

#include "Logger.hpp"

class AccountDao {
public:
	static bool	isAccountExist(const QString& username, const QString& password);
};

