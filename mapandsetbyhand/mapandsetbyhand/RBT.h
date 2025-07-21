#pragma once
#include<iostream>
enum Colour{
	RED,
	BLACK
};

template<class T>
class RBTnode {
public:
	RBTnode<T>* _left;
	RBTnode<T>* _right;
	RBTnode<T>* _parent;
	T _data;
	Colour _col;
	RBTnode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T,class Ptr,class Ref>
struct _RBiterator {
	typedef RBTnode<T> Node;
	Node* _node;
	typedef _RBiterator<T, Ptr, Ref> self;
	typedef _RBiterator<T,T*,T&> iterator;
	//
	_RBiterator(const iterator& it)
		:_node(it._node)
	{ }
	_RBiterator(Node* node)
		:_node(node) 
	{ }
	Ref operator*()
	{
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}
	bool operator!=(const self& s)const
	{
		return _node != s._node;
	}
	bool operator==(const self& s)const
	{
		return _node == s._node;
	}
	self& operator--()
	{
		if (_node == nullptr) return *this; // end()-- 未定义行为
		if (_node->_left) {
			Node* subright = _node->_left;
			while (subright->_right) subright = subright->_right;
			_node = subright;
		}
		else {
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_left) {
				cur = parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	self& operator++()
	{
		if (_node->_right)
		{
			Node* subleft = _node->_right;
			while (subleft->_left) {
				subleft = subleft->_left;
			}
			_node = subleft;
		}
		else {
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent&& cur == parent->_right) {
				
				
					cur = cur->_parent;
					parent = parent->_parent;
			
			}
			_node = parent;
		}
		return *this;
	}
};

// set->RBTree<K, K, SetKeyOfT> _t;
// map->RBTree<K, pair<K, V>, MapKeyOfT> _t;
template<class K, class T,class keyofT>
class RBT {
public:
	typedef RBTnode<T> Node;
	typedef _RBiterator<T,T*,T&> iterator;
	typedef _RBiterator<T,const T*,const T& > const_iterator;
	iterator begin()
	{
		Node* minnode = _root;
		while (minnode&& minnode->_left) {
			minnode = minnode->_left;
		}
		return iterator(minnode);
	}
	iterator end()
	{
		/*Node* maxnode = _root;
		while (maxnode&& maxnode->_right) {
			maxnode = maxnode->_right;
		}*/
		return iterator(nullptr);

	}
	const_iterator begin()const
	{
		Node* minnode = _root;
		while (minnode && minnode->_left) {
			minnode = minnode->_left;
		}
		return const_iterator(minnode);
	}
	const_iterator end()const
	{
	/*	Node* maxnode = _root;
		while (maxnode && maxnode->_right) {
			maxnode = maxnode->_right;
		}*/
		return const_iterator(nullptr);
	}
	Node* find(const K& key) 
	{
		Node* cur = _root;
		keyofT kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}
	std::pair<iterator, bool> insert(const  T& data) {
		if (_root == nullptr) {
			_root = new Node(data);
			_root->_col = BLACK;
			return std::make_pair(iterator(_root),true);
		}
		Node* cur = _root;
		Node* parent = nullptr;
		keyofT koft;
		while (cur) {
			if (koft(cur->_data) < koft(data)) {
				parent = cur;
				cur = cur->_right;
			}
			else if (koft(cur->_data) >koft(data)) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return std::make_pair(iterator(cur), false);
			}
		}
		cur = new Node(data);
		Node* newnode = cur;
		if (koft(parent->_data) > koft(cur->_data)) {
			parent->_left = cur;
			
		}
		else {
			parent->_right = cur;
			
		}
		cur->_parent = parent;
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (!grandfather) break; // 根节点或父节点为根时直接跳出
			if (parent == grandfather->_left) {
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED) {

					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						rotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;

					}
					else {
						rotateL(parent);
						rotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
			}
			else //parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED) {

					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						rotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;

					}
					else {
						rotateR(parent);
						rotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
				}
			}
		}




		_root->_col = BLACK;

		return std::make_pair(iterator(newnode), true);
	}
	//左单旋
	void rotateL(Node* parent) {
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		Node* pphead = parent->_parent;
		parent->_right = curleft;

		if (curleft)curleft->_parent = parent;
		cur->_left = parent;
		parent->_parent = cur;
		if (pphead) {
			if (pphead->_left == parent) {
				pphead->_left = cur;
			}
			else {
				pphead->_right = cur;
			}
			cur->_parent = pphead;

		}
		else {
			_root = cur;

			cur->_parent = nullptr;
		}
	


	}
	//右单旋
	void rotateR(Node* parent) {
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		Node* pphead = parent->_parent;


		parent->_left = curright;
		if (curright)curright->_parent = parent;
		cur->_right = parent;
		parent->_parent = cur;
		if (pphead) {
			if (pphead->_left == parent) {
				pphead->_left = cur;
			}
			else {
				pphead->_right = cur;
			}
			cur->_parent = pphead;
		}
		else {
			_root = cur;
			cur->_parent = nullptr;
		}
		


	} 
	void clear() {
		_clear(_root);
		_root = nullptr;
		_size = 0;
	}

	void inorder() const {
		_inorder(_root);
		std::cout << std::endl;
	}

	size_t size() const { return _size; }
	bool empty() const { return _size == 0; }

private:
	void _clear(Node* node) {
		if (!node) return;
		_clear(node->_left);
		_clear(node->_right);
		delete node;
	}
	void _inorder(Node* node) const {
		if (!node) return;
		_inorder(node->_left);
		std::cout << node->_data << " ";
		_inorder(node->_right);
	}
	Node* _root=nullptr;
	size_t _size=0;
};