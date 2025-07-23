#pragma once
#include<iostream>
#include<vector>
#include<string>

namespace ares {
	enum STATE {
		EXIST,
		EMPTY,
		DELETE
	};
	template<class K, class V>
	struct hashdata {
		std::pair< K, V> _kv;
		STATE _state = EMPTY;
		/*hashdata(const std::pair<K, V>& kv)
			:_kv(kv),_state(EMPTY)
		{ }*/
		/*hashdata()
			:_kv(kv), _state(EMPTY)
		{
		}*/
	};
	template<class K>
	struct defaulthashfunc {
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<>//使用特化解决
	struct defaulthashfunc <std::string> {
		//size_t operator()(const std::string& key)
		//{
		//	return key[0];//冲突有点大
		//}
		size_t operator()(const std::string& key)
		{
			//BKDR
			size_t num = 0;
			for (auto e : key) {
				num = num * 131 + e;
			}
			return num;
		}
	};
	template<class K, class V, class hashfunc = defaulthashfunc<K>>
	class hashtable {
	private:
		std::vector<hashdata<K, V>> _table;
		size_t _n = 0;
	public:
		hashtable()
		{
			_table.resize(10);
		}
		bool insert(const std::pair<K, V>& kv)
		{
			hashfunc hs;
			if (_n * 10 / _table.size() >= 7) {
				size_t newsize = _table.size() * 2;
				hashtable<K, V, hashfunc> newtable;
				newtable._table.resize(newsize);
				for (size_t i = 0; i < _table.size(); i++)
				{
					if (_table[i]._state == EXIST) {
						newtable.insert(_table[i]._kv);
					}
				}
				_table.swap(newtable._table);
			}
			//
			size_t pos = hs(kv.first) % _table.size();
			while (_table[pos]._state == EXIST) {
				++pos;
				pos %= _table.size();
			}
			_table[pos]._kv = kv;
			_table[pos]._state = EXIST;
			++_n;

			return true;
		}
		//加const防止修改
		hashdata<const K, V>* find(const K& key) {
			//key可能不是整形
			hashfunc hs;
			size_t pos = hs(key) % _table.size();
			size_t start = pos;
			while (_table[pos]._state != EMPTY) {
				if (_table[pos]._state == EXIST && _table[pos]._kv.first == key)
				{
					return (hashdata<const K, V>*) & _table[pos];
				}
				++pos;
				pos %= _table.size();
				if (pos == start)break;
			}
			return nullptr;
		}

		bool erase(const K& key) {
			hashdata<const K, V>* ret = find(key);
			if (ret)
			{
				ret->_state = DELETE;
				--_n;
				return true;
			}
			return false;
		}
	};
}
///////////////////////////////////////////////////////////////////////////
// 
//哈希桶
namespace hash_bucket {
	template<class K>
	struct defaulthashfunc {
		size_t operator()(const K& key)
		{
			return (size_t)key;
		}
	};
	template<>//使用特化解决
	struct defaulthashfunc <std::string> {
		//size_t operator()(const std::string& key)
		//{
		//	return key[0];//冲突有点大
		//}
		size_t operator()(const std::string& key)
		{
			//BKDR
			size_t num = 0;
			for (auto e : key) {
				num = num * 131 + e;
			}
			return num;
		}
	};
	template<>
	struct defaulthashfunc<const char*> {
		size_t operator()(const char* key) {
			size_t hash = 0;
			while (*key) {
				hash = hash * 131 + *key++;
			}
			return hash;
		}
	};
	template<class T>
	struct hashnode {
		T _data;
		hashnode<T>* _next;
		hashnode(const T& data)
			: _data(data), _next(nullptr) {
		}
	};
	//前置声明
	template<class K, class T, class KeyofT, class hashfunc>
	class hashTable;
	template<class K, class T,class Ptr,class Ref, class KeyofT, class hashfunc = defaulthashfunc<K>>
	struct hashiterator {
		typedef hashnode<T> Node;
		//取类模板里面的内嵌类型，编译器不能区分时才加typename
		typedef hashiterator<K, T, Ptr, Ref, KeyofT, hashfunc> Self;
		typedef hashiterator<K, T, T*,T&, KeyofT, hashfunc> iterator;
		//typedef hashiterator< T,T&,T*> iterator;
		const hashTable<K, T, KeyofT, hashfunc>* _ht;
		Node* _node;
		KeyofT kot;
		hashfunc hf;
		hashiterator(const iterator&it)
			:_node(it._node)
			,_ht(it._ht)
		{ }
		hashiterator(Node* node, hashTable<K, T, KeyofT, hashfunc>* ht)
			:_node(node),_ht(ht)
		{ }
		hashiterator(Node* node,const hashTable<K, T, KeyofT, hashfunc>* ht)
			:_node(node), _ht(ht)
		{
		}
		Ref operator*()
		{
			return (_node->_data);
		}
		Ptr operator->()
		{
			return &(_node->_data);
		}
		Self& operator++()
		{
			if (_node->_next)
			{
				//当前桶
				_node = _node->_next;
			}
			else {
				//_ht类外面不能访问，要声明友元
				size_t pos = hf(kot(_node->_data)) % _ht->_table.size();
				//从下一个位置查找下一个不为空的桶
				++pos;
				while (pos < _ht->_table.size())
				{
					if (_ht->_table[pos]) {
						_node = _ht->_table[pos];
						return *this;
					}
					else {
						++pos;
					}
				}
				_node = nullptr;
				return *this;
			}
			return *this;
		}

