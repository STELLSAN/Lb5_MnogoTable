#pragma once
#include "TDataCom.h";
#include "Marks.h";
#include "TDataValue.h";
#include "TTable.h";
#include "TTabRecord.h"


#define TAB_OK 0
#define TAB_EMPTY -101
#define TAB_FULL -102
#define TAB_NO_RECORD -103
#define TAB_RECORD_DOUBLE -104
#define TAB_NO_MEM -105

class TTable : public TDataCom  //абстрактный базовый класс, содержит спецификации методов таблицы
{
protected:
    size_t dataCount; 
    size_t efficiency; 

public:
    TTable() : dataCount(0), efficiency(0)
    {}
    virtual ~TTable() {}

    int GetDataCount() const { return dataCount; }
    int GetEfficiency() const { return efficiency; }

    bool IsEmpty() const{ return dataCount == 0;}
    virtual bool IsFull() const = 0;

    virtual PTDataValue FindRecord(TKey key_) = 0;
    virtual bool InsertRecord(TKey key_, PTDataValue pValue_) = 0;
    virtual void DeleteRecord(TKey key_) = 0;

    virtual int Reset() = 0;
    virtual int IsTabEnded()const = 0;
    virtual int GoNext() = 0;

    virtual TKey GetKey()const = 0;
    virtual PTDataValue GetValuePtr() const = 0;

    friend std::ostream& operator<<(std::ostream& os, TTable& tab_)
    {
        for (tab_.Reset(); !tab_.IsTabEnded(); tab_.GoNext())
        {
            os << "Key: " << tab_.GetKey() << " Value: " << *tab_.GetValuePtr() << std::endl;
        }
        return os;
    }
    friend class TScanTable;


};