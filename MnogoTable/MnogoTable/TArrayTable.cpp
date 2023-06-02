#include "TArrayTable.h"

 TKey TArrayTable::GetKey() const {
     int localPos = -1;
     if (!this->IsEmpty())
         switch (curPos) {
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
