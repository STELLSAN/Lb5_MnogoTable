
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

/*
* 
* 1)Загрузка всего источкика
* 2)Замерить эфеективность и время работы 3-х основных методов работы
* Для всех таблиц
* 2.1)Вставка замеряется во время обработка источника
* 2.2)Вывод эффективности для вставки всех слов
* 2.3)Find - нужно в таблице запустить find для каждого слова из таблицы, засеч время поиска эффективности
* 2.4)Delete - удаления всего
* Сортировки на всех таблицах
* Find/Delete происходитна всех уже отсортированных массивах
* 
* 3)Реализация хэшей 
*
* 
*/


int main() {
    setlocale(LC_ALL, "Russian");


    // 5.1 Print, Insert, Find, Delete
    TScanTable* test1 = new TScanTable(10);


    InputHandler ih = InputHandler(test1);
    //"..\\1voina-i-mir.txt"
    //"..\\WarAndPeace.txt"
    ih.Execution("..\\1voina-i-mir.txt.txt");


    TestScan ts = TestScan();
    std::cout << *test1;

    //TWarAndWorld* w1 = new TWarAndWorld(BookNumber::FIRST, TypeSymbol::CYRILLIC , TypeLetter::СAPITAL, 3);
    //TWarAndWorld* w2 = new TWarAndWorld(BookNumber::FIRST, TypeSymbol::CYRILLIC, TypeLetter::SMALL, 15);

    std::cout << ts.TestDelete(test1, "ТОМ") << " sec." << std::endl;
    //std::cout << ts.TestFind(test1, some) << " sec." << std::endl;
    //std::cout << ts.TestInsert(test1, "карыч", w1) << " sec." << std::endl;;
    std::cout << "--------------------------------------------------------------------------" << std::endl;
    std::cout << *test1;



    // 5.2 Sort's
    //std::cout << "--------------------------------------------------------------------------" << std::endl;
    //std::cout << "QuickSort " << ts.TestQuickSort(test1) << " seconds" << std::endl;      // O(n2) -  O(nlogn)
    //std::cout << "InsertSort " << ts.TestInsertSort(test1) << " seconds" << std::endl;  // O(n2) -  O(n)
    // std::cout << "MergeSort " << ts.TestMergeSort(test1) << " seconds" << std::endl;    // O(nlogn) ?? не помню
    //std::cout << "HeapSort " << ts.TestFreeChoice(test1) << " seconds" << std::endl;    // O(nlogn)  - ♫это♫ ♪база♪

    // 5.3 HashTable ListHashTable
    //TArrayHashTable* test3 = new TArrayHashTable(50, 1);
    //TListHashTable* test4 = new TListHashTable(1000);
    //InputHandler ih2 = InputHandler(test3);
    //  "..\\text-full.txt"
    // text-WarAndPeace.txt"
    //ih2.Execution("..\\1voina-i-mir.txt.txt");
    //std::cout << *test3;
    
        
    return 0;
}