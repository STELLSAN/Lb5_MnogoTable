#include "Marks.h"
#include "TTabRecord.h"

int main() {
	Marks mmm = Marks(1, 5, 3); // Mavrodi jiv! :D
	std::cout << mmm<< std::endl;

	Marks* mmm2012 = (Marks*)mmm.GetCopy();
	std::cout << *mmm2012 << std::endl;

	//TTabRecord* tabs = new TTabRecord[10];




}