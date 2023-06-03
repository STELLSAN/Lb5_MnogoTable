#pragma once

#include <iostream>
#include "TDataValue.h"

typedef std::string TKey;

class TTabRecord : public TDataValue {

protected:
    
    TKey _key;
    PTDataValue _pValue; 

    void Print(std::ostream& os) const override {
        os << _key << " " << *_pValue;
    }

    void SetKey(const TKey& key) { _key = key; }
    void SetValue(PTDataValue value) { _pValue = value; }

public:
    TTabRecord(const TKey& key = "", PTDataValue value = nullptr) :
        _key(key), _pValue(value) {}


    TKey GetKey() { return _key; }
    PTDataValue GetValue() { return _pValue; }

    TTabRecord& operator=(const TTabRecord& other) {
        _key = other._key;
        _pValue = other._pValue;

        return *this;
    }

    bool operator==(const TTabRecord& other) {
        return _key == other._key;
    }

    bool operator<(const TTabRecord& other) {
        return _key < other._key;
    }

    bool operator>(const TTabRecord& other) {
        return _key > other._key;
    }

    PTDataValue GetCopy() override {
        return new TTabRecord(_key, _pValue);
    }

    friend class TScanTable;
    friend class TArrayTable;
};

typedef TTabRecord* PTTabRecord;