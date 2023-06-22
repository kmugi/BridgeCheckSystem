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

	// TODO: add constructor

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

private:
	QDateTime assessmentTime_;		// 评定时间
	InspectionType type_;			// 检测类型
	QString result_;				// 结果
	QString remedialMeasures_;		// 处治对策
	QDateTime nextInspectionTime_;	// 下次检测时间
};


