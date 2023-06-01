#pragma once

#include<iostream>

enum BookNum {
    DEFAULT,
    FIRST,
    SECOND,
    THIRD,
    FORTH,
    EPILOGUE
};


struct WordCount {
    int bookOne = 0;
    int bookTwo = 0;
    int bookThree = 0;
    int bookFour = 0;
    int epilogue = 0;

    int Summ() const {

        return bookOne + bookTwo + bookThree + bookFour + epilogue;
    }
    friend std::ostream& operator<<(std::ostream& ostream, const WordCount& wordCount) {
        ostream << wordCount.bookOne << '\t' << wordCount.bookTwo << '\t' << wordCount.bookThree << '\t' << wordCount.bookFour << '\t' << wordCount.epilogue;
        return ostream;
    }
};


class TWarAndWorld
{
};

