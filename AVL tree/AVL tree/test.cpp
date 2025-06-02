#include "AVL tree.h"
#include<vector>


//int main() {
//
//	AVLTree<int, int>t;
//	int a[] = { 5,6,9,88,97,2,11,33,1,0 };
//	for (int i = 1; i <= 10; i++) {
//		t.Insert({ i,i });
//		cout <<"insert:"<<i<<"->"<< t.IsBalance() << endl;
//	}
//	for (auto e:a) {
//		if (e == 11) {
//			int c = 0;
//		}
//		t.Insert({ e,e });
//		cout << "insert:" << e<< "->" << t.IsBalance() << endl;
//	}
//	return 0;
//}

int main() {
	const int N = 10000000;
	vector<int>v;
	srand(time(0));
	AVLTree<int, int>t;
	int a[] = { 5,6,9,88,97,2,11,33,1,0 };
	for (int i = 1; i <= N; i++) {
		v.push_back(rand());
	}
	for (auto e : v) {
		
		t.Insert({ e,e });
		cout << "insert:" << e << "->" << t.IsBalance() << endl;
		cout << t.Hight() << endl;
	}
	return 0;
}