
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "TDataValue.h"
#include "TTabRecord.h"
#include "TArrayTable.h"
#include "TScanTable.h"
#include "TMarks.h"
#include "TWarAndWorld.h"
#include "InputHandler.h"

#include "TSortTable.h"

#include "TArrayHashTable.h"
#include "TListHashTable.h"

#include"TScanTable.h"

#include "TestScan.h"

void Func(int* &ptr1) {
    std::cout << &ptr1 << std::endl;

}



int main() {
    setlocale(LC_ALL, "Russian");

    // 5.1 Print, Insert, Find, Delete
    //TListHashTable* test1 = new TListHashTable(100);
    TWarAndWorld* w1 = new TWarAndWorld(BookNumber::FIRST, TypeSymbol::LATINIC, TypeLetter::SMALL, 4);
    TWarAndWorld* w2 = new TWarAndWorld(BookNumber::FIRST, TypeSymbol::LATINIC, TypeLetter::SMALL, 5);
    TScanTable* test2 = new TScanTable(10000000);

    InputHandler p = InputHandler(test2);
    //  "..\\text-full.txt"
    // text-WarAndPeace.txt"
    p.Execution("..\\text-WarAndPeace.txt");  


    TestScan ts = TestScan();

    std::cout << ts.TestInsert(test2, "КАРКАРЫЧ", input1) << " sec. " << std::endl;
    //std::cout <<  ts.TestFind(test2, "КАРКАРЫЧ") << " sec. " << std::endl;
    //std::cout <<  ts.TestDelete(test2, "КАРКАРЫЧ") << " sec. " << std::endl;
    std::cout << ts.TestFind(test2, "огнями") << " sec." << std::endl;
    std::cout << ts.TestDelete(test2, "позван") << " sec." << std::endl;


    // 5.2 Sort's

    //std::cout << "QuickSort" << ts.TestQuickSort(test1) << " seconds" << std::endl;      // O(n2) -  O(nlogn)
    //std::cout << "InsertSort" << ts.TestInsertSort(test1) << " seconds" << std::endl;  // O(n2) -  O(n)
    //std::cout << "MergeSort" << ts.TestMergeSort(test1) << " seconds" << std::endl;    // O(nlogn) ?? не помню
    //std::cout << "HeapSort" << ts.TestFreeChoice(test1) << " seconds" << std::endl;    // O(nlogn)  - ♫это♫ ♪база♪

    // 5.3 HashTable
    //TArrayHashTable test3();
    //InputHandler p2 = InputHandler(test3);
    //  "..\\text-full.txt"
    // text-WarAndPeace.txt"
    p.Execution("..\\text-WarAndPeace.txt");
    
    
    
    return 0;
}