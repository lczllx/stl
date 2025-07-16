#pragma once
#include<assert.h>
#include<iostream>
namespace lcz {
	template<class T>
	struct list_node {
		list_node<T>* _next;
		list_node<T>* _prev;
		T _val;
		list_node(const T& val=T())
			:_next(nullptr)
			,_prev(nullptr)
			,_val(val)
		{ }
	};

	template<class T,class Ref,class Ptr>
	struct list_iterator{
		typedef list_node<T> Node;
		typedef list_iterator<T,Ref,Ptr>self;
		Node* _node;

		list_iterator(Node* node):_node(node){}
		Ref operator*() 
		{
			return _node->_val;
		}
		Ptr operator->() 
		{
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
			_node=_node->_prev;

			return tmp;
		}

		bool operator==(const self& lt) {
			return _node == lt._node;
		}
		bool operator!=(const self& lt) {
			return _node != lt._node;
		}
		bool operator<(const self& lt) {
			return _node < lt._node;
		}
		bool operator>(const self& lt) {
			return _node > lt._node;
		}
		bool operator<=(const self& lt) {
			return _node <= lt._node;
		}
		bool operator>=(const self& lt) {
			return _node >= lt._node;
		}
	};


	template<class T>
	class list {
		typedef list_node<T> Node;
		
	public:
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
		void swap(list<T>&lt) {
			std::swap(_head, lt._head);
			std::swap(_sz, lt._sz);
		}
		void clear() {
			iterator it=begin();
			while (it != end())it=erase(it);
			_sz = 0;
		}
		void empty_init() {
			_head = new Node;
			_head->_next = _head;
			_head->_prev = _head;
			_sz = 0;
		}
		list(){ empty_init(); }
		list(const list&lt)
		{
			empty_init();
			for (auto& e : lt)push_back(e);
		}
		list& operator=(list<T>lt) {
			swap(lt);
			return *this;
		}
		~list() {
			clear();
			delete _head;
			_head = nullptr;

		}
		iterator insert(iterator pos,const T& x) {
			Node* newnode = new Node(x);
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			cur->_prev = newnode;
			prev->_next = newnode;
			newnode->_next=cur;
			newnode->_prev = prev;

			++_sz;
			return iterator(newnode);
		}
		void push_back(const T& x) {
			insert(end(), x);
		}
		void pop_back() {
			if(_sz>0)erase(--end());
		}
		void pop_front() {
			erase(begin());
		}
		void push_front(const T& x) {
			insert(begin(), x);
		}
		iterator erase(iterator pos) {
			assert(pos != end());
			Node* cur = pos._node;
			Node* prev = cur->_prev;
			Node* ne=cur->_next;
			prev->_next = ne;
			ne->_prev = prev;
			delete cur;
			--_sz;
			return iterator(ne);
		}

		iterator begin() {
			return _head->_next;
		}
		const_iterator begin()const {
			return _head->_next;
		}
		iterator end() {
			return _head;
		}
		const_iterator end()const {
			return _head;
		}
		bool empty()const {
			return _sz == 0;
		}
		size_t size()const {
			return _sz;
		}
	private:
		Node* _head;
		size_t _sz;
	};



}