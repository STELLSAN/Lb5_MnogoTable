
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "TDataValue.h"
#include "TTabRecord.h"
#include "TArrayTable.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "TMarks.h"
#include "TWarAndWorld.h"
#include "InputHandler.h"
#include "TArrayHashTable.h"
#include "TListHashTable.h"

#include "TestScan.h"

void Func(int* &ptr1) {
	std::cout << &ptr1 << std::endl;

}



int main() {
	setlocale(LC_ALL, "Russian");

	TListHashTable* a4 =  new TListHashTable(500000); // Около 461 к слов всего - ключ-счётчик-значение > 100к
	//TArrayTable a4 = TArrayTable();
	///*TWarAndWorld* a1 = new TWarAndWorld(Volume::FIRST, TypeText::LATINIC, FirstLetter::SMALL, 4);
	TWarAndWorld* a2 = new TWarAndWorld(BookNumber::FIRST, TypeSymbol::LATINIC, TypeLetter::SMALL, 5);
	//a.InsertRecord("llll", a1);
	//a.InsertRecord("оооз", a2);*/
	Packer p = Packer(a4);
	p.Execution("..\\text-full.txt");
	//std::cout << *a4;
	//
	//TWarAndWorld* w1 = new TWarAndWorld(Volume::FIRST, TypeText::LATINIC, FirstLetter::SMALL, 4);

	//TestScan ts = TestScan();
	//std::cout.precision(2);
	//std::cout << std::fixed << std::setprecision(5)<< ts.TestInsert(a4, "lllk",a2) << " seconds" << std::endl;
	//std::cout << ts.TestFind(a4, "огнями") << " seconds" << std::endl;
	//std::cout << ts.TestDelete(a4, "позван") << " seconds" << std::endl;

	//std::cout.precision(2);
	//std::cout << std::fixed << std::setprecision(5) << ts.TestWordSearch(a4,"..\\text-full.txt" ) << " seconds" << std::endl;
	
	//std::cout << *a4;
	//std::cout << "QuickSort" << ts.TestQuickSort(a1) << " seconds" << std::endl;
	//std::cout << "InsertSort" << ts.TestInsertSort(a1) << " seconds" << std::endl;
	//std::cout << "MergeSort" << ts.TestMergeSort(a1) << " seconds" << std::endl;
	//std::cout << "BubbleSort" << ts.TestBubbleSort(a1) << " seconds" << std::endl;
	//std::cout << "HeapSort" << ts.TestFreeChoice(a1) << " seconds" << std::endl;
	/*TSortTable* a2 = new TSortTable(*a1);
	a2->SetSortMethod(QuickSort);
	a2->SortData();
	std::cout << *a2;*/
	
	
	return 0;
}