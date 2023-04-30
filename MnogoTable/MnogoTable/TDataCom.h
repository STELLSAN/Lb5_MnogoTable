#pragma once

#define DataOk 0
#define DataError -1

class TDataCom 
{
protected:
	int retCode;

public:

	TDataCom() : retCode(DataOk)
	{}

	int SetRetCode(int ret)
	{
		return retCode = ret;
	}

	int GetRetCode() 
	{
		int tmp = retCode;
		retCode = DataOk;
		return tmp;
	}

	virtual ~TDataCom() = 0{};

};