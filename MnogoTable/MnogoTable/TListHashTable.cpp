#include "TListHashTable.h"

TListHashTable::TListHashTable(size_t size) : tabSize(size), currentList(0)
{
	if (size <= 0)
		throw std::exception("value cannot be zero");

	pList = new std::list<PTTabRecord>[size];
	for (int i = 0; i < size; i++) {
		pList[i] = std::list<PTTabRecord>();
	}
	currentList = 0;
	iter = pList[currentList].begin();
}

TListHashTable::~TListHashTable()
{
	delete[] pList;
}

bool TListHashTable::isFull() const
{
	return pList == nullptr;
}

PTDataValue TListHashTable::FindRecord(TKey key)
{
	PTDataValue pValue = nullptr;
	currentList = HashFunc(key) % tabSize;
	efficiency = 0;

	

	for (auto iterator = pList[currentList].begin(); iterator != pList[currentList].end(); ++iterator)
	{
		efficiency++;
		if ((*iterator)->GetKey() == key)
		{
			pValue = (*iterator)->GetValue();
			iter = iterator;
			break;
		}
	}

	if (pValue == nullptr) {
		SetRetCode(TAB_NO_RECORD);

	}
	else {
		SetRetCode(TAB_OK);
	}

	return pValue;
}

bool TListHashTable::InsertRecord(TKey key, PTDataValue datValue)
{
	if (isFull()) {
		SetRetCode(TAB_FULL);
	}
	else {
		PTDataValue pVal = FindRecord(key);
		if (pVal != nullptr) {
			SetRetCode(TAB_RECORD_DOUBLE);
		}
		else {
			SetRetCode(TAB_OK);
			dataCount++;
			pList[currentList].push_front(new TTabRecord(key, datValue));
			return true;
		}
	}
	return false;


}

void TListHashTable::DeleteRecord(TKey key)
{
	auto tmp = FindRecord(key);
	if (tmp == nullptr) {
		SetRetCode(TAB_NO_RECORD);
	}
	else {
		SetRetCode(TAB_OK);
		dataCount--;
		pList[currentList].remove(currentElem);
		Reset();
		efficiency++;
	}
}

int TListHashTable::Reset()
{
	currentList = 0;
	while (pList[currentList].empty() and !IsTabEnded()) currentList++;
	iter = pList[currentList].begin();
	return IsTabEnded();
}

int TListHashTable::IsTabEnded() const 
{
	return currentList >= tabSize;
}

bool TListHashTable::IsListEnded() const
{
	auto tmp = iter;
	return ++tmp == pList[currentList].end(); // lpValue è rpValue 
}

int TListHashTable::GoNext()
{
	if (!IsListEnded()) {
		iter++;
	}
	else if (!IsTabEnded()) {
		while (pList[++currentList].empty() and !IsTabEnded());
		iter = pList[currentList].begin();
	}
	return IsTabEnded();
}

TKey TListHashTable::GetKey() const
{
	return (*iter)->GetKey();
}

PTDataValue TListHashTable::GetValuePtr() const
{
	return (*iter)->GetValue();
}
