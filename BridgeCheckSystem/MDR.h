#pragma once

#include <QDateTime>
#include <QString>

// 养护处治记录
// Maintenance and Disposal Records
class MDR {
public:
	// 处治类别
	enum class RemedialActionType {
		Repair = 0,		// 修理
		Strengthen,		// 加固
		Renovation,		// 改造
	};

private:
	QDateTime time_;
	RemedialActionType type_;
	QString remedialActionReason_;		// 处治原因
	QString remedialActionScope_;		// 处治范围
	uint32_t projectCost_;				// 工程费用(w)
	QString fundingSource_;				// 经费来源
	QString RAQA_;						// 处治质量评定(Remedial Action Quality Assessment)
};

