#pragma once
#include "hashtable.h"
namespace lcz {
	template<class K,class V>
	class unordered_map {
		struct unordermapKofT {
			const K& operator()(const K& key) {
				return key;
			}
			const K& operator()(const std::pair<const K,V>& key)
			{
				return key.first;
			}
		};
	public:
		typedef typename hash_bucket::hashTable<K, std::pair<const K, V>, unordermapKofT>::iterator iterator;
		typedef typename hash_bucket::hashTable<K, std::pair<const K, V>, unordermapKofT>::const_iterator const_iterator;

	     
		
		std::pair<iterator, bool> insert(const std::pair<K, V>& kv)
		{
		 std::pair<typename hash_bucket::hashTable<K, std::pair<const K, V>, unordermapKofT>::iterator, bool> ret = _ht.insert(kv);
		 return std::pair<iterator, bool>(ret.first, ret.second);

		}
		iterator find(const K& key) {
			return _ht.find(key);
		}
		 bool erase(const K& key)
		 {
			 return _ht.erase(key);

		 }
		 V& operator[](const K& key) {
			 auto it = _ht.find(key);
			 if(it==_ht.end())
			 it = insert(std::make_pair(key, V())).first;			
			 return it->second;
		 }
		iterator begin()
		{
			return _ht.begin();
		}
		iterator end()
		{
			return _ht.end();
		}
		const_iterator begin()const
		{
			return _ht.begin();
		}
		const_iterator end()const
		{
			return _ht.end();
		}
		size_t size() const {
			size_t count = 0;
			for (auto it = begin(); it != end(); ++it) {
				++count;
			}
			return count;
		}
	private:
		hash_bucket::hashTable<K, std::pair<const K,V>, unordermapKofT> _ht;
	};
}