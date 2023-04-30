#pragma once
#include "TTable.h"

#define TabMaxSize 99 


enum TDataPosition
{
	First, Current, Last
};

class TArrayTable : public TTable
{
protected:
	PTTabRecord* pRecs;// массив указателей на записи в таблице
	int tabSize;
	int curPos;

public:
	TArrayTable(int size = TabMaxSize) : tabSize(size){
		pRecs = new PTTabRecord[tabSize];
		for (int i = 0; i < tabSize; i++) {
			pRecs[i] = nullptr;
		}
		curPos = 0;
	}
	virtual ~TArrayTable() {
		for (int i = 0; i < tabSize; i++) {
			delete pRecs[i];
		}
		delete[] pRecs;
	}

	virtual bool IsFull()const {
		return dataCount >= tabSize;
	}

	int GetTabSize() const {
		return tabSize;
	}

	//4 метода 
	virtual Tkey GetKey() const{
		return GetKey(TDataPosition::Current);

	}
	virtual Tkey GetKey(TDataPosition pos) const {
		int local_pos = -1;
		if (!IsEmpty()){
			switch(pos){
			case TDataPosition::First:
				local_pos = 0; 
				break;
			case TDataPosition::Last:
				local_pos = dataCount - 1;
				break;
			default:
				local_pos = curPos;
				break;
			}
		}
		return (local_pos == -1)? "" : pRecs[local_pos] -> key;
	};

	virtual PTDataValue GetValuePtr() const{
		return GetValuePtr(TDataPosition::Current);

	}
	virtual PTDataValue GetValuePtr(TDataPosition pos) const {
		int local_pos = -1;
		if (!IsEmpty()) {
			switch (pos) {
			case TDataPosition::First:
				local_pos = 0;
				break;
			case TDataPosition::Last:
				local_pos = dataCount - 1;
				break;
			default:
				local_pos = curPos;
				break;
			}
		}
		return (local_pos == -1) ? nullptr : pRecs[local_pos]->pValue;
	};
	
	virtual int Reset() {
		curPos = 0;
		return IsTabEnded();
	};
	
	virtual bool IsTabEnded() const{
		return (curPos >= dataCount);
	};
	
	virtual int GoNext() {
		if (!IsTabEnded()) {
			curPos++;
		}
		return IsTabEnded();
	};

	virtual void SetCurrentPosition(int pos) {
		if (pos > -1 && pos < dataCount) {
			curPos = pos;
		}
		else { curPos = 0; }
	}
	int GetCurrentPosition() const{
		return curPos;
	}
	
	friend class TSortTable;

};

