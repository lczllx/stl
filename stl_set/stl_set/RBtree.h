#pragma once
#pragma once
#pragma once
#include<iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

////template<class K, class V>
////class RBTreeNode {
////public:
////	Colour _col;
////	std::pair<K, V>_kv;
////	RBTreeNode<K, V>* _left;
////	RBTreeNode<K, V>* _right;
////	RBTreeNode<K, V>* _parent;
////
////	RBTreeNode(const std::pair<K,V>&kv)
////		:_col(RED)
////		,_kv(kv)
////		, _left(nullptr)
////		, _right(nullptr)
////		, _parent(nullptr)
////		
////	{ }
////};
//
//
////template<class K, class V>
////class RBTree {
////public:
////	typedef RBTreeNode<K, V> Node;
////	bool Insert(const std::pair<K, V>& kv) {
////		if (_root == nullptr) {
////			_root = new Node(kv);
////			_root->_col = BLACK;
////			return true;
////		}
////		Node* cur = _root;
////		Node* parent = nullptr;
////		while (cur) {
////			if (cur->_kv.first < kv.first) {
////				parent = cur;
////				cur = cur->_right;
////			}
////			else if (cur->_kv.first > kv.first) {
////				parent = cur;
////				cur = cur->_left;
////			}
////			else {
////				return false;
////			}
////		}
////		cur = new Node(kv);
////		cur->_col = RED;
////		if (parent->_kv.first > cur->_kv.first) {
////			parent->_left = cur;
////			cur->_parent = parent;
////		}
////		else {
////			parent->_right = cur;
////			cur->_parent = parent;
////		}
////
////		while (parent && parent->_col == RED)
////		{
////			Node* grantfather = parent->_parent;
////			if (grantfather == nullptr)break;
////			if (parent == grantfather->_left) {
////				Node* uncle = grantfather->_right;
////				if (uncle && uncle->_col == RED) {
////					parent->_col = uncle->_col = BLACK;
////					grantfather->_col = RED;
////
////					cur = grantfather;
////					parent = cur->_parent;
////				}
////				else //u不存在或存在为黑
////				{
////					if (parent->_left == cur) {
////						right_rotate(grantfather);
////
////						parent->_col = BLACK;
////						grantfather->_col = RED;
////
////						break;
////					}
////					else {
////						left_rotate(parent);
////						right_rotate(grantfather);
////
////						cur->_col = BLACK;
////						grantfather->_col = RED;
////						break;
////
////					}
////				}
////					
////			}
////			else //parent == grantfather->_right
////			{
////				Node* uncle = grantfather->_left;
////				if (uncle && uncle->_col == RED) {
////					parent->_col = uncle->_col = BLACK;
////					grantfather->_col = RED;
////
////					cur = grantfather;
////					parent = cur->_parent;
////				}
////				else //u不存在或存在为黑
////				{
////					if (parent->_right == cur) {
////						left_rotate(grantfather);
////						parent->_col = BLACK;
////						grantfather->_col = RED;
////						break;
////
////					}
////					else {
////						right_rotate(parent);
////						left_rotate(grantfather);
////
////						cur->_col = BLACK;
////						grantfather->_col = RED;
////
////						break;
////					}
////				}
////			}
////		}
////		_root->_col = BLACK;
////		return true;
////	}
////
////	void left_rotate(Node* parent) {
////		Node* cur = parent->_right;
////		Node* pphead = parent->_parent;
////		Node* curleft = cur->_left;
////
////		if (curleft)curleft->_parent = parent;
////
////		parent->_right = curleft;
////		cur->_left = parent;
////		parent->_parent = cur;
////
////		if (pphead) {
////			if (pphead->_left == parent) {
////				pphead->_left = cur;
////			}
////			else {
////				pphead->_right = cur;
////
////			}
////			cur->_parent = pphead;
////		}
////		else {
////			_root = cur;
////			cur->_parent = nullptr;
////		}
////		
////	}
////
////	void right_rotate(Node* parent) {
////		Node* cur = parent->_left;
////		Node* pphead = parent->_parent;
////		Node* curright = cur->_right;
////
////		if (curright)curright->_parent = parent;
////
////		parent->_left = curright;
////		cur->_right = parent;
////		parent->_parent = cur;
////
////		if (pphead) {
////			if (pphead->_left == parent) {
////				pphead->_left = cur;
////			}
////			else {
////				pphead->_right = cur;
////
////			}
////			cur->_parent = pphead;
////		}
////		else {
////			_root = cur;
////			cur->_parent = nullptr;
////		}
////		
////	}
////	bool Isbalance() {
////		return Isbalance(_root);
////	}
////	bool checkcolor(Node* root,int blackmark,int blacknum) {
////		if (root == nullptr) {
////			if (blacknum != blackmark)return false;
////			return true;
////		}
////		if (root->_col == RED && root->_parent && root->_parent->_col == RED) {
////			if (root->_col == RED && root->_parent && root->_parent->_col == RED) {
////				cout << "连续红色节点: " << root->_kv.first << " 和 " << root->_parent->_kv.first << endl;
////			}
////			return false;
////		}
////		
////		if (root->_col == BLACK)blacknum++;
////		return checkcolor(root->_left, blackmark, blacknum) && checkcolor(root->_right, blackmark, blacknum);
////
////	}
////	bool Isbalance(Node* root) {
////		if (root == nullptr)return true;
////		if (root->_col != BLACK) return false;
////		Node* cur = root; int blackmark = 0;
////		while (cur) {
////			if (cur->_col == BLACK)blackmark++;
////			cur = cur->_left;
////		}
////		return checkcolor(root, blackmark,0);
////     }
////
////	int Hight() {
////		return hight(_root);
////	}
////	int hight(Node* root) {
////		if (root == nullptr)return 0;
////		int lh = hight(root->_left);
////		int rh = hight(root->_right);
////		return lh > rh ? lh + 1 : rh + 1;
////	}
////private:
////	Node* _root = nullptr;
////};
//

