#pragma once
#include "TScanTable.h"

enum SortMeth{
	BubbleSort,
	QuickSort,
	MergeSort,
	InsertSort,
	FreeChoice // на выбор
};

class TSortTable : public TScanTable
{
protected:
	SortMeth _sortMethod;
	
	void BubbleSort(PTTabRecord* data, int size);

	void InsertSort(PTTabRecord* data, int size);

	void QuickSort(PTTabRecord* data, int n1, int n2);
	int QuickSplit(PTTabRecord* data, int n1, int n2); //pivot - опорный элемент

	void MergeSort(PTTabRecord* data, int size);
	void MergeSorter(PTTabRecord* pRecs, PTTabRecord* pBuf,int n1, int n2); //Нужны для сортировки слиянием
	void MergeData(PTTabRecord* pRecs, PTTabRecord* pBuf, int n1, int n2, int mid); //

	void FreeChoice(PTTabRecord* data, int size);

	void Heapify(PTTabRecord* data, int size, int root);

	
public:
	void SortData();
	TSortTable(int size = 50) : TScanTable(size) {};
	TSortTable(const TScanTable& st) {
		*this = st;
	}
	TSortTable& operator=(const TScanTable& ts);
	SortMeth GetSortMethod() {
		return _sortMethod;
	}
	void SetSortMethod(SortMeth sm) {
		_sortMethod = sm;
	}
	virtual PTDataValue FindRecord(TKey key) override;
	virtual bool InsertRecord(TKey key, PTDataValue value) override;
	virtual void DeleteRecord(TKey key) override;

};

