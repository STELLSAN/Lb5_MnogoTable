#pragma once
#include "TTable.h"

#define TAB_MAX_SIZE 50

enum class Position
{
    FIRST,
    CURRENT,
    LAST
};

class TArrayTable: public TTable {
protected:
    PTTabRecord* pRecs;
    size_t size;
    size_t curPos;
public:

    TArrayTable(size_t size = TAB_MAX_SIZE) : size(size), curPos(0) {
        pRecs = new PTTabRecord[this->size];
        for (int i = 0; i < this->size; i++) {
            pRecs[i] = nullptr;
        }
    }

    virtual ~TArrayTable() {
        for (int i = 0; i < this->size; i++) {
            delete pRecs[i];
        }
        delete[] pRecs;
    }

    virtual bool isFull() const override {
        return dataCount >= size;
    }

    size_t GetSize() const { return size; }
    
    virtual TKey GetKey(Position pos) const;
    virtual TKey GetKey() const { return GetKey(Position::CURRENT); }

    virtual PTDatValue GetValuePtr(Position pos) const;
    virtual PTDatValue GetValuePtr() const { return GetValuePtr(Position::CURRENT); }

    // Сдача 5.1 на хэш таблице
    //virtual PTDatValue FindRecord(TKey key) = 0;
    //virtual bool InsertRecord(TKey key, PTDatValue value) = 0; // передача value по ссылке
    //virtual void DeleteRecord(TKey key) = 0;


    TDataValue* GetValue() const {
        return GetValue(Position::CURRENT);
    }

    TDataValue* GetValue(Position position) const {
        if (isEmpty())
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

    virtual int Reset(void) // установить на первую запись
    {
        this->curPos = 0;
        return this->IsTabEnded();
    }

    virtual int IsTabEnded(void) const // таблица завершена?
    {	
        return this->curPos >= dataCount;
    }

    virtual int GoNext(void)
    {
        if (!this->IsTabEnded())
            this->curPos++;
        return this->IsTabEnded();
    }

    virtual int SetCurrentPos(int pos)// установить текущую запись
    {
        if (pos < 0 || pos > dataCount)
            curPos = 0;
        else
            curPos = pos;
        return IsTabEnded();
    }

    int GetCurrentPos(void) const
    {
        return curPos;
    }

    friend class TSortTable;
};