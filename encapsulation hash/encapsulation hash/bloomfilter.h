#pragma once
#include "bitmap.h"



struct APhash {
	size_t operator()(const std::string& str)
	{
		register size_t hash = 0;
		for (size_t i = 0; i < str.size(); i++)
		{
			size_t ch = str[i];

			if ((i & 1) == 0) {
				hash ^= ((hash << 7) ^ ch ^ (hash >> 3));
			}
			else {
				hash ^= (~((hash << 11) ^ ch ^ (hash >> 5)));
			}
		}
		return hash;
	}
};
struct DJBhash {
	size_t operator()(const std::string& str)
	{
		size_t hash = 5381;
		for (size_t i = 0; i < str.size(); i++)
		{
			size_t ch = str[i];

			hash += (hash << 5) + ch;
		}
		return hash;
	}
};

template<size_t N,class K=std::string,class hash1= DJBhash,class hash2=APhash>
class bloomfilter {
public:
	bool set(const K& key)
	{
		size_t h1 = hash1()(key) % N;
		_bm.set(h1);
		size_t h2 = hash2()(key) % N;
		_bm.set(h2);
	}
	bool test(const K& key)
	{
		size_t h1 = hash1()(key) % N;
		if (_bm.test(h1) == false)return false;
		size_t h2 = hash2()(key) % N;
		if (_bm.test(h2) == false)return false;
	
		return true;
	}


private:
	lcz::bitmap<N>_bm;
};