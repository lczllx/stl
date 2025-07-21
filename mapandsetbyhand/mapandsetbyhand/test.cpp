#include"RBT.h"
#include"set.h"
#include"map.h"
#include<vector>
#include<iostream>
int main()
{
	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	lcz::set<int> t;
	lcz::map<int,int> m;
	for (auto e : a)
	{
		m.insert(std::make_pair(e,e));
		t.insert(e);
		//std::cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	//t.inorder();
	for (auto e : t)std::cout << e << " ";
	for (auto e : m)std::cout << e.first << " "<<e.second<<std::endl;
	return 0;
}