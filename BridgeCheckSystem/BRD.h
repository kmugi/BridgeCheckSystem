#pragma once

#include <QString>
#include <QDateTime>

// 桥梁档案资料
// Bridge records and documentation
class BRD {
public:
	enum class BRDType {
		Complete = 1,
		None = 0,
		Incomplete = -1,
	};

	enum class ArchiveType {
		PaperBased = 0,
		Electronic,
	};

private:
	BRDType designDrawings_;	// 设计图纸
	BRDType designDoc_;			// 设计文件
	BRDType recordDrawings_;	// 竣工图纸
	BRDType acceptanceDoc_;		// 验收文件
	BRDType ADDoc_;				// 行政审批文件(Administrative Approval Document)
	BRDType PMS_;				// 定期检查资料(Preventive Maintenance Schedule)
	BRDType SIS_;				// 特殊检查资料(Special Inspection Schedule)
	BRDType RRR_;				// 历次维修，加固资料(Record of Repair and ReinforcementRecord of Repair and Reinforcement)
	QString otherArchive_;		// 其他档案
	ArchiveType archiveType_;	// 档案形式
	QDateTime filingDate;		// 建档时间
};

