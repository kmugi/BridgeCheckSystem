#include "MDR.h"

MDR::MDR(
	const QDateTime& time,
	RemedialActionType type,
	const QString& remedialActionReason,
	const QString& remedialActionScope,
	uint32_t projectCost,
	const QString& fundingSource,
	const QString& RAQA
) noexcept :
	time_(time),
	type_(type),
	remedialActionReason_(remedialActionReason),
	remedialActionScope_(remedialActionScope),
	projectCost_(projectCost),
	fundingSource_(fundingSource),
	RAQA_(RAQA)
{}

MDR::MDR(
	QDateTime&& time,
	RemedialActionType type,
	QString&& remedialActionReason,
	QString&& remedialActionScope,
	uint32_t projectCost,
	QString&& fundingSource,
	QString&& RAQA
) noexcept :
	time_(std::move(time)),
	type_(type),
	remedialActionReason_(std::move(remedialActionReason)),
	remedialActionScope_(std::move(remedialActionScope)),
	projectCost_(projectCost),
	fundingSource_(std::move(fundingSource)),
	RAQA_(std::move(RAQA))
{}