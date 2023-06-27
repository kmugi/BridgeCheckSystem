#include "BSInfo.h"


BSInfo::BSInfo(
	const QString& mainGirder,
	const QString& mainArchRib,
	const QString& bridgeTower,
	const QString& structureAboveArch,
	const QString& mainCable,
	const QString& bridgeSurfaceCoating,
	const QString& sidewalk,
	const QString& lighting,
	const QString& coneSlope,
	const QString& wingWall,
	const QString& foundation,
	const QString& bearing,
	const QString& crashBarrier,
	const QString& beacon
) noexcept :
	mainGirder_(mainGirder),
	mainArchRib_(mainArchRib),
	bridgeTower_(bridgeTower),
	structureAboveArch_(structureAboveArch),
	mainCable_(mainCable),
	bridgeSurfaceCoating_(bridgeSurfaceCoating),
	sidewalk_(sidewalk),
	lighting_(lighting),
	coneSlope_(coneSlope),
	wingWall_(wingWall),
	foundation_(foundation),
	bearing_(bearing),
	crashBarrier_(crashBarrier),
	beacon_(beacon)
{}

BSInfo::BSInfo(
	QString&& mainGirder,
	QString&& mainArchRib,
	QString&& bridgeTower,
	QString&& structureAboveArch,
	QString&& mainCable,
	QString&& bridgeSurfaceCoating,
	QString&& sidewalk,
	QString&& lighting,
	QString&& coneSlope,
	QString&& wingWall,
	QString&& foundation,
	QString&& bearing,
	QString&& crashBarrier,
	QString&& beacon
) noexcept :
	mainGirder_(std::move(mainGirder)),
	mainArchRib_(std::move(mainArchRib)),
	bridgeTower_(std::move(bridgeTower)),
	structureAboveArch_(std::move(structureAboveArch)),
	mainCable_(std::move(mainCable)),
	bridgeSurfaceCoating_(std::move(bridgeSurfaceCoating)),
	sidewalk_(std::move(sidewalk)),
	lighting_(std::move(lighting)),
	coneSlope_(std::move(coneSlope)),
	wingWall_(std::move(wingWall)),
	foundation_(std::move(foundation)),
	bearing_(std::move(bearing)),
	crashBarrier_(std::move(crashBarrier)),
	beacon_(std::move(beacon))
{}