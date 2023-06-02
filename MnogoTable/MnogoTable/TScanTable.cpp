#include "TScanTable.h"

PTDatValue TScanTable::FindRecord(TKey key)
{
    int i;
    SetRetCode(TAB_OK);
    for (i = 0; i < dataCount; i++)
    {
        if (pRecs[i]->_key == key)
            break;
    }
    efficiency = i + 1;

    if (i < dataCount)
    {
        curPos = i;
        return pRecs[curPos]->_pValue;
    }
    SetRetCode(TAB_NO_RECORD);
    return nullptr;
}

bool TScanTable::InsertRecord(TKey key, PTDatValue value)
{
    if (this->isFull())
    {
        SetRetCode(TAB_FULL);
        return false;
    }
    if (FindRecord(key), GetRetCode() != TAB_NO_RECORD) {
        SetRetCode(TAB_RECORD_DOUBLE);
        return false;
    }
    pRecs[dataCount] = new TTabRecord(key, value);
    dataCount++;
    SetRetCode(TAB_OK);
    return true;
}

void TScanTable::DeleteRecord(TKey key)
{
    PTDatValue t =  this->FindRecord(key);
    if (t == nullptr)
        SetRetCode(TAB_NO_RECORD);
    else
    {
        SetRetCode(TAB_OK);
        pRecs[curPos] = pRecs[dataCount - 1];
        pRecs[--dataCount] = nullptr;
    }
}
