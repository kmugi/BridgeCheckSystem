#include "BRD.h"

BRD::BRD(
	BRDType designDrawings,
	BRDType designDoc,
	BRDType recordDrawings,
	BRDType acceptanceDoc,
	BRDType ADDoc,
	BRDType PMS,
	BRDType SIS,
	BRDType RRR,
	const QString& otherArchive,
	ArchiveType archiveType,
	const QDateTime& filingDate
) noexcept :
	designDrawings_(designDrawings),
	designDoc_(designDoc),
	recordDrawings_(recordDrawings),
	acceptanceDoc_(acceptanceDoc),
	ADDoc_(ADDoc),
	PMS_(PMS),
	SIS_(SIS),
	RRR_(RRR),
	otherArchive_(otherArchive),
	archiveType_(archiveType),
	filingDate_(filingDate)
{}

BRD::BRD(
	BRDType designDrawings,
	BRDType designDoc,
	BRDType recordDrawings,
	BRDType acceptanceDoc,
	BRDType ADDoc,
	BRDType PMS,
	BRDType SIS,
	BRDType RRR,
	QString&& otherArchive,
	ArchiveType archiveType,
	QDateTime&& filingDate
) noexcept :
	designDrawings_(designDrawings),
	designDoc_(designDoc),
	recordDrawings_(recordDrawings),
	acceptanceDoc_(acceptanceDoc),
	ADDoc_(ADDoc),
	PMS_(PMS),
	SIS_(SIS),
	RRR_(RRR),
	otherArchive_(std::move(otherArchive)),
	archiveType_(archiveType),
	filingDate_(std::move(filingDate))
{}