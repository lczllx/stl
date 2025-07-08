#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include<vector>
//using namespace std;
//
//#include"RBTree.h"

//// ²âÊÔ´úÂë
//void TestRBTree1()
//{
//	RBTree<int, int> t;
//	// ³£¹æµÄ²âÊÔÓÃÀı
//	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	// ÌØÊâµÄ´øÓĞË«Ğı³¡¾°µÄ²âÊÔÓÃÀı
//	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
//	for (auto e : a)
//	{
//		t.Insert({ e, e });
//	}
//	t.InOrder();
//	cout << t.IsBalanceTree() << endl;
//}
//
//void TestRBTree2()
//{
//	const int N = 10000000;
//	vector<int> v;
//	v.reserve(N);
//	srand(time(0));
//
//	for (size_t i = 0; i < N; i++)
//	{
//		v.push_back(rand() + i);
//	}
//
//	RBTree<int, int> t;
//	for (size_t i = 0; i < v.size(); ++i)
//	{
//		t.Insert(make_pair(v[i], v[i]));
//	}
//	cout << t.IsBalanceTree() << endl;
//}
//
//int main()
//{
//	TestRBTree2();
//
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////
#include"myset.h"
//#include"mymap.h"
#include<iostream>
using namespace std;
void Print(const bit::set<int>& s)
{
	for (auto& e : s)
	{
		//e++;
		cout << e << " ";
	}
	cout << endl;
}

void test_set()
{
	bit::set<int> s;
	s.insert(4);
	s.insert(1);
	s.insert(3);
	s.insert(6);
	s.insert(16);
	s.insert(6);
	s.insert(36);
	s.insert(-6);
	s.insert(9);

	bit::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto& e : s)
	{
		//e++;
		cout << e << " ";
	}
	cout << endl;

	Print(s);

	it = s.end();
	while (it != s.begin())
	{
		--it;
		cout << *it << " ";
	}
	cout << endl;
}

//void test_map()
//{
//	bit::map<string, string> dict;
//	dict.insert({ "sort", "ÅÅĞò" });
//	dict.insert({ "left", "×ó±ß" });
//	dict.insert({ "right", "ÓÒ±ß" });
//
//	bit::map<string, string>::iterator it = dict.begin();
//	while (it != dict.end())
//	{
//		//it->first += 'x';
//		it->second += 'x';
//
//		cout << it->first << ":" << it->second << endl;
//		++it;
//	}
//	cout << endl;
//
//	dict["insert"];
//	dict["left"] = "×ó±ß¡¢Ê£Óà";
//
//	for (auto& e : dict)
//	{
//		cout << e.first << ":" << e.second << endl;
//	}
//	cout << endl;
//}

int main()
{
	test_set();
	//test_map();

	return 0;
}