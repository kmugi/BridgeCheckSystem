#pragma once

#include <QString>
#include <QDateTime>

// 桥梁档案资料
// Bridge records and documentation
class BRD {
public:
	enum class BRDType {
		Complete = 1,
		None = 0,
		Incomplete = -1,
	};

	enum class ArchiveType {
		PaperBased = 0,
		Electronic,
	};

	// TODO: add constructor

	void setDesignDrawings(BRDType designDrawings) noexcept { designDrawings_ = designDrawings; }
	BRDType getDesignDrawings() const noexcept { return designDrawings_; }

	void setDesignDoc(BRDType designDoc) noexcept { designDoc_ = designDoc; }
	BRDType getDesignDoc() const noexcept { return designDoc_; }

	void setRecordDrawings(BRDType recordDrawings) noexcept { recordDrawings_ = recordDrawings; }
	BRDType getRecordDrawings() const noexcept { return recordDrawings_; }

	void setAcceptanceDoc(BRDType acceptanceDoc) noexcept { acceptanceDoc_ = acceptanceDoc; }
	BRDType getAcceptanceDoc() const noexcept { return acceptanceDoc_; }

	void setADDoc(BRDType ADDoc) noexcept { ADDoc_ = ADDoc; }
	BRDType getADDoc() const noexcept { return ADDoc_; }

	void setPMS(BRDType PMS) noexcept { PMS_ = PMS; }
	BRDType getPMS() const noexcept { return PMS_; }

	void setSIS(BRDType SIS) noexcept { SIS_ = SIS; }
	BRDType getSIS() const noexcept { return SIS_; }

	void setRRR(BRDType RRR) noexcept { RRR_ = RRR; }
	BRDType getRRR() const noexcept { return RRR_; }

	void setOtherArchive(const QString& otherArchive) noexcept { otherArchive_ = otherArchive; }
	void setOtherArchive(QString&& otherArchive) noexcept { otherArchive_ = std::move(otherArchive); }
	QString getOtherArchive() const noexcept { return otherArchive_; }

	void setArchiveType(ArchiveType archiveType) noexcept { archiveType_ = archiveType; }
	ArchiveType getArchiveType() const noexcept { return archiveType_; }

	void setFilingDate(const QDateTime& filingDate) noexcept { filingDate_ = filingDate; }
	void setFilingDate(QDateTime&& filingDate) noexcept { filingDate_ = std::move(filingDate); }
	QDateTime getFilingDate() const noexcept { return filingDate_; }


private:
	BRDType designDrawings_;	// 设计图纸
	BRDType designDoc_;			// 设计文件
	BRDType recordDrawings_;	// 竣工图纸
	BRDType acceptanceDoc_;		// 验收文件
	BRDType ADDoc_;				// 行政审批文件(Administrative Approval Document)
	BRDType PMS_;				// 定期检查资料(Preventive Maintenance Schedule)
	BRDType SIS_;				// 特殊检查资料(Special Inspection Schedule)
	BRDType RRR_;				// 历次维修，加固资料(Record of Repair and ReinforcementRecord of Repair and Reinforcement)
	QString otherArchive_;		// 其他档案
	ArchiveType archiveType_;	// 档案形式
	QDateTime filingDate_;		// 建档时间
};

