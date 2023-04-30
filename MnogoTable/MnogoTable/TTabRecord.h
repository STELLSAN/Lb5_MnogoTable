#pragma once
#include <string>
#include <iostream>
#include "TDataValue.h"

typedef std::string Tkey;

class TTabRecord : public TDataValue
{
protected:
	Tkey key;
	PTDataValue pValue;

	virtual void Print(std::ostream& os)
	{
		os << key << " " << *pValue << std::endl;
	}

public:

	TTabRecord(Tkey key_ = " ", PTDataValue pValue_ = nullptr) 
		: key(key_), pValue(pValue_)
	{}


	Tkey GetKey() { return key;}
	PTDataValue GetpValue() { return pValue; }


	virtual TDataValue* GetCopy()
	{
		return new TTabRecord(key, pValue);
	};

	TTabRecord& operator=(const TTabRecord& tab_)
	{
		key = tab_.key;
		pValue = tab_.pValue;
		return *this;
	}
	virtual bool operator==(const TTabRecord& tab_)
	{
		return key == tab_.key;
	}
	virtual bool operator<(const TTabRecord& tab_)
	{
		return key < tab_.key;
	}
	virtual bool operator>(const TTabRecord& tab_)
	{
		return key > tab_.key;
	}
	friend class TArrayTable;

};

typedef TTabRecord* PTTabRecord;