#pragma once
#include "RBT.h"
namespace lcz 
{
	template<class K,class V>
	class map 
	{
		struct mapkeyofT 
		{
			const K& operator()(const std::pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		/*map() :_t(), _size(0) {}*/

		typedef typename RBT< K, std::pair<const K, V>, mapkeyofT>::iterator iterator;
		typedef typename RBT< K, std::pair<const K,V>, mapkeyofT>::const_iterator const_iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}
		const_iterator begin()const
		{
			return _t.begin();
		}
		const_iterator end()const
		{
			return _t.end();
		}
		V& operator[](const K& key)
		{
			std::pair<iterator,bool> tmp = _t.insert(std::make_pair(key,V()));

			return tmp.first->second;
		}
		std::pair<iterator,bool> insert(const std::pair<K,V>& kv)
		{
			return _t.insert(kv);
		}
		// 查找
		iterator find(const std::pair<K, V>& kv) const
		{
			auto node = _t.find(kv.first);
			return iterator(node);
		}

		//// 判空
		//bool empty() const
		//{
		//	return _size == 0;
		//}

		//// 大小
		//size_t size() const
		//{
		//	return _size;
		//}

		//// 清空
		//void clear()
		//{
		//	_t.clear();
		//	_size = 0;
		//}

		// 中序遍历输出
		void inorder() const
		{
			_t.inorder();
		}

	private:
		RBT<K, std::pair<const K, V>,mapkeyofT>_t;
		/*size_t _size;*/

	};
}