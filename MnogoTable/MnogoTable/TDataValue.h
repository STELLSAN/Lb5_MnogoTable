#pragma once

#include<iostream>
class TDataValue {
protected:
    virtual void Print(std::ostream& os) const = 0;
public:
    TDataValue() {};
    virtual TDataValue* GetCopy() = 0;
    friend std::ostream& operator << (std::ostream& out, TDataValue& tdv) {
        if (&tdv != nullptr)
        {
            tdv.Print(out);
        }
        return out;
    }
};

typedef TDataValue* PTDataValue;



