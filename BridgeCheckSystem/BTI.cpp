#include "BTI.h"

BTI::BTI(
	float length,
	float width,
	float laneWidth,
	float sidewalkWidth,
	float guardrailHeight,
	float medianWidth,
	float BVC,
	float ABC,
	float AUC,
	float ARW
) noexcept :
	length_(length),
	width_(width),
	laneWidth_(laneWidth),
	sidewalkWidth_(sidewalkWidth),
	guardrailHeight_(guardrailHeight),
	medianWidth_(medianWidth),
	BVC_(BVC),
	ABC_(ABC),
	AUC_(AUC),
	ARW_(ARW)
{}