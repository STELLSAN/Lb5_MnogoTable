#include "TWarAndWorld.h"

TWarAndWorld::TWarAndWorld(TypeSymbols typeSym, Letter letter, short int lenght) {
    _wordCount = { 0, 0, 0, 0, 0 };
    _typeSymbols = TypeSymbols::DEFAULT;
    _letter = Letter::DEFAULT;
    _lenght = lenght;
}

TWarAndWorld::TWarAndWorld(BookNum booknum, TypeSymbols typeSimbols, Letter letter, short int lenght) {
    _wordCount = { 0, 0, 0, 0, 0 };
    _typeSymbols = typeSimbols;
    _letter = letter;
    _lenght = lenght;
}

TWarAndWorld::TWarAndWorld(WordCount wordCount, TypeSymbols typeSymbols, Letter letter, short int lenght){
    _wordCount = wordCount;
    _typeSymbols = typeSymbols;
    _letter = letter;
    _lenght = lenght;
}


void TWarAndWorld::Print(std::ostream& os) const {
    os << _wordCount << '\t';

    switch (_typeSymbols) {
    case TypeSymbols::CYRILIC:
        os << "CYRILIC" << '\t';
        break;
    case TypeSymbols::LATINIC:
        os << "LATINIC" << '\t';
        break;
    default:
        os << "Default" << '\t';
        break;
    }

    switch (_letter) {
    case Letter::DEFAULT:
        os << "Small" << '\t';
        break;
    case Letter::SMALL:
        os << "SMALL" << '\t';
        break;
    case Letter::ÑAPITAL:
        os << "ÑAPITAL" << '\t';
        break;
    default:
        os << "Default" << '\t';
        break;
    }

    os << "[" << _lenght << "]";
    //    os << "[";
    //    for (auto sequentialNumber : _sequentialNumbers) {
    //        os << sequentialNumber << ", ";
    //    }
    //    os << "]";
}

