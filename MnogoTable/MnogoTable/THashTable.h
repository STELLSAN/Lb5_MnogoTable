#pragma once
#include "TTable.h"

class THashTable : public TTable
{
protected:
	virtual unsigned long long HashFunc(const TKey& key) {
		//хэш функция генерирует индекс для ключа!!!
		unsigned long long hv = 0;
		int keySize = key.size();
		for (int i = 0; i < keySize; i++) {
			hv = (hv << 3) + key[i];

		}
		return hv;
	};
	virtual unsigned long long WorstHashFunc(const TKey& key) {
		//хэш функция генерирует индекс для ключа!!!
		unsigned long long hv = key.size();
			hv = (hv >> 5);
		return hv;
	};
	virtual unsigned long long BestHashFunc(const TKey& key) {
		//хэш функция генерирует индекс для ключа!!!
		unsigned long long hash = 0;

		for (int i=0; i< key.size(); i++)
		{
			hash += (unsigned char)(key[i]);
			hash += (hash << 10);
			hash ^= (hash >> 6);
		}
		hash += (hash << 3);
		hash ^= (hash >> 11);
		hash += (hash << 15);

		return hash;
	};
public:
	THashTable() :TTable() {}

};

