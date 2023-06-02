#pragma once
#include "TTable.h"

#define TABMAXSIZE 99 


enum Position
{
    FIRST, CURRENT, LAST
};

class TArrayTable : public TTable  // абстрактный базовый класс для таблиц с непрерывной памятью
{
protected:
    PTTabRecord* pRecs;// массив указателей на записи в таблице
    size_t tabSize;
    size_t curPos;

public:
    TArrayTable(int size = TABMAXSIZE) : tabSize(size), curPos(0) {
        pRecs = new PTTabRecord[tabSize];
        for (int i = 0; i < tabSize; i++) {
            pRecs[i] = nullptr;
        }
    }

    virtual ~TArrayTable() {
        for (int i = 0; i < tabSize; i++) {
            delete pRecs[i];
        }
        delete[] pRecs;
    }

    virtual bool IsFull() const {
        return dataCount >= tabSize;
    }

    int GetTabSize() const {  return tabSize; }
    /*
    
    virtual TKey GetKey() const{return GetKey(Position::CURRENT);}
    virtual TKey GetKey(Position pos) const {
        int local_pos = -1;
        if (!IsEmpty()){
            switch(pos){
            case Position::FIRST:
                local_pos = 0; 
                break;
            case Position::LAST:
                local_pos = dataCount - 1;
                break;
            default:
                local_pos = curPos;
                break;
            }
        }
        return (local_pos == -1)? "" : pRecs[local_pos] -> _key;
    };
    */


    TDataValue* GetValue() const {return GetValue(Position::CURRENT);}
    TDataValue* GetValue(Position position) const {
        if (IsEmpty())
            return nullptr;

        uint32_t index;
        switch (position) {
        case Position::FIRST:
            index = 0;
            break;
        case Position::LAST:
            index = TTable::dataCount - 1;
            break;
        default:
            index = curPos;
            break;
        }
        return pRecs[index]->_pValue;
    }


    virtual PTDataValue GetValuePtr() const{ return GetValuePtr(Position::CURRENT);}
    virtual PTDataValue GetValuePtr(Position pos) const {
        int local_pos = -1;
        if (!IsEmpty()) {
            switch (pos) {
            case Position::FIRST:
                local_pos = 0;
                break;
            case Position::LAST:
                local_pos = dataCount - 1;
                break;
            default:
                local_pos = curPos;
                break;
            }
        }
        return (local_pos == -1) ? nullptr : pRecs[local_pos]->_pValue;
    };  
    

    virtual TKey GetKey()const;
    //virtual PTDataValue FindRecord(TKey key_);
    //virtual bool InsertRecord(TKey key_, PTDataValue pValue_);
    //virtual void DeleteRecord(TKey key_);

    virtual int Reset() {  
        curPos = 0;
        return IsTabEnded();
    };
    
    virtual int IsTabEnded() const{ 
        return (curPos >= dataCount);
    };
    
    virtual int GoNext() {
        if (!IsTabEnded()) {
            curPos++;
        }
        return IsTabEnded();
    };

    virtual void SetCurrentPosition(int pos) {
        if (pos > -1 && pos < dataCount) {
            curPos = pos;
        }
        else { curPos = 0; }
    }
    int GetCurrentPosition() const{
        return curPos;
    }
    
    friend class TSortTable;

};

