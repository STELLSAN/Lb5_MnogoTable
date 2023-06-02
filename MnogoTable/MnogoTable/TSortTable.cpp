#include "TSortTable.h"

TSortTable& TSortTable::operator=(const TScanTable& ts)
{
    if (pRecs != nullptr) {
        for (int i = 0; i < dataCount; i++){
            delete pRecs[i];
        }
        delete []pRecs;
        pRecs = nullptr;
    }
    size = ts.GetSize();
    dataCount = ts.GetDataCount();
    pRecs = new PTTabRecord[this->size];
    for (int i = 0; i < dataCount; i++) {
        pRecs[i] = (PTTabRecord)ts.pRecs[i]->GetCopy();
    }

   // SortData();
    curPos = 0;

    return *this;
}

PTDatValue TSortTable::FindRecord(TKey key)
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
        return pRecs[last]->GetValue();
    }
    SetRetCode(TAB_NO_RECORD);
    return nullptr;
}

bool TSortTable::InsertRecord(TKey key, PTDatValue value)
{
    if (isFull()) {
        SetRetCode(TAB_FULL);
        return false;
    }
    else {
        PTDatValue tmp = FindRecord(key);
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

void TSortTable::SortData()
{
    efficiency = 0;
    switch (_sortMethod) {
        case SortMeth::BubbleSort:
            BubbleSort(pRecs, GetDataCount());
            break;
        case SortMeth::QuickSort:
            QuickSort(pRecs, 0, GetDataCount()-1);
            break;
        case SortMeth::MergeSort:
            MergeSort(pRecs, GetDataCount());
            break;
        case SortMeth::InsertSort:
            InsertSort(pRecs, GetDataCount());
            break;
        default:
            FreeChoice(pRecs, GetDataCount());
            break;
    }
}

void TSortTable::BubbleSort(PTTabRecord* data, int size)
{
    PTTabRecord curElem;
    efficiency = dataCount;
    for (size_t i = 0; i + 1 < dataCount; ++i) {
        for (size_t j = 0; j + 1 < dataCount - i; ++j) {
            if (data[j+1]->GetKey() < data[j]->GetKey()) {
                curElem = data[j];
                data[j] = data[j+1];
                data[j + 1] = curElem;
            }
        }
    }
}

void TSortTable::InsertSort(PTTabRecord* data, int size)
{
    PTTabRecord curElem;
    efficiency = dataCount;
    for (int i = 1,j; i < dataCount; i++) {
        curElem = data[i];
        for (j = i - 1; j > -1; j--) {
            if (data[j]->GetKey() > curElem->GetKey()) {
                data[j + 1] = data[j];
                efficiency++;
            }
            else {
                break;
            }
        
        }
        data[j + 1] = curElem;
    }
}

void TSortTable::MergeSort(PTTabRecord* data, int size)
{
    PTTabRecord* pBuf = new PTTabRecord[this->size];
    MergeSorter(data, pBuf, 0, size-1);
}

void TSortTable::MergeSorter(PTTabRecord* pRecs, PTTabRecord* pBuf, int n1, int n2)
{
    
    
    int mid;
    if (n1 < n2) {

        mid = (n1 + n2) / 2;
        MergeSorter(pRecs, pBuf, n1, mid);
        MergeSorter(pRecs, pBuf, mid + 1, n2);

        MergeData(pRecs, pBuf, n1, n2, mid);
    }
}

void TSortTable::MergeData(PTTabRecord* pRecs, PTTabRecord* pBuf, int n1, int n2, int mid)
{
    int k = n1, i = n1, j = mid + 1;

    // Пока есть элементы в левом и правом прогонах
    while (i <= mid && j <= n2)
    {
        if (pRecs[i]->GetKey() <= pRecs[j]->GetKey()) {
            pRecs[i];
            pBuf[k++] = pRecs[i++];
        }
        else {
            pRecs[j];
            pBuf[k++] = pRecs[j++];
        }
    }

    // Копируем оставшиеся элементы
    while (i <= mid) {
        pBuf[k++] = pRecs[i++];
    }
    while (j <= n2) {
        pBuf[k++] = pRecs[j++];
    }
    // Вторую половину копировать не нужно (поскольку остальные элементы
    // уже находятся на своем правильном месте во вспомогательном массиве)

    // копируем обратно в исходный массив, чтобы отразить порядок сортировки
    for (int i = n1; i <= n2; i++) {
        pRecs[i] = pBuf[i];
    }
}

void TSortTable::FreeChoice(PTTabRecord* data, int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        Heapify(data, size, i);

    for (int i = size - 1; i >= 0; i--)
    {
        std::swap(data[0], data[i]);
        Heapify(data, i, 0);
    }
}

void TSortTable::Heapify(PTTabRecord* data, int size, int root)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < size && data[l]->GetKey() > data[largest]->GetKey())
        largest = l;

    if (r < size && data[r]->GetKey() > data[largest]->GetKey())
        largest = r;

    if (largest != root)
    {
        std::swap(data[root], data[largest]);
        Heapify(data, size, largest);
    }
}



void TSortTable::QuickSort(PTTabRecord* data, int n1, int n2)
{
    //int pivot = size / 2;
    //QuickSplit(data,  n1, n2, pivot);
    //if (pivot > 0) {
    //    //"Левый кусок"
    //    QuickSort(data, n1, pivot-1);
    //}
    //if (size> pivot+1) {
    //   
    //    QuickSort(data, pivot+1, n2);
    //}

    if (n1 < n2)
    {
       int pivot= QuickSplit(data, n1, n2);

       QuickSort(data, n1, pivot - 1);
       QuickSort(data, pivot + 1, n2);
    }
}

int TSortTable::QuickSplit(PTTabRecord* data, int n1,  int n2)
{
    int i = n1, pivot=n2;
    while (i < pivot)
    {
        if (data[i]->GetKey() > data[pivot]->GetKey() && i == pivot - 1)
        {
            std::swap(data[i], data[pivot]);
            pivot--;
        }

        else if (data[i]->GetKey() > data[pivot]->GetKey())
        {
            
            std::swap(data[pivot - 1], data[pivot]);
            std::swap(data[i], data[pivot]);
            pivot--;
        }

        else i++;
    }
    return pivot;
    
}
