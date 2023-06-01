#pragma once

#include<iostream>
#include<vector>
#include"TDataValue.h"

enum BookNum {
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
    WORD,
    NUMBER,
    PUNCTUATION_MARK,
};

enum class Language {
    DEFAULT,    
    RUSSIAN,
    FRENCH,
    NONE,
};


class TWarAndWorld : public TDataValue
{
private:
    WordCount _wordCount{};
    TypeSymbols _typeSymbols;
    Language _language;
    std::vector<uint32_t> _seqNumbers;
public:
    /*
    * 
    * WordCount
    * TypeSymbols
    * Language
    */
    TWarAndWorld();
    TWarAndWorld(BookNum booknum, TypeSymbols typeSimbols, Language language, std::vector<uint32_t> seqNumbers);
    TWarAndWorld(WordCount wordCount, TypeSymbols typeSymbols, Language language, std::vector<uint32_t> seqNumbers);


    // Nujno li?
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
    * Геттеры
    */

    void Print(std::ostream& os) const override;

};

