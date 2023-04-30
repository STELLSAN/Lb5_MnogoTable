#pragma once
#include "TDataCom.h";
#include "Marks.h";
#include "TDataValue.h";
#include "TTable.h";
#include "TTabRecord.h"


#define TabOkey 0
#define TabEmpty -101
#define TabFull -102
#define TabNoRecord -103
#define TabRecordDouble -104
#define TabNoMem -105

class TTable : public TDataCom
{
protected:
	int dataCount;
	int efficiency;

public:
	TTable() : dataCount(0), efficiency(0)
	{}
	virtual ~TTable() {}

	int GetDataCount() const { return dataCount; }
	int GetEfficiency() const { return efficiency; }

	bool IsEmpty() const
	{
		return dataCount == 0;
	}

	virtual bool IsFull() const = 0;


	virtual PTDataValue FindRecord(Tkey key_) = 0;
	virtual void InsertRecord(Tkey key_, PTDataValue pValue_) = 0;
	virtual void DeleteRecord(Tkey key_) = 0;

	virtual int Reset() = 0;
	virtual bool IsTabEnded()const = 0;
	virtual int GoNext() = 0;

	virtual Tkey GeyKey()const = 0;
	virtual PTDataValue GetValuePtr()const = 0;

	friend std::ostream& operator<<(std::ostream& os, TTable& tab_)
	{
		for (tab_.Reset(); !tab_.IsTabEnded(); tab_.GoNext())
		{
			os << "Key: " << tab_.GeyKey() << " Value: " << *tab_.GetValuePtr() << std::endl;
		}
		return os;
	}
	friend class TScanTable;


};