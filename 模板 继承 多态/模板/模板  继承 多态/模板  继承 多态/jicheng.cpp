//#include<iostream>
//using namespace std;
////class Animal {
////public:
////    void eat() {
////        cout << "I can eat!" << endl;
////    }
////private:
////    int age;
////    double weight;
////    char name[20];
////};
////
////class Dog : public Animal {  // Dog 继承 Animal
////public:
////    void bark() {
////        cout << "I can bark! Woof woof!" << endl;
////    }
////};
////class cat : public Animal {  // cat 继承 Animal
////public:
////    void bark() {
////        cout << "I can miao! miao miao!" << endl;
////    }
////};
////int main() {
////    //Dog dog;
////    //dog.eat();   // 继承自 Animal
////    //dog.bark();  // Dog 自己的方法
////
////    int i = 0;
////    //double& a = i;产生了临时变量
////    Animal p;
////    Dog s;
////
////    return 0;
////}
////两个print函数构成 隐藏/重定义 关系/\重载需要在同一个作用域
////父子类域中有同名函数构成隐藏
////不要在继承体系中定义同名成员
////class person {
////public:
////
////	void print() {
////		cout << _name << endl;
////		cout << _num << endl;
////	}
////protected:
////	string _name = "lisi";
////	int _num = 11;
////};
////class student:public person
////{
////public:
////	void print(int i) {
////		cout << _name << endl;
////		cout << _num << endl;
////	}
////protected:
////	
////	int _num = 9;
////};
////int main() {
////
////	student d;
////	d.person::print();
////	d.print(1);
////	return 0;
////}
//
////class person {
////public:
////	//先父后子
////	person(const char* name="lisu")
////		:_name(name)
////	
////	{}
////	person(const person&p)
////		:_name(p._name)
////	{
////		cout << "person(const person&p)" << endl;
////	}
////	~person() {
////		cout << "~person" << endl;
////	}
////protected:
////	string _name ;
////	
////};
////class student :public person
////{
////public:
////	student(const char* name = "lisang", int num = 1)
////		:person(name)
////		,_num(num)
////	{}
////	student(const student&s)//调用父类的拷贝构造
////		:person(s)//不加这个会调用父类的默认构造函数
////		,_num(s._num)
////	{}
////	~student() {
////		//被处理了，统一处理成了destructor
////		//显示调用父类析构函数，无法保证先子后父
////		// 所以子类析构函数调用完成后，自动调用父类的析构函数
////		// 
////		//person::person();
////		delete ptr;
////	}
////protected:
////
////	int _num = 9;
////	int* ptr = new int;
////};
////int main() {
////
////	student d;
////	student dd(d);
////
////	return 0;
////}
//
//class A {
//public:
//
//	int _a;
//};
//class B :virtual public A {
//public:
//
//	int  _b;
//};
//class C :virtual public A {
//public:
//
//	int _c;
//};
//class D :public B, public C
//{
//public:
//	int _d;
//};
//int main() {
//
//	D d;
//	d.B::_a = 1;
//	d.C:: _a =44;
//	d._b = 2;
//	d._c = 3;
//	d._d = 4;
//	d._a = 44;
//
//	return 0;
//}