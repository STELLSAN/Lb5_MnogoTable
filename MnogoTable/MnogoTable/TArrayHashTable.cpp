#include "TArrayHashTable.h"

TArrayHashTable::TArrayHashTable(size_t size, int step) : tabSize(size), hashStep(step) {
	if (size <= 0)
		throw std::exception("Value cannot be less than zero");
	pData = new PTTabRecord[size];
	for (int i = 0; i < size; i++) {
		pData[i] = nullptr;
	}
	pMark = new TTabRecord("", nullptr);
	currentPos = 0;
	freePos = -1;

}

TArrayHashTable::~TArrayHashTable()
{
	for (int i = 0; i < tabSize; i++) {
		if (pData[i] != nullptr && pData[i] != pMark) {
			delete pData[i];
		}

	}
	delete[] pData;
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
		if (pData[currentPos] == nullptr) break; //текущая позиция свободна, записи нет
		else if (pData[currentPos] == pMark) { //запись не пуста, но оттуда что-то удалили
			if (freePos == -1) freePos = currentPos; //можно потом сюда записать
		}
		else if (pData[currentPos]->GetKey() == key) {
			ptmp = pData[currentPos]->GetpValue();  //запись найдена, выход из цикла
			break;
		}
		//пока не найдено, берем следующую возможную
		currentPos = GetNextPosition(currentPos);

	}

	if (ptmp == nullptr) SetRetCode(TAB_NO_RECORD);
	else SetRetCode(TAB_OK);

	return ptmp;
}

bool TArrayHashTable::InsertRecord(TKey key, PTDataValue datValue)
{
	if (IsFull()) {
		SetRetCode(TAB_FULL);
	}
	else {
		PTDataValue tmp = FindRecord(key);
		if (tmp != nullptr) { SetRetCode(TAB_RECORD_DOUBLE); }
		else {
			SetRetCode(TAB_OK);
			if (freePos != -1) currentPos = freePos;
			pData[currentPos] = new TTabRecord(key, datValue);
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
		delete pData[currentPos];
		pData[currentPos] = pMark;
		dataCount--;
	}

}

int TArrayHashTable::Reset()
{
	currentPos = 0;
	while (currentPos < tabSize) {
		if (pData[currentPos] != nullptr && pData[currentPos] != pMark) break;
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
		if (pData[currentPos] != nullptr && pData[currentPos] != pMark) break;
	}
	return IsTabEnded();
}

TKey TArrayHashTable::GetKey() const
{
	if (currentPos >= 0 && currentPos < tabSize) return pData[currentPos]->GetKey();
	return "";
}

PTDataValue TArrayHashTable::GetValuePtr() const
{
	if (currentPos >= 0 && currentPos < tabSize) return pData[currentPos]->GetpValue();
	return nullptr;
}