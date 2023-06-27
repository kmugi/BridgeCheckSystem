#pragma once

#define GAS(type, funcname, valname) \
void set##funcname(type valname) noexcept { valname##_ = valname; } \
type get##funcname() const noexcept { return valname##_; }

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
	void setLength(float length) noexcept { length_ = length; }
	float getLength() const noexcept { return length_; }

	void setWidth(float width) noexcept { width_ = width; }
	float getWidth() const noexcept { return width_; }

	void setLaneWidth(float laneWidth) noexcept { laneWidth_ = laneWidth; }
	float getLaneWidth() const noexcept { return laneWidth_; }

	void setSidewalkWidth(float sidewalkWidth) noexcept { sidewalkWidth_ = sidewalkWidth; }
	float getSidewalkWidth() const noexcept { return sidewalkWidth_; }

	void setGuardrailHeight(float guardrailHeight) noexcept { guardrailHeight_ = guardrailHeight; }
	float getGuardrailHeight() const noexcept { return guardrailHeight_; }

	void setMedianWidth(float medianWidth) noexcept { medianWidth_ = medianWidth; }
	float getMedianWidth() const noexcept { return medianWidth_; }

	void setBVC(float BVC) noexcept { BVC_ = BVC; }
	float getBVC() const noexcept { return BVC_; }

	void setABC(float ABC) noexcept { ABC_ = ABC; }
	float getABC() const noexcept { return ABC_; }

	void setAUC(float AUC) noexcept { AUC_ = AUC; }
	float getAUC() const noexcept { return AUC_; }

	void setARW(float ARW) noexcept { ARW_ = ARW; }
	float getARW() const noexcept { return ARW_; }


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

