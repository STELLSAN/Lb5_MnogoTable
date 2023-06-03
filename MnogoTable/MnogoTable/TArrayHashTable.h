#pragma once
#include "THashTable.h"
class TArrayHashTable : public THashTable
{
protected:

	PTTabRecord* pRecs; //массив записей
	size_t tabSize; //размер 
	size_t freePos; //свободная позиция
	size_t currentPos;//текущая позиция
	PTTabRecord pMark;
	int hashStep;

	int GetNextPosition(size_t pos) {
		//???
		return (pos + hashStep) % tabSize;
	}

public:
	explicit TArrayHashTable(size_t size = 50, int hashStep = 7);
	virtual ~TArrayHashTable();

	virtual bool isFull() const override  {
		return dataCount >= tabSize;
	}

	virtual PTDataValue FindRecord(TKey key) override;
	virtual bool InsertRecord(TKey key, PTDataValue dataValue) override;
	virtual void DeleteRecord(TKey key) override;

	virtual int Reset()override;
	virtual int IsTabEnded() const override;
	virtual int GoNext() override;

	virtual TKey GetKey()const override;
	virtual PTDataValue GetValuePtr() const override;



};

