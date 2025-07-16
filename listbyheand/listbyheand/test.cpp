#include "list.h"
#include <iostream>

void test_insert() {
    lcz::list<int> lst;
    auto it = lst.begin();
    lst.insert(it, 1); // 插入到空表
    lst.insert(lst.end(), 2); // 插入到尾部
    lst.insert(lst.begin(), 0); // 插入到头部

    std::cout << "test_insert: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_push_pop() {
    lcz::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_front(0);

    std::cout << "test_push: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    lst.pop_back();
    std::cout << "test_pop_back: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    lst.pop_front();
    std::cout << "test_pop_front: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_erase() {
    lcz::list<int> lst;
    for (int i = 0; i < 5; ++i)
        lst.push_back(i);

    auto it = lst.begin();
    ++it; // 指向1
    lst.erase(it);

    std::cout << "test_erase: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_copy_assign() {
    lcz::list<int> lst;
    for (int i = 0; i < 3; ++i)
        lst.push_back(i);

    lcz::list<int> lst2(lst); // 拷贝构造
    lcz::list<int> lst3;
    lst3 = lst2; // 赋值

    std::cout << "test_copy: ";
    for (auto it = lst2.begin(); it != lst2.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;

    std::cout << "test_assign: ";
    for (auto it = lst3.begin(); it != lst3.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void test_clear() {
    lcz::list<int> lst;
    for (int i = 0; i < 3; ++i)
        lst.push_back(i);

    lst.clear();
    std::cout << "test_clear: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << "(应为空)" << std::endl;
}

int main() {
    test_insert();
    test_push_pop();
    test_erase();
    test_copy_assign();
    test_clear();
    return 0;
}