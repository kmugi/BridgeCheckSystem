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
	//set函数
	void setTime(QDateTime time) { time_ = time; }
	void setType(RemedialActionType type) { type_ = type; }
	void setRemedialActionReason(QString remedialActionReason) { remedialActionReason_ = remedialActionReason; }
	void setRemedialActionScope(QString remedialActionScope) { remedialActionScope_ = remedialActionScope; }
	void setProjectCost(uint32_t projectCost) { projectCost_ = projectCost; }
	void setFundingSource(QString fundingSource) { fundingSource_ = fundingSource; }
	void setRAQA(QString RAQA) { RAQA_ = RAQA; }
	//get函数
	QDateTime getTime() const { return time_; }
	RemedialActionType getType() const { return type_; }
	QString getRemedialActionReason() const { return remedialActionReason_; }
	QString getRemedialActionScope() const { return remedialActionScope_; }
	uint32_t getProjectCost() const { return projectCost_; }
	QString getFundingSource() const { return fundingSource_; }
	QString getRAQA() const { return RAQA_; }


private:
	QDateTime time_;
	RemedialActionType type_;
	QString remedialActionReason_;		// 处治原因
	QString remedialActionScope_;		// 处治范围
	uint32_t projectCost_;				// 工程费用(w)
	QString fundingSource_;				// 经费来源
	QString RAQA_;						// 处治质量评定(Remedial Action Quality Assessment)
};

