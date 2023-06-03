#pragma once
#include "TDataValue.h"
enum class BookNumber { // enum äëÿ ÷àñòåé ñåðèè
    DEFAULT,
    FIRST,
    SECOND,
    THIRD,
    FORTH,
    EPILOGUE
};

struct WordCounts { // Ñ÷¸ò÷èê ñëîâ
    int bookOne=0;
    int bookTwo=0;
    int bookThree=0;
    int bookFour=0;
    int epilogue=0;

    int SumWord() const {return bookOne + bookTwo + bookThree + bookFour + epilogue;}

    BookNumber Prevailing() const { //?
        int p = 0;
        BookNumber s = BookNumber::DEFAULT;
        if (bookOne > p) {
            p = bookOne;
            s = BookNumber::FIRST;
        }
        if (bookTwo > p) {
            p = bookTwo;
            s = BookNumber::SECOND;
        }
        if (bookThree > p) {
            p = bookThree;
            s = BookNumber::THIRD;
        }
        if (bookFour > p) {
            p = bookFour;
            s = BookNumber::FORTH;
        }
        if (epilogue > p) {
            p = epilogue;
            s = BookNumber::EPILOGUE;
        }
        return s;
    }

};
enum class TypeSymbol { 
    DEFAULT,
    CYRILLIC,
    LATINIC
};
enum class TypeLetter { 
    DEFAULT,
    ÑAPITAL,
    SMALL
};
class TWarAndWorld: public TDataValue
{ 
    WordCounts _wordCounts{}; 
    TypeSymbol _typeSym; 
    TypeLetter _typeLetter; 
    uint16_t _length; 

public:
    TWarAndWorld(TypeSymbol typeSym, TypeLetter letter, short int lenght) {
        _typeSym = typeSym;
        _typeLetter = letter;
        _length = lenght;
    }

    TWarAndWorld(WordCounts wordCounts, TypeSymbol sym, TypeLetter letter, short int lenght) {
        _typeSym = sym;
        _typeLetter = letter;
        _length = lenght;
        _wordCounts.bookOne = wordCounts.bookOne;
        _wordCounts.bookTwo = wordCounts.bookTwo;
        _wordCounts.bookThree = wordCounts.bookThree;
        _wordCounts.bookFour = wordCounts.bookFour;
        _wordCounts.epilogue = wordCounts.epilogue;
    }

    TWarAndWorld(BookNumber bookNum, TypeSymbol sym, TypeLetter letter, short int lenght) {
        _typeSym = sym;
        _typeLetter = letter;
        _length = lenght;
        switch (bookNum) {
        case BookNumber::FIRST:
            _wordCounts.bookOne++; break;
        case BookNumber::SECOND:
            _wordCounts.bookTwo++; break;
        case BookNumber::THIRD:
            _wordCounts.bookThree++; break;
        case BookNumber::FORTH:
            _wordCounts.bookFour++; break;
        case BookNumber::EPILOGUE:
            _wordCounts.epilogue++; break;

        }
        
    }

    TWarAndWorld() {
        _typeSym = TypeSymbol::DEFAULT;
        _typeLetter = TypeLetter::DEFAULT;
        _length = 0;
    }

    void AddCount(BookNumber vol) {
        switch (vol)
        {
        case BookNumber::FIRST:
            _wordCounts.bookOne++;
            break;
        case BookNumber::SECOND:
            _wordCounts.bookTwo++;
            break;
        case BookNumber::THIRD:
            _wordCounts.bookThree++;
            break;
        case BookNumber::FORTH:
            _wordCounts.bookFour++;
            break;
        case BookNumber::EPILOGUE:
            _wordCounts.epilogue++;
            break;
        }
    };

    TypeSymbol GetTypeSym() {
        return _typeSym;
    }

    TypeLetter GetLetter() {
        return _typeLetter;
    }

    int GetLength() {
        return _length;
    }

    int GetWordCount() {
        return _wordCounts.SumWord();
    }

    BookNumber GetPrevailing() {
        return _wordCounts.Prevailing();
    }

    void operator =(const TWarAndWorld& wr) {
        _wordCounts.bookOne = wr._wordCounts.bookOne;
        _wordCounts.bookTwo = wr._wordCounts.bookTwo;
        _wordCounts.bookThree = wr._wordCounts.bookThree;
        _wordCounts.bookFour = wr._wordCounts.bookFour;
        _wordCounts.epilogue = wr._wordCounts.epilogue;
        _typeSym = wr._typeSym;
        _typeLetter = wr._typeLetter;
        _length = wr._length;
    }

    void Print(std::ostream& os) const {
        os << _wordCounts.SumWord() << '\t';
        
        switch (_wordCounts.Prevailing()) {
        case BookNumber::FIRST:
            os << "FIRST" << '\t'; 
            break;
        case BookNumber::SECOND:
            os << "SECOND" << '\t'; 
            break;
        case BookNumber::THIRD:
            os << "THIRD" << '\t'; 
            break;
        case BookNumber::FORTH:
            os << "FORTH" << '\t'; 
            break;
        case BookNumber::EPILOGUE:
            os << "EPILOGUE" << '\t'; 
            break;
        }
        

        switch (_typeSym) {
        case TypeSymbol::CYRILLIC:
            os << "CYRILLIC" << '\t';
            break;
        case TypeSymbol::LATINIC:
            os << "LATINIC" << '\t';
            break;
        default:
            os << "DEFAULT" << '\t';
            break;
        }

        switch (_typeLetter) {
        case TypeLetter::ÑAPITAL:
            os << "ÑAPITAL" << '\t';
            break;
        case TypeLetter::SMALL:
            os << "SMALL" << '\t';
            break;
        default:
            os << "DEFAULT" << '\t';
            break;
        }

        os << _length << '\t';
        
    }

    TDataValue* GetCopy() {
        return new TWarAndWorld(_wordCounts, _typeSym, _typeLetter, _length);
    }
};

