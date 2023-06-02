#pragma once

#include<iostream>
#include<vector>
#include"TDataValue.h"

enum class BookNum {
    DEFAULT,
    FIRST,
    SECOND,
    THIRD,
    FORTH,
    EPILOGUE
};


struct WordCount{
    int bookOne = 0;
    int bookTwo = 0;
    int bookThree = 0;
    int bookFour = 0;
    int epilogue = 0;

    int TWordSum() const {

        return bookOne + bookTwo + bookThree + bookFour + epilogue;
    }
    friend std::ostream& operator<<(std::ostream& ostream, const WordCount& wordCount) {
        ostream << wordCount.bookOne << '\t' << wordCount.bookTwo << '\t' << wordCount.bookThree << '\t' << wordCount.bookFour << '\t' << wordCount.epilogue;
        return ostream;
    }
};

enum class TypeSymbols {
    DEFAULT,
    CYRILIC,
    LATINIC
};

enum class Letter {
    DEFAULT,
    ÑAPITAL,
    SMALL
};

class TWarAndWorld : public TDataValue
{
private:
    WordCount _wordCount{};
    TypeSymbols _typeSymbols;
    Letter _letter;
    short int _lenght;
public:
    TWarAndWorld(TypeSymbols typeSym, Letter letter, short int lenght);
    TWarAndWorld(BookNum booknum, TypeSymbols typeSimbols, Letter letter, short int lenght);
    TWarAndWorld(WordCount wordCount, TypeSymbols typeSymbols, Letter letter, short int lenght);


    void AddCount(BookNum bookNum) {
        switch (bookNum)
        {
        case BookNum::FIRST:
            _wordCount.bookOne++;
            break;
        case BookNum::SECOND:
            _wordCount.bookTwo++;
            break;
        case BookNum::THIRD:
            _wordCount.bookThree++;
            break;
        case BookNum::FORTH:
            _wordCount.bookFour++;
            break;
        case BookNum::EPILOGUE:
            _wordCount.epilogue++;
            break;
        }
    }

    /*
    * Ãåòòåðû
    */

    void Print(std::ostream& os) const override;

    TDataValue* GetCopy() {
        return new TWarAndWorld(_wordCount, _typeSymbols, _letter, _lenght);
    }

};

