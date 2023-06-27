#include "Other.h"


Other::Other(
	const QString& bridgeEngineer,
	const QString& cardFiller,
	const QDateTime& cardTime
) noexcept :
	bridgeEngineer_(bridgeEngineer),
	cardFiller_(cardFiller),
	cardTime_(cardTime)
{}

Other::Other(
	QString&& bridgeEngineer,
	QString&& cardFiller,
	QDateTime&& cardTime
) noexcept :
	bridgeEngineer_(std::move(bridgeEngineer)),
	cardFiller_(std::move(cardFiller)),
	cardTime_(std::move(cardTime))
{}