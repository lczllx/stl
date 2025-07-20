#pragma once
#include<iostream>
#include<assert.h>
template<class K,class V>
struct AVLnode {
	std::pair<K, V> _kv;
	AVLnode<K, V>* _left;
	AVLnode<K, V>* _right;
	AVLnode<K, V>* _parent;
	int _bf;
	AVLnode(const std::pair<K,V>&kv)
		:_kv(kv),_left(nullptr),_right(nullptr),_parent(nullptr),_bf(0)
	{}
};

template<class K, class V>
class AVLT {
public:
	typedef AVLnode<K, V> Node;
	Node* find(const K& key) const {
		Node* cur = _root;
		while (cur) {
			if (key < cur->_kv.first)
				cur = cur->_left;
			else if (key > cur->_kv.first)
				cur = cur->_right;
			else
				return cur;
		}
		return nullptr;
	}
	bool insert(const std::pair<K,V>& kv)
	{
		if (_root == nullptr) {
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			
			 if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_kv.first >kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else {
				 return false;
			}
		}
		cur= new Node(kv);
		if (parent->_kv.first < kv.first) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;
		}
		cur->_parent = parent;
		while (parent)
		{
			if (parent->_left == cur) {
				parent->_bf--;
			}
			else {
				parent->_bf++;
			}

			if (parent->_bf == 0)break;
			else if (parent->_bf == 1 || parent->_bf == -1) {
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) {
				if (parent->_bf == 2 && cur->_bf == 1) {
					romateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1) {
					romateR(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					romateLR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					romateRL(parent);

				}
				break;
			}
			else {
				assert(false);
			}
		}

		return true;
	}
	//×óµ¥Ðý
	void romateL(Node* parent) {
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
		parent->_bf = cur->_bf = 0;

	}
	//ÓÒµ¥Ðý
	void romateR(Node* parent) {
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
		parent->_bf = cur->_bf = 0;

	}
	//×óÓÒË«Ðý
	void romateLR(Node* parent) {
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		Node* pphead = parent->_parent;
		int bf = curright->_bf;
		romateL(parent->_left);
		romateR(parent);
		if (bf == 0) {
			cur->_bf = 0;
			parent->_bf = 0;
			curright->_bf = 0;

		}
		else if (bf == 1) {
			cur->_bf = -1;
			parent->_bf = 0;
			curright->_bf = 0;
		}
		else if (bf == -1) {
			cur->_bf = 0;
			parent->_bf = 1;
			curright->_bf = 0;
		}
	}
	//ÓÒ×óË«Ðý
	void romateRL(Node* parent) {
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		Node* pphead = parent->_parent;
		int bf = curleft->_bf;
		romateL(parent->_right);
		romateR(parent);
		if (bf == 0) {
			cur->_bf = 0;
			parent->_bf = 0;
			curleft->_bf = 0;

		}
		else if (bf == 1) {
			cur->_bf = -1;
			parent->_bf = -1;
			curleft->_bf = 0;
		}
		else if (bf == -1) {
			cur->_bf = 1;
			parent->_bf = 0;
			curleft->_bf = 0;
		}
	}
	int Height()
	{
		return Height(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHight = Height(root->_left);
		int rightHight = Height(root->_right);

		if (rightHight - leftHight != root->_bf)
		{
			std::cout << "Æ½ºâÒò×ÓÒì³£:" << root->_kv.first << "->" << root->_bf << std::endl;
			return false;
		}

		return abs(rightHight - leftHight) < 2
			&& IsBalance(root->_left)
			&& IsBalance(root->_right);
	}

	void inorder() const 
	{
    _inorder(_root);
    std::cout << std::endl;
     }
private:
void _inorder(Node* node) const 
{
    if (!node) return;
    _inorder(node->_left);
    std::cout << node->_kv.first << " ";
    _inorder(node->_right);
}

private:
	Node* _root=nullptr;
public:
	~AVLT() {
    _destroy(_root);
}
private:
void _destroy(Node* node) {
    if (!node) return;
    _destroy(node->_left);
    _destroy(node->_right);
    delete node;
}
};