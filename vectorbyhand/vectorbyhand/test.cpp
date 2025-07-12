#include "vector.h"
#include <iostream>

int main() {
    lcz::vector<int> v1; // 默认构造
    std::cout << "初始size: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;

    // push_back 测试
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    std::cout << "插入10个元素后size: " << v1.size() << ", capacity: " << v1.capacity() << std::endl;

    // operator[] 测试
    std::cout << "v1[5] = " << v1[5] << std::endl;

    // erase 测试
    v1.erase(v1.begin() + 5);
    std::cout << "删除第6个元素后v1[5] = " << v1[5] << std::endl;

    // insert 测试
    v1.insert(v1.begin() + 3, 99);
    std::cout << "在第4个位置插入99后v1[3] = " << v1[3] << std::endl;

    // pop_back 测试
    v1.pop_back();
    std::cout << "pop_back后size: " << v1.size() << std::endl;

    // 拷贝构造测试
    lcz::vector<int> v2(v1);
    std::cout << "拷贝构造v2, v2.size: " << v2.size() << std::endl;

    // 赋值测试
    lcz::vector<int> v3;
    v3 = v2;
    std::cout << "赋值v3 = v2, v3.size: " << v3.size() << std::endl;

    // clear 测试
    v3.clear();
    std::cout << "clear后v3.size: " << v3.size() << std::endl;

    // 范围for遍历
    std::cout << "v1内容: ";
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}