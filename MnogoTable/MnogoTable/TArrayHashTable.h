#pragma once
#include "THashTable.h"
class TArrayHashTable : public THashTable
{
protected:

	PTTabRecord* pData; //������ �������
	size_t tabSize; //������ 
	size_t freePos; //��������� �������
	size_t currentPos;//������� �������
	PTTabRecord pMark;
	int hashStep;

	int GetNextPosition(size_t pos) {
		//???
		return (pos + hashStep) % tabSize;
	}

public:
	explicit TArrayHashTable(size_t size = 50, int hashStep = 7);
	virtual ~TArrayHashTable();

	virtual bool IsFull() const override {
		return dataCount >= tabSize;
	}

	virtual PTDataValue FindRecord(TKey key) override;
	virtual bool InsertRecord(TKey key, PTDataValue datValue) override;
	virtual void DeleteRecord(TKey key) override;

	virtual int Reset()override;
	virtual int IsTabEnded() const override;
	virtual int GoNext() override;

	virtual TKey GetKey()const override;
	virtual PTDataValue GetValuePtr() const override;



};

