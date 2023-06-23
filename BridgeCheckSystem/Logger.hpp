#pragma once

#include <QDebug>

class Logger {
private:
	Logger() {}

public:
	static Logger& instance() {
		static Logger m_instance;
		return m_instance;
	}

	void Debug(const char* funcname, int line, const QString& info) const {
		qDebug() << QString("funcname: %1; line: %2; info: %3")
			.arg(funcname)
			.arg(line)
			.arg(info);
	}
};

#ifndef DEBUG
#define DEBUG(info) \
Logger::instance().Debug(__FUNCTION__, __LINE__, info)
#endif

