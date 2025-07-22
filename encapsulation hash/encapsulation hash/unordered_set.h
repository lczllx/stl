#pragma once
#include "hashtable.h"
namespace lcz {
	template<class K>
	class unordered_set {
		struct unordersetKofT {
			const K& operator()(const K& key)
			{
				return key;
			}
		};
		bool insert(const K& key)
		{
			return _ht.insert(key);
		}


	private:
		hash_bucket::hashTable<K, K, unordersetKofT> _ht;
	};
}