#include "TArrayHashTable.h"

TArrayHashTable::TArrayHashTable(size_t size, int step) : tabSize(size), hashStep(step) {
	if (size <= 0)
		throw std::exception("Value cannot be less than zero");
	pRecs = new PTTabRecord[size];
	for (int i = 0; i < size; i++) {
		pRecs[i] = nullptr;
	}
	pMark = new TTabRecord("", nullptr);
	currentPos = 0;
	freePos = -1;

}

TArrayHashTable::~TArrayHashTable()
{
	for (int i = 0; i < tabSize; i++) {
		if (pRecs[i] != nullptr && pRecs[i] != pMark) {
			delete pRecs[i];
		}

	}
	delete[] pRecs;
	delete pMark;
}

PTDataValue TArrayHashTable::FindRecord(TKey key)
{
	SetRetCode(TAB_OK);
	PTDataValue ptmp = nullptr;
	freePos = -1;
	efficiency = 0;
	currentPos = HashFunc(key) % tabSize; //определяет примерное положение

	for (int i = 0; i < tabSize; i++) {
		efficiency++;
		if (pRecs[currentPos] == nullptr) break; //свободная позиция, нужного key нет
		else if (pRecs[currentPos] == pMark) { // из позиции что-то удалили
			if (freePos == -1) freePos = currentPos; //суда можно будет записать
		}
		else if (pRecs[currentPos]->GetKey() == key) {
			ptmp = pRecs[currentPos]->GetValue();  //нашли запись
			break;
		}
		//берём каждую следующую, пока не найдено 
		currentPos = GetNextPosition(currentPos);

	}

	if (ptmp == nullptr) SetRetCode(TAB_NO_RECORD);
	else SetRetCode(TAB_OK);

	return ptmp;
}

bool TArrayHashTable::InsertRecord(TKey key, PTDataValue datValue)
{
	if (isFull()) {
		SetRetCode(TAB_FULL);
	}
	else {
		PTDataValue tmp = FindRecord(key);
		if (tmp != nullptr) { SetRetCode(TAB_RECORD_DOUBLE); }
		else {
			SetRetCode(TAB_OK);
			if (freePos != -1) currentPos = freePos;
			pRecs[currentPos] = new TTabRecord(key, datValue);
			dataCount++;
			return true;
		}
	}
	return false;
}

void TArrayHashTable::DeleteRecord(TKey key)
{
	PTDataValue tmp = FindRecord(key);
	if (tmp == nullptr) {
		SetRetCode(TAB_NO_RECORD);
	}
	else {
		SetRetCode(TAB_OK);
		delete pRecs[currentPos];
		pRecs[currentPos] = pMark;
		dataCount--;
	}

}

int TArrayHashTable::Reset()
{
	currentPos = 0;
	while (currentPos < tabSize) {
		if (pRecs[currentPos] != nullptr && pRecs[currentPos] != pMark) break;
		currentPos++;

	}
	return IsTabEnded();
}

int TArrayHashTable::IsTabEnded() const
{
	return currentPos >= tabSize;
}

int TArrayHashTable::GoNext()
{
	while (!IsTabEnded()) {	
			currentPos++;
			if (pRecs[currentPos] != nullptr && pRecs[currentPos] != pMark) break;
	}
	return IsTabEnded();
}

TKey TArrayHashTable::GetKey() const
{
	if (currentPos >= 0 && currentPos < tabSize) return pRecs[currentPos]->GetKey();
	return "";
}

PTDataValue TArrayHashTable::GetValuePtr() const
{
	if (currentPos >= 0 && currentPos < tabSize) return pRecs[currentPos]->GetValue();
	return nullptr;
}