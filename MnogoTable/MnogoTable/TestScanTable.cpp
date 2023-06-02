#include <string>
#include <stdio.h> 
#include <time.h> 
#include "TScanTable.h" 
#include "TWarAndWorld.h" 


double TestInsert(TScanTable* a, std::string st, TWarAndWorld* waw) {
	
	clock_t start = clock();
	a->InsertRecord(st, waw);
	clock_t end= clock();
	return  (double)(end - start) / CLOCKS_PER_SEC;

}

double TestFind(TScanTable* a, std::string st) {

	clock_t start = clock();
	a->FindRecord(st);
	clock_t end = clock();
	return  (double)(end - start) / CLOCKS_PER_SEC;

}

double TestDelete(TScanTable* a, std::string st) {

	clock_t start = clock();
	a->DeleteRecord(st);
	clock_t end = clock();
	return  (double)(end - start) / CLOCKS_PER_SEC;

}