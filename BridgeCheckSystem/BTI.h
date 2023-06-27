#pragma once


// 桥梁技术指标
// Bridge Technical Indicators
class BTI {
public:
	BTI() = delete;
	BTI(
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
	) noexcept;

	// TODO: getter and setter



private:
	float length_;				// 全长
	float width_;				// 桥面总宽
	float laneWidth_;			// 车道宽度
	float sidewalkWidth_;		// 人行道宽度
	float guardrailHeight_;		// 护栏高度
	float medianWidth_;			// 中央分隔带高度
	float BVC_;					// 桥面标准净空 Bridge Vertical Clearance
	float ABC_;					// 桥面实际净空 Actual Bridge Clearance
	float AUC_;					// 桥下实际净空 Actual Underpass Clearance
	float ARW_;					// 引道总宽	  Approach Roadway Width
};

