#pragma once
#include "RBT.h"
namespace lcz 
{
	template<class K>
	class set 
	{
		struct setkeyofT 
		{
			const K& operator()(const K& key)
			{
				return key;
			}
		};
	public:
		set():_t(),_size(0){}
		
		typedef typename RBT< K, K, setkeyofT>::const_iterator iterator;
		typedef typename RBT< K, K, setkeyofT>::const_iterator const_iterator;
		const_iterator begin()const
		{
			return _t.begin();
		}
		const_iterator end()const
		{
			return _t.end();
		}

		std::pair<const iterator, bool> insert(const K& key)
		{
			std::pair<typename RBT< K, K, setkeyofT>::iterator, bool>ret = _t.insert(key);
			return std::pair<iterator,bool>(ret.first,ret.second);
		}
		// 查找
		iterator find(const K& key) const
		{
			auto node = _t.find(key);
			return iterator(node);
		}

		// 判空
		bool empty() const
		{
			return _size == 0;
		}

		// 大小
		size_t size() const
		{
			return _size;
		}

		// 清空
		void clear()
		{
			_t.clear();
			_size = 0;
		}

		// 中序遍历输出
		void inorder() const
		{
			_t.inorder();
		}

	private:
		RBT<K, K, setkeyofT> _t;
		size_t _size;
	};
}