#pragma once
#include "THashTable.h"
#include <list>
class TListHashTable : public THashTable
{
protected:
	size_t tabSize;
	size_t currentList;
	PTTabRecord currentElem;
	std::list<PTTabRecord>::iterator iter;
	std::list<PTTabRecord>* pList;

public:
	TListHashTable(size_t size = 25);
	virtual ~TListHashTable();

	virtual bool isFull() const;

	virtual PTDataValue FindRecord(TKey key) override;
	virtual bool InsertRecord(TKey key, PTDataValue datValue) override;
	virtual void DeleteRecord(TKey key) override;

	virtual int Reset()override;
	virtual int IsTabEnded() const override;
	bool IsListEnded() const;
	virtual int GoNext() override;

	virtual TKey GetKey()const override;
	virtual PTDataValue GetValuePtr() const override;

};

