#pragma once

#include <QString>
#include <QDateTime>
#include <QMap>

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

	BMAH() = delete;
	BMAH(
		const QDateTime assessmentTime,
		InspectionType type,
		const QString result,
		const QString remedialMeasures,
		const QDateTime nextInspectionTime
	) noexcept;

	BMAH(
		QDateTime&& assessmentTime,
		InspectionType type,
		QString&& result,
		QString&& remedialMeasures,
		QDateTime&& nextInspectionTime
	) noexcept;

	void setAssessmentTime(const QDateTime& assessmentTime) noexcept { assessmentTime_ = assessmentTime; };
	void setAssessmentTime(QDateTime&& assessmentTime) noexcept { assessmentTime_ = std::move(assessmentTime); };
	QDateTime getAssessmentTime() const noexcept { return assessmentTime_; }

	void setType(InspectionType type) noexcept { type_ = type; }
	InspectionType getType() const noexcept { return type_; }

	void setResult(const QString& result) noexcept { result_ = result; }
	void setResult(QString&& result) noexcept { result_ = std::move(result); }
	QString getResult() const noexcept { return result_; }

	void setRemedialMeasures(const QString& remedialMeasures) noexcept { remedialMeasures_ = remedialMeasures; }
	void setRemedialMeasures(QString&& remedialMeasures) noexcept { remedialMeasures_ = std::move(remedialMeasures); }
	QString getRemedialMeasures() const noexcept { return remedialMeasures_; }

	void setNextlnspectionTime(const QDateTime& nextinspectionTime) noexcept { nextInspectionTime_ = nextinspectionTime; }
	void setNextlnspectionTime(QDateTime&& nextinspectionTime) noexcept { nextInspectionTime_ = std::move(nextinspectionTime); }
	QDateTime getInspectionTime() const noexcept { return nextInspectionTime_; }

public:
	inline const static QMap<BMAH::InspectionType, QString> inspectionTypeToStr{
		{BMAH::InspectionType::Initial, "初始"},
		{BMAH::InspectionType::Regular, "定期"},
		{BMAH::InspectionType::Special, "特殊"}
	};

	inline const static QMap<QString, BMAH::InspectionType> strToInspectionType{
		{"初始", BMAH::InspectionType::Initial},
		{"定期", BMAH::InspectionType::Regular},
		{"特殊", BMAH::InspectionType::Special}
	};

private:
	QDateTime assessmentTime_;		// 评定时间
	InspectionType type_;			// 检测类型
	QString result_;				// 结果
	QString remedialMeasures_;		// 处治对策
	QDateTime nextInspectionTime_;	// 下次检测时间
};


