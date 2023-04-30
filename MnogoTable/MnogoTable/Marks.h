#pragma once
#include"TDataValue.h"
#include<iostream>

class Marks : public TDataValue{
private:
	int* _marks;
	void Print(std::ostream& os) override{
		os << "Mark1 " << _marks[0] << std::endl;
		os << "Mark2 " << _marks[1] << std::endl;
		os << "Mark3 " << _marks[2] << std::endl;
	};

public:
	Marks(int mark1, int mark2, int mark3):TDataValue(){// как срабатывает конструктор и деструктор??
		_marks = new int[3];
		_marks[0] = mark1;
		_marks[1] = mark2;
		_marks[2] = mark3;
		
	}

	TDataValue* GetCopy() override {
		return new Marks(_marks[0], _marks[1], _marks[2]);
	};

	~Marks() {
		delete[] _marks;
	}
};

