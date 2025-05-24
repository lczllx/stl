//#include <iostream>
//using namespace std;
//class Base {
//public:
//    // 虚函数
//    virtual void show() {
//        cout << "Base class show()" << endl;
//    }
//
//    // 非虚函数
//    void display() {
//        cout << "Base class display()" << endl;
//    }
//};
//class Derived : public Base {
//public:
//    // 重写虚函数
//   virtual void show() override {
//        cout << "Derived class show()" << endl;
//    }
//
//    // 隐藏基类的display函数（不是多态）
//    void display() {
//        cout << "Derived class display()" << endl;
//    }
//};
//int main() {
//    Base* basePtr;
//    Derived derivedObj;
//
//    basePtr = &derivedObj;
//
//    // 运行时多态 - 调用Derived的show()
//    basePtr->show();      // 输出: Derived class show()
//
//    // 非虚函数 - 静态绑定，调用Base的display()
//    basePtr->display();   // 输出: Base class display()
//
//    return 0;
//}

#include <iostream>
using namespace std;
class person {
public:
    virtual void show() { cout << "person" << endl; }

private:
    int _a;
};
class student : public person {
public:
    void show() { cout << "student" << endl; }
private:
    int _b;
};
int main() {
    

    return 0;
}