template<class T>
class RBTreeNode {
public:
	Colour _col;
	T _data;
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	RBTreeNode(const T& data)
		:_col(RED)
		, _data(data)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)

	{
	}
};
//          元素类型  指针类型   引用类型
template<class T, class Ptr, class Ref>
struct __treeIterator {
	typedef RBTreeNode<T> Node;
	typedef __treeIterator<T, Ptr, Ref> Self;
	typedef __treeIterator<T, T*, T&> Iterator;

	__treeIterator(const Iterator& it)
		:_node(it._node)
	{
	}

	Node* _node;
	__treeIterator(Node* node)
		:_node(node)
	{
	}
	Ref operator*() {
		return _node->_data;
	}
	Ptr operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)const
	{
		return _node != s._node;
	}
	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}

	Self& operator--() {
		Node* cur = _node;
		if (cur->_left) {
			cur = cur->_left;
			while (cur->right) {
				cur = cur->_right;
			}
			_node = cur;
		}
		else //
		{
			Node* parent = cur->_parent;
			//找孩子是父亲右的那个点
			while (parent) {
				if (cur == parent->_right) {
					break;
				}
				else {
					cur = parent;
					parent = parent->_parent;
				}

			}
			//找到或为空
			_node = parent;
		}
		return *this;
	}
	Self& operator++() {

		Node* cur = _node;

		if (cur->_right) {
			//右树的最小节点
			cur = cur->_right;
			while (cur->_left)cur = cur->_left;
			_node = cur;
		}
		else //
		{
			Node* parent = cur->_parent;
			//找孩子是父亲左的那个祖先点，就是下一个要访问的节点
			while (parent) {
				if (cur == parent->_left) {
					break;
				}
				else {
					cur = parent;
					parent = parent->_parent;
				}

			}
			//找到或为空
			_node = parent;
		}
		return *this;
	}
};
template<class K, class T, class KeyOfT>
class RBTree {
	typedef RBTreeNode<T> Node;

public:

