
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <time.h> 
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
    1)TScanTable
        1.1) Insert, Delete, Search
    2)TSortTable
        2.2) Insert, Delete(Search + сортировка после), Search(бинарный поиск)
    3)TListTable
        3.3)Insert, Delete, Search;
*/
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
* 
*
* 
*/


int main() {
    setlocale(LC_ALL, "Russian");
    /*
    std::cout << " ----------------------START TScanTable TESTING ---------------------- " << std::endl;
    // TScanTable
    
    TScanTable* test1 = new TScanTable(10000);
    InputHandler ih = InputHandler(test1);
    clock_t start1 = clock();
    ih.Execution("..\\1voina - i - mir.txt.txt");
    clock_t end1 = clock();
    double seconds1 = (double)(end1 - start1) / CLOCKS_PER_SEC;

    std::cout << "Insert operation: " << seconds1 << " sec. " << std::endl;

    TestScan testScanT = TestScan();
    //std::cout << "Search operation: " << testScanT.TestFind(test1, "кабинет") << std::endl;
    std::cout << "Search all operation: " << testScanT.TestWordSearch(test1, "..\\1voina - i - mir.txt.txt") << std::endl;
    //std::cout << "Efficiency: " << test1->GetEfficiency() << std::endl;
    //std::cout << "Delete operation: " << testScanT.TestDelete(test1, "кабинет") << std::endl;
    */
    
    // TSortTable
    
    std::cout << " ----------------------START TSortTable TESTING ---------------------- " << std::endl;
    TestScan testScanT = TestScan();
    TSortTable* test2 = new TSortTable(10000);
    InputHandler ih2 = InputHandler(test2);
    clock_t start2 = clock();
    ih2.Execution("..\\1voina-i-mir.txt.txt");
    clock_t end2 = clock();
    double seconds2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    std::cout << "Insert operation: " << seconds2 << "sec." << std::endl;
    std::cout << "Search all operation: " << testScanT.TestWordSearch(test2, "..\\1voina-i-mir.txt.txt") << std::endl;
    std::cout << "Efficiency: " << test2->GetEfficiency() << std::endl;

    std::cout << " ---------------------------------------------------------- " << std::endl;

    std::cout << "Buble Sort:" << testScanT.TestBubbleSort(test2) << "sec." << std::endl;
    std::cout << "Insert Sort:" << testScanT.TestInsertSort(test2) << "sec." << std::endl;
    std::cout << "Merge Sort:" << testScanT.TestMergeSort(test2) << "sec." << std::endl;
    std::cout << "Heap Sort:" << testScanT.TestFreeChoice(test2) << "sec." << std::endl;
    //std::cout << "Quick Sort:" << testScanT.TestQuickSort(test2) << "sec." << std::endl;

    std::cout << " ----------------------START TArrayHashTable TESTING ---------------------- " << std::endl;
    TArrayHashTable* test4 = new TArrayHashTable(100000);
    InputHandler ih4 = InputHandler(test4);
    clock_t start4 = clock();
    ih4.Execution("..\\1voina-i-mir.txt.txt");
    clock_t end4 = clock();
    double seconds4 = (double)(end4 - start4) / CLOCKS_PER_SEC;
    std::cout << "Insert operation: " << seconds4 << "sec." << std::endl;
    std::cout << "Search operation: " << testScanT.TestWordSearch(test4, "..\\1voina-i-mir.txt.txt");
    std::cout << "Efficiency: " << test4->GetEfficiency() << std::endl;
    //TListHashTable

    std::cout << " ----------------------START TListHashTable TESTING ---------------------- " << std::endl;
    TListHashTable* test3 = new TListHashTable(100000);
    InputHandler ih3 = InputHandler(test3);
    clock_t start3 = clock();
    ih3.Execution("..\\1voina-i-mir.txt.txt");
    clock_t end3 = clock();
    double seconds3 = (double)(end3 - start3) / CLOCKS_PER_SEC;
    std::cout << "Insert operation: " << seconds3 << "sec." << std::endl;

    std::cout << "Search operation: " << testScanT.TestWordSearch(test3, "..\\1voina-i-mir.txt.txt");
    std::cout << "Efficiency: " << test3->GetEfficiency() << std::endl;
    


   

    
    
    //TListHashTable

        
    return 0;
}