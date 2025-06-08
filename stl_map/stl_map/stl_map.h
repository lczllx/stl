#pragma once
//#include "D:\cpp¡∑œ∞\STL\red black tree\red black tree\RBtree.h"



namespace lcz
{

	template<class K, class V>
	class map {

		struct MapKeyOfT {
			const K& operator()(const pair<K, V>& kv) {
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator iterator;
		typedef typename RBTree<K, pair<const K, V>, MapKeyOfT>::const_iterator const_iterator;

		pair<iterator, bool> insert(const pair<K, V>& kv) {
			pair<typename RBTree<K, pair<const K, V>, MapKeyOfT>::iterator, bool> tmp = _t.Insert(kv);
			return pair<iterator, bool>(tmp.first, tmp.second);
		}
		iterator begin() {
			return _t.begin();
		}
		iterator end() {
			return _t.end();
		}
		/*V& operator[](const K& key) {

		}*/
	private:
		RBTree<K, pair<const K, V>, MapKeyOfT> _t;
	};
}