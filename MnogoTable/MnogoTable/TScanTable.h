#pragma once
#include "TArrayTable.h"

class TScanTable : public TArrayTable
{
public:
	TScanTable(int size = TabMaxSize):TArrayTable(size) {}

	virtual PTDataValue FindRecord(Tkey key) override{
		int i;
		SetRetCode(TabOkey);
		for (i = 0; i < dataCount; i++) {
			if (pRecs[i]->GetKey() == key) {
				break;
			}
		}
		if (i < dataCount) {
			curPos = i;
			return pRecs[i]->GetpValue();
		}else{
			SetRetCode(TabNoRecord);
			return nullptr;
		}
	}

	virtual void InsertRecord(Tkey key, PTDataValue pValue_) override{
		if (IsFull()) {
			SetRetCode(TabFull);
		}
		else {
			pRecs[dataCount] = new TTabRecord(key, pValue_);
			dataCount++;
			SetRetCode(TabOkey);
		}
	}

	virtual void DeleteRecord(Tkey key) override{
		PTDataValue tmp = FindRecord(key);
		if (tmp == nullptr) {
			SetRetCode(TabNoRecord);
		}
		else {
			SetRetCode(TabOkey);
			pRecs[curPos] = pRecs[dataCount - 1]; // ruina v pamyati
			dataCount--;
			pRecs[dataCount] = nullptr;
		}
	}
};

