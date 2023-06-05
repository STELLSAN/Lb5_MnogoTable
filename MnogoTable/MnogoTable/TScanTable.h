#pragma once

#include "TArrayTable.h"

class TScanTable : public TArrayTable
{
public:
	TScanTable(size_t size = 50) : TArrayTable(size) {}
	virtual PTDataValue FindRecord(TKey key) override;
	
	virtual bool InsertRecord(TKey key, PTDataValue value)override;
	virtual void DeleteRecord(TKey key)override;
};

