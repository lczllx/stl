#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
template<class K,class V>
class AVLTreeNode {
public:
	pair<K, V>_kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{ }
};

template<class K, class V>
class AVLTree {
	
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
		
	{ }
	~AVLTree() {
		destory(_root);
	}
	bool Insert(const pair<K, V>& kv) {
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent=nullptr;
		while (cur) {
			if (cur->_kv.first < kv.first) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first > cur->_kv.first) {
			parent->_left = cur;
			cur->_parent = parent;
		}
		else {
			parent->_right = cur;
			cur->_parent = parent;
		}

		//Æ½ºâÒò×Ó¸üÐÂ

		while (parent) {
			if (cur == parent->_left) {
				parent->_bf--;
			}
			else if (cur == parent->_right) {
				parent->_bf++;

			}
			else {
				break;
			}
			if (parent->_bf == 0) {
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				//Ðý×ª
				if (parent->_bf == 2 &&cur->_bf==1)
				{
					//×óÐý
					left_rotate(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					//ÓÒÐý
					right_rotate(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					//ÓÒ×óÐý
					right_left_rotate(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					//×óÓÒÐý
				   left_right_rotate(parent);
				}
				break;
			}
			else {
				//Å×Òì³£
				assert(false);
			}
		}


		return true;
	}

	void left_rotate(Node* parent) {
		Node* cur = parent->_right;
		Node* pphead = parent->_parent;
		Node* curleft = cur->_left;
		 
		if(curleft)curleft->_parent = parent;

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
		parent->_bf = cur->_bf = 0;
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
		parent->_bf = cur->_bf = 0;
	}
	//ÓÒ×óÐý
	void right_left_rotate(Node*parent) 
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		int bf = curleft->_bf;
		right_rotate(parent->_right);
		left_rotate(parent);
		if (bf == 0) {
			cur->_bf = parent->_bf = curleft->_bf = 0;
		}
		else if (bf == 1) {
			cur->_bf = 0;
			curleft->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1) {
			cur->_bf = 1;
			curleft->_bf = 0;
			parent->_bf = 0;
		}
		else {
			assert(false);
		}
	}

	//×óÓÒÐý
	void left_right_rotate(Node* parent) {
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;
		left_rotate(parent->_left);
		right_rotate(parent);
		if (bf == 0) {
			cur->_bf = parent->_bf = curright->_bf = 0;
		}
		else if (bf == 1) {
			cur->_bf = -1;
			curright->_bf =0;
			parent->_bf =0;
		}
		else if (bf == -1) {
			cur->_bf = 0;
			curright->_bf = 0;
			parent->_bf = 1;
		}
		else {
			assert(false);
		}
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
	void destory(Node* root) {
		if (root == nullptr)return;
		destory(root->_left);
		destory(root->_right);
		delete root;
	}
	bool IsBalance() {
		return IsBalance(_root);
	}
	bool IsBalance(Node* root)  {
		if (root == nullptr)return true;
		int lefthight = hight(root->_left);
		int righthight = hight(root->_right);
		if (righthight - lefthight != root->_bf) {
			cout << "error" <<root->_bf<<" "<<root->_kv.first << " " << root->_kv.second << endl;
			return false;
		}
		return abs(lefthight - righthight) < 2 && IsBalance(root->_left) && IsBalance(root->_right);
	}
private:
	Node* _root; 
	
};