		bool operator!=(const Self& s)
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)
		{
			return _node == s._node;
		}
	};

	template<class K, class T,class KeyofT,class hashfunc= defaulthashfunc<K>>
	class hashTable {
		typedef hashnode<T> Node;
		//迭代器是哈希表的友元
		template<class K, class T,class Ptr,class Ref, class KeyofT, class hashfunc>
		friend struct hashiterator;
	public:
		typedef hashiterator<K, T,T*,T&, KeyofT, hashfunc> iterator;
		typedef hashiterator<K, T,const T*,const T&, KeyofT, hashfunc> const_iterator;
		iterator begin()
		{
			for (size_t i = 0; i < _table.size(); i++) {
				Node* cur = _table[i];
				if (cur) {
					return iterator(cur, this);
				}
			}
			return iterator(nullptr, this);
		}
		iterator end()
		{
			return iterator(nullptr, this);
		}
		const_iterator begin()const
		{
			for (size_t i = 0; i < _table.size(); i++) {
				Node* cur = _table[i];
				if (cur) {
					return const_iterator(cur, this);
				}
			}
			return const_iterator(nullptr, this);
		}
		const_iterator end()const
		{
			return const_iterator(nullptr, this);
		}
		hashTable()
		{
			_table.resize(10, nullptr);
		}
		~hashTable()
		{
			for (size_t i = 0; i < _table.size(); i++) {
				Node* cur = _table[i];
				while (cur)
				{
					Node* next = cur->_next;
					delete cur;
					cur = next;
				}
				_table[i] = nullptr;
			}
			_n = 0;
		}
	     std::pair<iterator, bool> insert(const T& data)
		{
			KeyofT kot;
			hashfunc hf;
			iterator it= find(kot(data));
				if (it != end())
				return std::make_pair(it,false);
			//负载因子控制在1再扩容
			if (_n == _table.size())
			{
				size_t newsize = _table.size() * 2;
				std::vector<Node*> newtable;
				newtable.resize(newsize, nullptr);
				for (size_t i = 0; i < _table.size(); i++) {
					Node* cur = _table[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t pos = hf(kot(cur->_data)) % newsize;
						//头插
	
						cur->_next =newtable[pos];
						newtable[pos] = cur;
						cur = next;
					}
					_table[i] = nullptr;
				}
				_table.swap(newtable);
			}

			size_t pos = hf(kot(data)) % _table.size();
			//头插
			Node* newnode = new Node(data);
			newnode->_next = _table[pos];
			_table[pos] = newnode;
			++_n;
			return make_pair(iterator(newnode,this),true);
		}

		iterator find(const K& key) {
			if (_table.size() == 0) {
				return end();
			}
			hashfunc hf;
			KeyofT kot;
			size_t pos = hf(key) % _table.size();
			Node* cur = _table[pos];
			while (cur) {
				if (kot(cur->_data) == key) {
					return iterator(cur, this);
				}
				cur = cur->_next;
			}
			return end();
		}
		bool erase(const K& key) {
			//if (!find(key))return false;
			if (_table.size() == 0) {
				return false;
			}
			hashfunc hf;
			KeyofT kot;
			size_t pos = hf(kot(key)) % _table.size();
			Node* cur = _table[pos];
			Node* prev = nullptr;
			while (cur) {
				if (kot(cur->_data) == key) {

					if (prev == nullptr) {
						_table[pos] = cur->_next;
					}
					else {
						prev->_next = cur->_next;
					}
					delete cur;
					--_n;

					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			
			return false;
		}

	private:
		std::vector<Node*> _table;//指针数组
		size_t _n;//记录有效存储shuliang

	};
}