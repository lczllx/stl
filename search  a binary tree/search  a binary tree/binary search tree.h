#pragma once
//BST

template<class K>
struct BStreeNode {
	BStreeNode<K>* _left;
	BStreeNode<K>* _right;
	K _val;
	BStreeNode(const K& val)
		: _left(nullptr)
		, _right(nullptr)
		, _val(val)
	{
	}
	
};
template<class K>
class BsTree {
	typedef BStreeNode<K> node;

public:
	BsTree():_root(nullptr){}
	bool insert(const K& val) {
		if (_root == nullptr) {
			_root = new node(val);
			return true;
		}
		node* cur = _root;
		node* parent = cur;
		while (cur) {
			parent = cur;

			if (cur->_val<val) {
				cur = cur->_right;
			}
			else if (cur->_val > val) {
				cur = cur->_left;
				
			}
			else {
				return false;
			}
		}
		cur = new node(val);
		if (val > parent->_val) {
			parent->_right = cur;
		}
		else {
			parent->_left = cur;

		}
		return true;
	}
	void Inorder() {
		inorder(_root);
		cout << endl;
	}
	void inorder(node* root) {
		if (root == nullptr)return;
		inorder(root->_left);
		cout << root->_val << " ";
		inorder(root->_right);
	}
	bool Erase(node*& root, const K& x) {
		if (root == nullptr) {
			return false;
		}
		if (root->_val < x) return Erase(root->_right, x);
		else if (root->_val > x) return Erase(root->_left, x);
		else {
			if (root->_left == nullptr) {
				node* del = root;
				root = root->_right;
				delete del;
				return true;
			}
			else if (root->_right == nullptr) {
				node* del = root;
				root = root->_left;
				delete del;
				return true;
			}
			else {
				// 找左子树最大节点（前驱）
				node* cur = root->_left;
				while (cur->_right) {
					cur = cur->_right;
				}
				swap(root->_val, cur->_val);
				return Erase(root->_left, x);
			}
		}
	}
	bool erase(const K&x) {
		node* cur = _root; node* parent = nullptr;
		while (cur) {
			if (cur->_val < x) {
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_val > x) {
				parent = cur;
				cur = cur->_left;
			}
			else {
				break;
			}
		}
		if (!cur)return false;
		if (cur->_left == nullptr) //左边为空	
		{
			if (parent == nullptr) {
				_root = cur->_right;
			}
			else if (parent->_left == cur) {
				parent->_left = cur->_right;
			}
			else {
				parent->_right = cur->_right;
			}
			delete cur;

		}
		else if (cur->_right == nullptr)//右边为空
		{
			if (parent == nullptr) {
				_root = cur->_left;
			}
			else if (parent->_left == cur) {
				parent->_left = cur->_left;
			}
			else {
				parent->_right = cur->_left;

			}
			delete cur;

		}
		else //两边不为空
		{
			node* pphead = cur;
			node* ppphead = pphead;
			pphead = cur->_left;
			while (pphead->_right) {
				ppphead = pphead;
				pphead = pphead->_right;
			}
			cur->_val = pphead->_val;
			if (ppphead == cur) {
				ppphead->_left = pphead->_left;
			}
			else {
				ppphead->_right = pphead->_left;
			}
			
		
			delete pphead;

		}
		return true;
	}
private:
	node* _root;
};
void test1() {
	int a[] = { 2,5,64,66,6,61,20,8,823,56,82,2,99 };
	BsTree<int>bt;

	for (auto e : a)bt.insert(e);
	bt.Inorder();
	bt.erase(823);
	bt.Inorder();
	bt.erase(2);

	bt.Inorder();
	cout << bt.erase(823) << endl;;
	bt.erase(5);
	bt.Inorder();

	bt.erase(61);
	bt.Inorder();



}