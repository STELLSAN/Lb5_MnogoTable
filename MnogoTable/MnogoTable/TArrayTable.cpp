#include "TArrayTable.h"

TKey TArrayTable::GetKey(Position pos) const
{
    int localPos = -1;
    if (!this->isEmpty())
        switch (pos) {
        case Position::FIRST: 
            localPos = 0;
            break;
        case Position::LAST:
            localPos = dataCount - 1;
            break;
        default:
            localPos = curPos;
            break;
        }
    return (localPos == -1 ? std::string("") : pRecs[localPos]->_key);
}

PTDatValue TArrayTable::GetValuePtr(Position pos) const
{
    int localPos = -1;
    if (!this->isEmpty())
        switch (pos) {
        case Position::FIRST:
            localPos = 0;
            break;
        case Position::LAST:
            localPos = dataCount - 1;
            break;
        default:
            localPos = curPos;
            break;
        }
    return (localPos == -1 ? nullptr : pRecs[localPos]->_pValue);
}
