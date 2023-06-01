#pragma once
#include <string>
#include <iostream>
#include "TDataValue.h"

typedef std::string TKey;

class TTabRecord : public TDataValue // модуль с классом объектов-значений для записей таблицы
{
protected:
    TKey _key;
    PTDataValue _pValue;

    virtual void Print(std::ostream& os) const override{
        os << _key << " " << *_pValue << std::endl;
    }

    void SetKey(const TKey& key) { _key = key; }
    void SetValue(PTDataValue value) { _pValue = value; }

public:

    TTabRecord(TKey key_ = " ", PTDataValue pValue_ = nullptr) 
        : _key(key_), _pValue(pValue_)
    {}

    TKey GetKey() { return _key;}
    PTDataValue GetpValue() { return _pValue; }


    virtual TDataValue* GetCopy()
    {
        return new TTabRecord(_key, _pValue);
    };

    TTabRecord& operator=(const TTabRecord& tab_)
    {
        _key = tab_._key;
        _pValue = tab_._pValue;
        return *this;
    }
    virtual bool operator==(const TTabRecord& tab_)
    {
        return _key == tab_._key;
    }
    virtual bool operator<(const TTabRecord& tab_)
    {
        return _key < tab_._key;
    }
    virtual bool operator>(const TTabRecord& tab_)
    {
        return _key > tab_._key;
    }

    friend class TArrayTable;
    friend class TScanTable;

};

typedef TTabRecord* PTTabRecord;