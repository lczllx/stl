#include<iostream>

#include "stl_set.h"

using namespace std;
//int main() {
//	set<int>s;
//	s.insert(5);
//	s.insert(5);
//	s.insert(6);
//	s.insert(9);
//	s.insert(7);
//	s.insert(51);
//
//	for (auto e : s)cout << e << " ";
//	cout << endl;
//	cout << s.count(5) << endl;
//
//	return 0;
//}

int main() {
    lcz::set<int> s;
    s.insert(2);
    s.insert(8);
    s.insert(9);

    lcz::set<int>::iterator it = s.begin();
    while (it != s.end()) {
        cout << *it << " ";
        ++it;
    }
    return 0;
}