#pragma once
#include"TScanTable.h"

enum SortType {
    InsertSort,
    QuickSort,
    MergeSort,
    HeapSort
};


class TSortTable : public TScanTable
{
protected:
    SortType sortType;

    void InsertSort(PTTabRecord* pmem, int size );

    void QuickSort(PTTabRecord* pmem, int size);
    void QuickSplit(PTTabRecord* pmem, int size, int& pivot);

    void MergeSort(PTTabRecord* pmem, int size);
    void MergeSorter(PTTabRecord *&pdata, PTTabRecord *&pbuf, int size);
    void MergeData(PTTabRecord*& pdata, PTTabRecord*& pbuf, int n1, int n2); // слияние | n1, n2 -

    void FreeSort(PTTabRecord* pmem, int size);

    void Heapify(PTTabRecord* data, int size, int root);
public:
    void SortData();

    TSortTable(SortType srtT,int size = TABMAXSIZE) : TScanTable(size), sortType(srtT) {};

    TSortTable(const TScanTable& st);

    TSortTable& operator=(const TScanTable& st);

    SortType GetSortType() const{ return sortType; };

    virtual PTDataValue FindRecord(TKey key) override;

    virtual bool InsertRecord(TKey key, PTDataValue pValue_) override;

    virtual void DeleteRecord(TKey key) override;

};

