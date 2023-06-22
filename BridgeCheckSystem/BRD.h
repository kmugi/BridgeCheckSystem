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
	//set函数
	void setDesignDrawings(BRDType designDrawings) { designDrawings_ = designDrawings; }
	void setDesignDoc(BRDType designDoc) { designDoc_ = designDoc; }
	void setRecordDrawings(BRDType recordDrawings) { recordDrawings_ = recordDrawings; }
	void setAcceptanceDoc(BRDType acceptanceDoc) { acceptanceDoc_ = acceptanceDoc; }
	void setADDoc(BRDType ADDoc) { ADDoc_ = ADDoc; }
	void setPMS(BRDType PMS) { PMS_ = PMS; }
	void setSIS(BRDType SIS) { SIS_ = SIS; }
	void setRRR(BRDType RRR) { RRR_ = RRR; }
	void setOtherArchive(QString otherArchive) { otherArchive_ = otherArchive; }
	void setArchiveType(ArchiveType archiveType) { archiveType_ = archiveType; }
	void setFilingDate(QDateTime filingDate) { filingDate_ = filingDate; }
	//get函数
	BRDType getDesignDrawings() const { return designDrawings_; }
	BRDType getDesignDoc() const { return designDoc_; }
	BRDType getRecordDrawings() const { return recordDrawings_; }
	BRDType getAcceptanceDoc() const { return acceptanceDoc_; }
	BRDType getADDoc() const { return ADDoc_; }
	BRDType getPMS() const { return PMS_; }
	BRDType getSIS() const { return SIS_; }
	BRDType getRRR() const { return RRR_; }
	QString getOtherArchive() const { return otherArchive_; }
	ArchiveType getArchiveType() const { return archiveType_; }
	QDateTime getFilingDate() const { return filingDate_; }

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

