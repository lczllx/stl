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

	public:
		typedef typename hash_bucket::hashTable<K, K, unordersetKofT>::const_iterator iterator;
		typedef typename hash_bucket::hashTable<K, K, unordersetKofT>::const_iterator const_iterator;

		std::pair<iterator,bool> insert(const K& key)
		{
			std::pair<typename hash_bucket::hashTable<K, K, unordersetKofT>::iterator, bool> ret = _ht.insert(key);
			return std::pair<const_iterator,bool>(ret.first,ret.second);
		}
		bool erase(const K& key)
		{
			return _ht.erase(key);
		}
		iterator find(const K& key) {
			return _ht.find(key);
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
		hash_bucket::hashTable<K, K, unordersetKofT> _ht;
	};

	

}