	typedef __treeIterator<T, T*, T&> iterator;
	typedef __treeIterator<T, const T*, const T&> const_iterator;
	//typedef __TreeIterator<T, T&, T*> Iterator;
	iterator begin() {
		Node* leftnode = _root;
		while (leftnode && leftnode->_left) {
			leftnode = leftnode->_left;
		}

		return iterator(leftnode);
	}
	iterator end() {
		return iterator(nullptr);
	}
	const_iterator begin()const {
		Node* leftnode = _root;
		while (leftnode && leftnode->_left) {
			leftnode = leftnode->_left;
		}

		return const_iterator(leftnode);
	}
	const_iterator end()const {
		return const_iterator(nullptr);
	}
	Node* find(const K& key) {
		KeyOfT kot;
		Node* cur = _root;
		while (cur) {
			if (kot(cur->_data) < key) {
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key) {
				cur = cur->_left;
			}
			else {
				return cur;
			}
		}


		return nullptr;
	}
	pair<iterator, bool> Insert(const T& data) {

		if (_root == nullptr) {
			_root = new Node(data);
			_root->_col = BLACK;
			return make_pair(iterator(_root), true);
		}
		KeyOfT kot;
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur) {
			if (kot(cur->_data) < kot(data)) {
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data)) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return make_pair(iterator(cur), true);



			}
		}
		cur = new Node(data);
		Node* tmpp = cur;
		cur->_col = RED;
		if (kot(parent->_data) > kot(cur->_data)) {
			parent->_left = cur;
			cur->_parent = parent;
		}
		else {
			parent->_right = cur;
			cur->_parent = parent;
		}

		while (parent && parent->_col == RED)
		{
			Node* grantfather = parent->_parent;
			if (grantfather == nullptr)break;
			if (parent == grantfather->_left) {
				Node* uncle = grantfather->_right;
				if (uncle && uncle->_col == RED) {
					parent->_col = uncle->_col = BLACK;
					grantfather->_col = RED;

					cur = grantfather;
					parent = cur->_parent;
				}
				else //u不存在或存在为黑
				{
					if (parent->_left == cur) {
						right_rotate(grantfather);

						parent->_col = BLACK;
						grantfather->_col = RED;

						break;
					}
					else {
						left_rotate(parent);
						right_rotate(grantfather);

						cur->_col = BLACK;
						grantfather->_col = RED;
						break;

					}
				}

			}
			else //parent == grantfather->_right
			{
				Node* uncle = grantfather->_left;
				if (uncle && uncle->_col == RED) {
					parent->_col = uncle->_col = BLACK;
					grantfather->_col = RED;

					cur = grantfather;
					parent = cur->_parent;
				}
				else //u不存在或存在为黑
				{
					if (parent->_right == cur) {
						left_rotate(grantfather);
						parent->_col = BLACK;
						grantfather->_col = RED;
						break;

					}
					else {
						right_rotate(parent);
						left_rotate(grantfather);

						cur->_col = BLACK;
						grantfather->_col = RED;

						break;
					}
				}
			}
		}
		_root->_col = BLACK;
		return make_pair(iterator(tmpp), true);


	}

	void left_rotate(Node* parent) {
		Node* cur = parent->_right;
		Node* pphead = parent->_parent;
		Node* curleft = cur->_left;

		if (curleft)curleft->_parent = parent;

		parent->_right = curleft;
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

	void right_rotate(Node* parent) {
		Node* cur = parent->_left;
		Node* pphead = parent->_parent;
		Node* curright = cur->_right;

		if (curright)curright->_parent = parent;

		parent->_left = curright;
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
	bool Isbalance() {
		return Isbalance(_root);
	}
	bool checkcolor(Node* root, int blackmark, int blacknum) {
		if (root == nullptr) {
			if (blacknum != blackmark)return false;
			return true;
		}
		if (root->_col == RED && root->_parent && root->_parent->_col == RED) {
			if (root->_col == RED && root->_parent && root->_parent->_col == RED) {
				cout << "连续红色节点: " << kot(root->_data) << " 和 " << kot(root->_parent->_data) << endl;
			}
			return false;
		}

		if (root->_col == BLACK)blacknum++;
		return checkcolor(root->_left, blackmark, blacknum) && checkcolor(root->_right, blackmark, blacknum);

	}
	bool Isbalance(Node* root) {
		if (root == nullptr)return true;
		if (root->_col != BLACK) return false;
		Node* cur = root; int blackmark = 0;
		while (cur) {
			if (cur->_col == BLACK)blackmark++;
			cur = cur->_left;
		}
		return checkcolor(root, blackmark, 0);
	}

	int Hight() {
		return hight(_root);
	}
	int hight(Node* root) {
		if (root == nullptr)return 0;
		int lh = hight(root->_left);
		int rh = hight(root->_right);
		return lh > rh ? lh + 1 : rh + 1;
	}
private:
	Node* _root = nullptr;
};



