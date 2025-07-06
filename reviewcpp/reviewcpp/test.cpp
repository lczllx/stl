//#include<iostream>
//#include<string>
//using namespace std;

//不需要建立栈帧，提高调用效率
//复杂，容易出错，可读性差，不能调试
//#define add(x,y) ((x)+(y))

//使用短小，频繁调用的函数
//否则会造成代码膨胀/可执行程序变大
//比较长的函数 递归加inline，会被编译器否决掉
//debug模式下inline不起作用
//inline int Add(int x,int y) {
//	return ((x)+(y));
//}
//
////int main() {
////
////	cout << add(4, 8) << endl;
////	return 0;
////}
//
//int main()  
//{
//
//
//
//	return 0;
//}

//class sum {
//public:
//    sum() {
//        _i++;
//        _ret += _i;
//    }
//    static int getret() {
//        return _ret;
//    }
//private:
//    static int _i;
//    static int _ret;
//};
//int sum::_i = 0;
//int sum::_ret = 0;
//
//
//
//class Solution {
//public:
//    int Sum_Solution(int n) {
//        sum a[n];
//
//        return sum::getret();
//    }
//};

//class A {
//
//
//};


//template<class T>
//T add(T& a, T& b) {
//	return a + b;
//}
//
//int main() {
//	try {
//		int* a = new int(10);//申请一个数组，初始化为10
//
//		int* b = new int[10] {0, 6};//申请一个10个int大小的数组
//		delete a;
//		delete[] b;
//	}
//	catch (const exception&e) {
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

//template<class T,class K>
//T add(T& a, K& b) {
//	return a + b;
//}
//
//int main() {
//	double a =3.6; int b = 98;
//	cout << add(a, b) << endl;
//	return 0;
//}




//int main() {
//	//string s;
//	//string ss = "hello world";
//	//s.insert(0, "sdjijdfsf");
//	//cout << s << endl;
//
//	//s.insert(0, ss,0,11);
//	//cout << s << endl;
//
//	//s.insert(s.begin()+5, 10,'x');
//	//cout << s << endl;
//
//
//	//s.erase(1,5);
//	//cout << s << endl;
//
//
//	//s.erase(1);
//	//cout << s << endl;
//
//	string s;
//	string ss = "hello world";
//	ss += '\0';
//	ss += "skjfsjf";
//	cout << ss << endl;
//	cout << ss.c_str() << endl;
//
//	return 0;
//}

