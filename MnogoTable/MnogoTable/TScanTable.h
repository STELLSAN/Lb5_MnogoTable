#pragma once
#include "TArrayTable.h"

class TScanTable : public TArrayTable  //модуль с классом, обеспечивающим реализацию просматриваемых таблиц;
{
public:
    TScanTable(int size = TABMAXSIZE) :TArrayTable(size) {}

    virtual PTDataValue FindRecord(TKey key) override {
        int i;
        SetRetCode(TAB_OK);
        for (i = 0; i < dataCount; i++) {
            if (pRecs[i]->GetKey() == key) {
                break;
            }
        }
        efficiency = i + 1;
        if (i < dataCount) {
            curPos = i;
            return pRecs[i]->_pValue;
        }
        else {
            SetRetCode(TAB_NO_RECORD);
            return nullptr;
        }
    }

    virtual bool InsertRecord(TKey key, PTDataValue pValue_) override {
        if (IsFull()) {
            SetRetCode(TAB_FULL);
            return false;
        }
        if (FindRecord(key), GetRetCode() != TAB_NO_RECORD) {
            SetRetCode(TAB_RECORD_DOUBLE);
            return false;
        }
        pRecs[dataCount] = new TTabRecord(key, pValue_);
        dataCount++;
        SetRetCode(TAB_OK);
        return true;
    }

    virtual void DeleteRecord(TKey key) override{
        PTDataValue tmp = FindRecord(key);
        if (tmp == nullptr) {
            SetRetCode(TAB_NO_RECORD);
        }
        else {
            SetRetCode(TAB_OK);
            pRecs[curPos] = pRecs[dataCount - 1]; // ruina v pamyati
            dataCount--;
            pRecs[dataCount] = nullptr;
        }
    }
};

