#include "Marks.h"

#include<iostream>
#include"TWarAndWorld.h"
#include"InputHandler.h"
#include"TArrayTable.h"
#include "TTabRecord.h"
#include"TListHashTable.h"
#include"TestScan.h"

int main() {
	
	TListHashTable* test = new TListHashTable(100);

	InputHandler p = InputHandler(test);
	p.ProcessInput("..\\voina-i-mir.txt");
	
	TestScan ts = TestScan();


	return 0;

}