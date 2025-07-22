#pragma once
#include "hashtable.h"
namespace lcz {
	template<class K,class V>
	class unordered_map {
		struct unordermapKofT {
			const K& operator()(const std::pair<K,V>& key)
			{
				return key.first;
			}
		};
		bool insert(const std::pair<K, V>& kv)
		{
			return _ht.insert(kv);

		}


	private:
		hash_bucket::hashTable<K, std::pair<K,V>, unordermapKofT> _ht;
	};
}