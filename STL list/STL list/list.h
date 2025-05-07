#pragma once
#include<iostream>
#include<list>
#include<assert.h>
#include<algorithm>
using namespace std;
#include "Reverseiterator.h"
namespace lcz 
{
	template<class T>
	struct list_node 
	{
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;

		list_node(const T& val = T()) 
			:_next(nullptr)
			, _prev(nullptr)
			,_val(val)
		{}
	
	};

	/*typedef _list_iterator<T, T&, T*> iterator;
	typedef _list_iterator<T, const T&, const T*> const_iterator;*/
	template<class T,class Ref,class Ptr>
	struct _list_iterator {
		typedef list_node<T> Node;
		typedef _list_iterator<T,Ref,Ptr> self;
		Node* _node;

		_list_iterator(Node* node)
			:_node(node)
		{ }

		//const T& operator*() 返回的类型不能修改
		// T& operator*()const 修饰this指针指向的对象
		Ref operator*() 
		{
			return _node->_val;
		}
		Ptr operator->() {
			return &_node->_val;

		}

		self& operator++() {
			_node = _node->_next;
			return *this;
		}
		self operator++(int) {
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--() {
			_node = _node->_prev;
			return *this;
		}
		self operator--(int) {
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		bool operator!=(const self& it)const 
		{
			return _node != it._node;
		}
		bool operator>(const self& it) {
			return _node > it._node;
		}
		bool operator>=(const self& it) {
			return _node >= it._node;
		}
		bool operator<(const self& it) {
			return _node < it._node;
		}
		bool operator<=(const self& it) {
			return _node <= it._node;
		}

	};

	//冗余，增加一个模板参数,通过类型控制
	//template<class T>
	//struct _list_const_iterator {
	//	typedef list_node<T> Node;
	//	Node* _node;

	//	_list_const_iterator(Node* node)
	//		:_node(node)
	//	{
	//	}

	//	//const T& operator*() 返回的类型不能修改
	//	// T& operator*()const 修饰this指针指向的对象
	//	const T& operator*()
	//	{
	//		return _node->_val;
	//	}

	//	_list_const_iterator<T>& operator++() {
	//		_node = _node->_next;
	//		return *this;
	//	}
	//	_list_const_iterator<T>& operator++(int) {
	//		_list_const_iterator<T> tmp(*this);
	//		_node = _node->_next;
	//		return tmp;
	//	}

	//	bool operator!=(const _list_const_iterator<T>& it) {
	//		return _node != it._node;
	//	}
	//	bool operator==(const _list_const_iterator<T>& it) {
	//		return _node == it._node;
	//	}
	//	bool operator>(const _list_const_iterator<T>& it) {
	//		return _node > it._node;
	//	}
	//	bool operator>=(const _list_const_iterator<T>& it) {
	//		return _node >= it._node;
	//	}
	//	bool operator<(const _list_const_iterator<T>& it) {
	//		return _node < it._node;
	//	}
	//	bool operator<=(const _list_const_iterator<T>& it) {
	//		return _node <= it._node;
	//	}

	//};


	template<class T>
    class list 
	{
		typedef list_node<T> Node;//私有，对内用的，不希望别人访问

	public:
		typedef _list_iterator<T, T&,T*> iterator;
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		typedef Reverseiterator<iterator, T&, T*> reverse_iterator;
		//typedef Reverseiterator<const T, const T&, const T*> const_reverse_iterator;

		//typedef const _list_iterator<T> const_iterator;/这样设计使得迭代器本身不能被修改
		//const T* ptr1;指向的内容不能被修改
		// T* const ptr2;指向的指针不能被修改
		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}
		/*reverse_iterator rbegin() const
		{
			return iterator(end());
		}*/
		reverse_iterator rend() {
			return reverse_iterator(begin());
		}
		/*reverse_iterator end()const
		{
			return iterator(begin());
		}*/
		iterator begin() 
		{
			return iterator(_head->_next);
			//return _head->_next;
		}
		const_iterator begin()const
		{
			return const_iterator(_head->_next);
			//return _head->_next;
		}

		iterator end()
		{
			//return _head;
			return _head;
		}
		const_iterator end()const 
		{
			//return _head;
			return const_iterator(_head);
		}

		void empty_init() 
		{
			_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;

			_size = 0;
		}

		list() 
		{
			empty_init();
		}

		list(const list<T>& lt) 
		{
			/*_head = new Node;
			_head->_prev = _head;
			_head->_next = _head;
            _size = 0;*/
			empty_init();

			for (auto& e : lt) {
				push_back(e);
			}
		}
		~list() {
			clear();

			delete _head;
			_head = nullptr;
		}
		void swap(list<T>& lt) {
			std::swap(_head, lt._head);
			std::swap(_size, lt.size);
		}
		list<T>& operator=(list<T>& lt) {
			swap(lt);
			return *this;
		}
		void clear() {
			iterator it = begin();
			while (it != end()) {
				it = erase(it);
				
			}
			_size = 0;
		}
		/*void push_back(const T& x) {
			Node* tail = _head->_prev;
			Node* newnode = new Node(x);

			newnode->_next = _head;
			newnode->_prev = tail;
			tail->_next = newnode;
			_head->_prev = newnode;
		}*/
		void push_back(const T& x) 
		{
			insert(end(), x);
		}
		void push_front(const T& x) 
		{
			insert(begin(), x);

		}

		void pop_back() 
		{
			erase(--end());
		}
		void pop_front() 
		{
			erase(begin());

		}

		//前面插入
		iterator insert(iterator pos,const T&x) {

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* newnode = new Node(x);

			newnode->_next = cur;
			newnode->_prev = prev;
			prev->_next = newnode;
			cur->_prev = newnode;
			//cout << "jjj" << endl;
			++_size;
			return newnode;

		}
		iterator erase(iterator pos) {
			assert(pos != end());

			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* next = cur->_next;

			prev->_next = next;
			next->_prev = prev;
			//cout << "jjj" << endl;

			delete cur;
			_size--;
			return next;
		}

		size_t size() {
			/*size_t sz = 0;
			iterator it = begin();
			while (it != end())it++,sz++;*/

			return _size;
		}

 	private:
		Node* _head;
		size_t _size;
	};



	

	struct A {
		A(int a1 = 0, int a2 = 0)
			:_a1(a1)
			,_a2(a2)
		{
		}
		int _a1, _a2;
	};

	
	void test_list2() {
		list<A>lt;
		lt.push_back(A(1,1));
		lt.push_back(A(2, 2));
		lt.push_back(A(3, 2));
		lt.push_back(A(4,2));
		

		list<A>::iterator it = lt.begin();
		while (it != lt.end()) {
			cout << (*it)._a1 << " ";
			if ((*it)._a2 >= 1)cout << 3 << " ";
			++it;
		}
		cout << endl;
	}

	void test_list1() {
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(6);
		lt.push_back(8);

		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;

		lt.pop_back();
		lt.push_front(88);
		lt.push_front(99);
		lt.pop_front();

		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;
		lt.clear();
		lt.push_back(6);
		lt.push_back(8);

		for (auto e : lt) {
			cout << e << " ";
		}
		cout << endl;
		cout << lt.size() << endl;


	}
	void test_list3() {
		list<int>lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(6);

		list<int> lt2(lt);
		for (auto e : lt2) {
			cout << e << " ";
		}
		cout << endl;
		list<int>::reverse_iterator lt3=lt.rbegin();
		while (lt3 != lt.rend())
		{
			cout << *lt3 << " ";
			++lt3;
		}
		cout << endl;

	}
}