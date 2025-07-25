#include<iostream>
using namespace std;

//struct a {
//	/*explicit  a(int x,int y)*/
//	a(int x, int y)
//		:_x(x),_y(y){ }
//	int _x, _y;
//};
//int main()
//{
//	int x = 1;
//	int y = { 2 };
//	int z{ 3 };
//
//	int a1[] = { 2,3,4 };
//	int a2[]{ 2,4 };
//
//	//本质是调用构造函数
//	a b(2, 4);
//	a b1 = { 2,4 };
//	a b2{ 2,4 };
//	const a& p = { 2,5 };
//	return 0;
//}
//#include<vector>
//struct a {
//	
//	a(int x, int y)
//		:_x(x), _y(y) {
//	}
//	int _x, _y;
//};
//int main()
//{
//	vector<int> v = { 1,2,42,4 };
//	
//	return 0;
//}

#include<vector>
//int main()
//{
//	auto pf = malloc;
//	cout << typeid(pf).name() << endl;
//	auto pf1 = pf;
//	cout << typeid(pf1).name() << endl;
//
//	decltype(pf)pf2;
//	cout << typeid(pf2).name() << endl;
//
//	return 0;
//}

//void add(const int x,const int y);
//void func(const int& x) { cout << 1 << endl; }
//void func( int&& x) { cout << 2 << endl; }
//int main()
//{
//	////左值
//	int x = 2;
//	//int* p = &x;
//	//const int z = 4;
//	////右值
//	//1;
//	//x + z;
//	//add(x, z);
//	//"sjdfhjs";//可以取地址是左值
//
//
//	////左值引用
//	int a = 3;
//	//int& a2  = a;
//	////左值引用能不能给右值取别名
//	//const int& pp = 11;
//
//	////右值引用
//	//int&& op = 13;
//
//	////右值引用能不能给左值取别名
//	//int&& ppp = move(a);
//
//	func(a);
//	func(a + x);
//	
//	return 0;
//}

int main()
{
	//lambda表达式
	auto less=[](int x, int y)->bool {return x < y; };




	return 0;
}