#pragma once
#include"TScanTable.h"

enum SortType {
	Insert,
	Merge,
	Quick,
	Free
};


class TSortTable : public TScanTable
{
protected:
	SortType sortType;
	void SortData();
	void InsertSort(PTTabRecord* pmem, int size );

	void MergeSort(PTTabRecord* pmem, int size);
	void MergeSorter(PTTabRecord *&pdata, PTTabRecord *&pbuf, int size);
	void MergeData(PTTabRecord*& pdata, PTTabRecord*& pbuf, int n1, int n2); // слияние | n1, n2 - 

	void QuickSort(PTTabRecord* pmem, int size);
	void QuickSplit(PTTabRecord* pmem, int size, int& pivot);

	void FreeSort(PTTabRecord* pmem, int size);
public:
	TSortTable(SortType srtT,int size = TabMaxSize) : TScanTable(size), sortType(srtT) {};

	TSortTable(const TScanTable& st);

	TSortTable& operator=(const TScanTable& st);

	SortType GetSortType() const{ return sortType; };

	virtual PTDataValue FindRecord(Tkey key) override;

	virtual void InsertRecord(Tkey key, PTDataValue pValue_) override;

	virtual void DeleteRecord(Tkey key) override;

};

