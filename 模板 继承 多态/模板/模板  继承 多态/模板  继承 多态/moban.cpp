//#include<iostream>
//#include<vector>
//using namespace std;
////template<class Container>
////void print(const Container& v) {
////	//没有具体的类型，编译器不确定Container::const_iterator是类型还是对象
////	//没有实例化需要加typename，告诉编译器是类型，等模板实例化再去解析
////	typename Container::const_iterator it = v.begin();
////	while (it != v.end()) {
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////}
////int main() {
////
////	vector<int>v(10, 1);
////	print(v);
////
////	return 0;
////}
//
////void print(const Container& v) {
////	//没有具体的类型，编译器不确定Container::const_iterator是类型还是对象
////	//没有实例化需要加typename，告诉编译器是类型，等模板实例化再去解析
////	typename Container::const_iterator it = v.begin();
////	while (it != v.end()) {
////		cout << *it << " ";
////		++it;
////	}
////	cout << endl;
////}
//
////template<class T,size_t N>
////class stack 
////{
////public:
////	void f() {
////		N = 0;
////	}
////private:
////	T a[N];
////	int top;
////};
////int main() {
////
////	stack<int, 10>st;
////	stack<int,100>st1;
////	//按需实例化
////	/*st.f();*/
////
////	return 0;
////}
//
//
////函数模板的特化
////template<class T>
////bool les(T l, T r) {
////	return l < r;
////}
////template<class T>
////bool les(T* l, T* r) {
////	return *l < *r;
////}
////template<class T1,class T2>
////class Date {
////public:
////	Date() { cout << "Date<T1,T2>" << endl; }
////private:
////	T1 _d1;
////	T2 _d2;
////};
//////全特化
////template<>
////class Date<int,double> 
////{
////public:
////	Date() { cout << "Date<int,double>" << endl; }
////private:
////	
////};
//////偏特化
////template<class T1>
////class Date<T1, double>
////{
////public:
////	Date() { cout << "Date<T1,double>" << endl; }
////private:
////
////};
////int main() {
////	/*int a = 1, b = 2;
////	cout << les(a, b) << endl;
////	cout << les(&a, &b) << endl;*/
////	
////
////
////	return 0;
////}
//
//template<class T1, class T2>
//class Date {
//public:
//	Date() { cout << "Date<T1,T2>" << endl; }
//private:
//	T1 _d1;
//	T2 _d2;
//};
////全特化
//template<>
//class Date<int, double>
//{
//public:
//	Date() { cout << "Date<int,double>" << endl; }
//private:
//
//};
////偏特化
//template<class T1>
//class Date<T1, double>
//{
//public:
//	Date() { cout << "Date<T1,double>" << endl; }
//private:
//
//};
//int main() {
//	/*int a = 1, b = 2;
//	cout << les(a, b) << endl;
//	cout << les(&a, &b) << endl;*/
//
//
//
//	return 0;
//}