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

public:
	MDR() = delete;
	MDR(
		const QDateTime& time,
		RemedialActionType type,
		const QString& remedialActionReason,
		const QString& remedialActionScope,
		uint32_t projectCost,
		const QString& fundingSource,
		const QString& RAQA
	) noexcept;

	MDR(
		QDateTime&& time,
		RemedialActionType type,
		QString&& remedialActionReason,
		QString&& remedialActionScope,
		uint32_t projectCost,
		QString&& fundingSource,
		QString&& RAQA
	) noexcept;

	void setTime(const QDateTime& time) noexcept { time_ = time; }
	void setTime(QDateTime&& time) noexcept { time_ = std::move(time); }
	QDateTime getTime() const noexcept { return time_; }

	void setType(RemedialActionType type) noexcept { type_ = type; }
	RemedialActionType getType() const noexcept { return type_; }

	void setRemedialActionReason(const QString& remedialActionReason) noexcept { remedialActionReason_ = remedialActionReason; }
	void setRemedialActionReason(QString&& remedialActionReason) noexcept { remedialActionReason_ = std::move(remedialActionReason); }
	QString getRemedialActionReason() const noexcept { return remedialActionReason_; }

	void setRemedialActionScope(const QString& remedialActionScope) noexcept { remedialActionScope_ = remedialActionScope; }
	void setRemedialActionScope(QString&& remedialActionScope) noexcept { remedialActionScope_ = std::move(remedialActionScope); }
	QString getRemedialActionScope() const noexcept { return remedialActionScope_; }

	void setProjectCost(uint32_t projectCost) noexcept { projectCost_ = projectCost; }
	uint32_t getProjectCost() const noexcept { return projectCost_; }

	void setFundingSource(const QString& fundingSource) noexcept { fundingSource_ = fundingSource; }
	void setFundingSource(QString&& fundingSource) noexcept { fundingSource_ = std::move(fundingSource); }
	QString getFundingSource() const noexcept { return fundingSource_; }

	void setRAQA(const QString& RAQA) noexcept { RAQA_ = RAQA; }
	void setRAQA(QString&& RAQA) noexcept { RAQA_ = std::move(RAQA); }
	QString getRAQA() const noexcept { return RAQA_; }

public:
	inline const static QMap<MDR::RemedialActionType, QString> remedialActionTypeToStr{
		{MDR::RemedialActionType::Repair, "修理"},
		{MDR::RemedialActionType::Strengthen, "加固"},
		{MDR::RemedialActionType::Renovation, "改造"}
	};

	inline const static QMap<QString, MDR::RemedialActionType> strToRemedialActionType{
		{"修理", MDR::RemedialActionType::Repair},
		{"加固", MDR::RemedialActionType::Strengthen},
		{"改造", MDR::RemedialActionType::Renovation}
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

