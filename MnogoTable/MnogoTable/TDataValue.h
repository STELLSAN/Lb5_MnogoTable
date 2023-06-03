#pragma once
#include <iostream>


class TDataValue
{
protected:
	virtual void Print(std::ostream& os) const = 0;
public:

	TDataValue() = default;
	virtual TDataValue* GetCopy() = 0;
	friend std::ostream& operator<<(std::ostream& os, const TDataValue& dv) 
	{
		//? TDataValue == nullpointer
		dv.Print(os);
		return os;
	};
	

};

typedef TDataValue* PTDataValue;
