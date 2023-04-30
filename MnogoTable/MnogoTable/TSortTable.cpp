#include "TSortTable.h"


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
	case SortType::Insert:
		InsertSort(pRecs, dataCount);
		break;
	case SortType::Merge:
		MergeSort(pRecs, dataCount);
		break;
	case SortType::Quick:
		QuickSort(pRecs, dataCount);
		break;
	case SortType::Free:
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

