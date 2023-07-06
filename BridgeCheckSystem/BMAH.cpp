#include "BMAH.h"


BMAH::BMAH(
	const QDateTime& assessmentTime,
	InspectionType type,
	const QString& result,
	const QString& remedialMeasures,
	const QDateTime& nextInspectionTime
) noexcept :
	assessmentTime_(assessmentTime),
	type_(type),
	result_(result),
	remedialMeasures_(remedialMeasures),
	nextInspectionTime_(nextInspectionTime)
{}

BMAH::BMAH(
	QDateTime&& assessmentTime,
	InspectionType type,
	QString&& result,
	QString&& remedialMeasures,
	QDateTime&& nextInspectionTime
) noexcept :
	assessmentTime_(std::move(assessmentTime)),
	type_(type),
	result_(std::move(result)),
	remedialMeasures_(std::move(remedialMeasures)),
	nextInspectionTime_(std::move(nextInspectionTime))
{}