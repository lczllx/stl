#include<iostream>
using namespace std;


//double Division(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
// //可以抛出string类型，返回的是拷贝，捕获完成后才销毁
//		throw "Division by zero condition!";//可以throw多个，但无意义
//	else
//		return ((double)a / (double)b);
//}
//void Func()
//{
//	int len, time;
//	cin >> len >> time;
//	cout << Division(len, time) << endl;
//}
//int main()
//{
//	try {
//		Func();
//	}
//	catch (const char* errmsg)//如果有多个匹配的，就选最近的那个
//	{
//	cout << errmsg << endl;
//	}
//	catch (...)
// {
//		cout << "unkown exception" << endl;
//	}
//		cout << "jsijfd" << endl;
//	return 0;
//}

double Division(int a, int b)
{
	// 当b == 0时抛出异常
	if (b == 0)
	{
		throw "Division by zero condition!";
	}
	return (double)a / (double)b;
}
void Func()
{
	// 这里可以看到如果发生除0错误抛出异常，另外下面的array没有得到释放。
	// 所以这里捕获异常后并不处理异常，异常还是交给外面处理，这里捕获了再
	// 重新抛出去。
	int* array = new int[10];
	try {
		int len, time;
		cin >> len >> time;
		cout << Division(len, time) << endl;
	}
	catch (...)
	{
		cout << "delete []" << array << endl;
		delete[] array;
		throw;
	}
	// ...
	cout << "delete []" << array << endl;
	delete[] array;
}
int main()
{
	try
	{
		Func();
	}
	catch (const char* errmsg)
	{
		cout << errmsg << endl;
	}
	return 0;
}