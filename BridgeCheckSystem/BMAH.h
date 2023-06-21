#pragma once

#include <QString>
#include <QDateTime>

// 桥梁检测评定历史
// Bridge Monitoring and Assessment History
class BMAH {
public:
	// 检测类型
	enum class InspectionType {
		Initial = 0,
		Regular,
		Special,
	};

private:
	QDateTime assessmentTime_;		// 评定时间
	InspectionType type;			// 检测类型
	QString result;					// 结果
	QString remedialMeasures;		// 处治对策
	QDateTime nextInspectionTime;	// 下次检测时间
};

