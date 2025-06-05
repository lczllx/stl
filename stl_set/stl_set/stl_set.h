#pragma once
#include "RBtree.h"
namespace lcz
{
	template<class K>
	class set {
		struct SetKeyOfT {
			const K& operator()(const K& key) {
				return key;
			}
		};
	public:
		//类模板，没有实例化，编译器认不出来这个是什么东西
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator iterator;
		typedef typename RBTree<K, K, SetKeyOfT>::const_iterator const_iterator;

		iterator begin()const
		{
			return _t.begin();
		}
		iterator end()const 
		{
			return _t.end();
		}
		/*const_iterator begin()const {
			return _t.begin();
		}
		const_iterator end()const {
			return _t.end();
		}*/

		pair<iterator, bool> insert(const K& kv) {
			//j接收
			pair<typename RBTree<K, K, SetKeyOfT>::iterator, bool> tmp = _t.Insert(kv);
			//构造
			return pair<iterator, bool>(tmp.first, tmp.second);
		}
	private:
		RBTree< K, K, SetKeyOfT> _t;
	};
}
