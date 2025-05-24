#include "list.h"
#include<iostream>
#include<list>
#include<algorithm>
using namespace std;
void test_list1() {
	list<int>lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(3);
	lt.push_back(5);
	lt.push_front(88);
	lt.push_front(66);
	for (auto e : lt)cout << e << " ";
	cout << endl;

	auto it = lt.begin();
	for (int i = 0; i < 5; i++)it++;
	lt.insert(it, 888);
	for (auto e : lt)cout << e << " ";
	cout << endl;

	it = find(lt.begin(), lt.end(), 888);
	if (it != lt.end()) {
		lt.insert(it, 998);
	}
	for (auto e : lt)cout << e << " ";
	cout << endl;


	reverse(lt.begin(), lt.end());
	for (auto e : lt)cout << e << " ";
	cout << endl;
	lt.reverse();
	for (auto e : lt)cout << e << " ";
	cout << endl;
}
//void test_list2() {
//	 
//}

//int main() {
//
//	/*test_list1();
//	test_list2();*/
//	//lcz::test_list1();
//	lcz::test_list3();
//	return 0;
//}
?int main()
{

	int ar[] = { 0,1, 2, 3, 4,  5, 6, 7, 8, 9 };

	int n = sizeof(ar) / sizeof(int);

	list<int> mylist(ar, ar + n);

	list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);

	reverse(mylist.begin(), pos);

	reverse(pos, mylist.end());

	list<int>::const_reverse_iterator crit = mylist.crbegin();

	while (crit != mylist.crend())

	{

		cout << *crit << " ";

		++crit;

	}

	cout << endl;
	return 0;
}