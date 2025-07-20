#include"AVL.h"
#include<vector>

int main()
{
	//int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLT<int, int> t;
	for (auto e : a)
	{
		
		t.insert(std::make_pair(e, e));
		//std::cout << "Insert:" << e << "->" << t.IsBalance() << endl;
	}
	 t.inorder();
	return 0;
}