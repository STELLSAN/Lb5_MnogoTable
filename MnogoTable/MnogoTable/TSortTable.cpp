#include "TSortTable.h"

void TSortTable::QuickSort(PTTabRecord* pmem, int size) {}
void TSortTable::QuickSplit(PTTabRecord* pmem, int size, int& pivot) {}

void TSortTable::MergeSort(PTTabRecord* pmem, int size) {}
void TSortTable::MergeSorter(PTTabRecord*& pdata, PTTabRecord*& pbuf, int size) {}
void TSortTable::MergeData(PTTabRecord*& pdata, PTTabRecord*& pbuf, int n1, int n2) {} // слияние | n1, n2 -

void TSortTable::FreeSort(PTTabRecord* pmem, int size) {}

void TSortTable::Heapify(PTTabRecord* data, int size, int root) {}

PTDataValue TSortTable::FindRecord(TKey key)
{
    int first = 0, last = dataCount - 1, mid;
    efficiency = 0;
    SetRetCode(TAB_OK);
    while (first < last) {
        efficiency++;
        mid = (first + last) >> 1;
        if (pRecs[mid]->GetKey() == key) {
            first = mid + 1;
            last = mid;
        }
        else if (pRecs[mid]->GetKey() > key)
            last = mid - 1;
        else
            first = mid + 1;
    }
    if (last < 0 || pRecs[last]->GetKey() < key) { // Может ли быть mid < 0 
        last++;
    }
    curPos = last;
    if (last < dataCount && (pRecs[last]->GetKey() == key)) {
        SetRetCode(TAB_OK);
        return pRecs[last]->GetpValue();
    }
    SetRetCode(TAB_NO_RECORD);
    return nullptr;
}

bool TSortTable::InsertRecord(TKey key, PTDataValue value)
{
    if (IsFull()) {
        SetRetCode(TAB_FULL);
        return false;
    }
    else {
        PTDataValue tmp = FindRecord(key);
        if (retCode == TAB_OK) {
            SetRetCode(TAB_RECORD_DOUBLE);
            return false;
        }
        else {
            retCode = TAB_OK;
            for (int i = dataCount; i > curPos; i--) {
                pRecs[i] = pRecs[i - 1];
            }
            pRecs[curPos] = new TTabRecord(key, value);
            dataCount++;
            SetRetCode(TAB_OK);
            efficiency++;
            return true;
        }
    }

}

void TSortTable::DeleteRecord(TKey key)
{
    FindRecord(key);
    if (retCode == TAB_OK) {
        for (int i = curPos; i < dataCount - 1; i++) {
            pRecs[i] = pRecs[i + 1];
        }
        pRecs[--dataCount] = nullptr;
    } // Проблема с утечкой памяти. Доказать
}

TSortTable::TSortTable(const TScanTable& st) {
	*this = st;
}

TSortTable& TSortTable::operator=(const TScanTable& st) {
	if (pRecs != nullptr) {
		for (int i = 0; i < dataCount; i++) {
			delete pRecs[i];
		}
		delete[] pRecs;
	}
	tabSize = st.tabSize;
	dataCount = st.dataCount;
	pRecs = new PTTabRecord[tabSize];
	for (int i = 0; i < dataCount; i++) {
		pRecs[i] = (PTTabRecord)(st.pRecs[i]->GetCopy());
	}
	SortData();
	curPos = st.curPos;
	return *this;
}

void TSortTable::SortData() {
	efficiency = 0; // запоминане итераций
	switch (sortType) {
	case SortType::InsertSort:
		InsertSort(pRecs, dataCount);
		break;
	case SortType::MergeSort:
		MergeSort(pRecs, dataCount);
		break;
	case SortType::QuickSort:
		QuickSort(pRecs, dataCount);
		break;
	case SortType::HeapSort:
		FreeSort(pRecs, dataCount);
		break;
	}
}

void TSortTable::InsertSort(PTTabRecord* pmem, int size) {
	PTTabRecord tmp;
	efficiency = dataCount;
	for (int i = 1, j; i < dataCount; i++) {
		tmp = pRecs[i];
		for (j = i - 1; j > -1; j--) {
			if (pRecs[j]->GetKey() > tmp->GetKey()) {
				pRecs[j + 1] = pRecs[j];
				efficiency++;
			}
			else {
				break;
			}
		}
		pRecs[j + 1] = tmp;
	}
}

// sravnenie effinciecy and time po vsem sortam; rapsrsit Voinu & mir

