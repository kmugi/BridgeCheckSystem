#pragma once

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

class DatabaseManager {
private:
	DatabaseManager() {}

public:
	static DatabaseManager& instance() {
		static DatabaseManager m_instance;
		return m_instance;
	}

	void init(QSqlDatabase& db) {
		db = QSqlDatabase::addDatabase("QODBC");
		db.setHostName("127.0.0.1");
		db.setDatabaseName("mysql");
		db.setUserName("root");
		db.setPassword("c2002108");
		if (db.open()) {
			qDebug() << "Connected to MySQL successfully.";
		} else {
			qDebug() << "Failed to connect to MySQL. Reason: " << db.lastError().text();
		}
	}
};

