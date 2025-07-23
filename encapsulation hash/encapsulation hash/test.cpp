//#include "hashtable.h"
//#include "unordered_map.h"
//#include "unordered_set.h"
//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
////    // 整型测试
////    hash_bucket::hashTable<int, int> h;
////    cout << "整型测试:" << endl;
////    for (int i = 1; i < 15; i++) {
////        h.insert({ i, i * 10 });
////    }
////    for (int i = 1; i < 15; i++) {
////        auto ret = h.find(i);
////        if (ret) {
////            cout << "找到: " << ret->_kv.first << " -> " << ret->_kv.second << endl;
////        }
////    }
////    h.erase(5);
////    if (!h.find(5)) {
////        cout << "删除成功: 5" << endl;
////    }
////
////    // 字符串测试
////    hash_bucket::hashTable<string, int> hs;
////    cout << "\n字符串测试:" << endl;
////    hs.insert({ "apple", 100 });
////    hs.insert({ "banana", 200 });
////    hs.insert({ "orange", 300 });
////    hs.insert({ "pear", 400 });
////
////    string keys[] = { "apple", "banana", "orange", "pear", "peach" };
////    for (const auto& k : keys) {
////        auto ret = hs.find(k);
////        if (ret) {
////            cout << "找到: " << ret->_kv.first << " -> " << ret->_kv.second << endl;
////        }
////        else {
////            cout << "未找到: " << k << endl;
////        }
////    }
////    hs.erase("banana");
////    if (!hs.find("banana")) {
////        cout << "删除成功: banana" << endl;
////    }
//    lcz::unordered_set<int>st;
//    lcz::unordered_map<int,int>mp;
//    for (int i = 1; i <= 11; i++)st.insert(i);
//    for (auto e : st)cout << e << " ";
//    auto it = st.begin();
//    while (it != st.end())
//    {
//        cout << *it << " ";
//        ++it;
//    }
//    return 0;
//}

#include <iostream>
#include <string>
#include "unordered_map.h"
#include "unordered_set.h"

void test_unordered_map() {
    std::cout << "===== Testing unordered_map =====" << std::endl;
    lcz::unordered_map<std::string, int> map;

    // 测试插入
    auto result1 = map.insert({ "apple", 5 });
    std::cout << "Insert apple: " << (result1.second ? "success" : "failed") << std::endl;

    auto result2 = map.insert({ "banana", 3 });
    std::cout << "Insert banana: " << (result2.second ? "success" : "failed") << std::endl;

    // 测试重复插入
    auto result3 = map.insert({ "apple", 10 });
    std::cout << "Insert apple again: " << (result3.second ? "success" : "failed") << std::endl;

    // 测试 operator[]
    map["orange"] = 8;
    map["apple"] = 10;  // 更新已有键

    // 遍历输出
    std::cout << "Map elements: ";
    for (auto& kv : map) {
        std::cout << kv.first << ":" << kv.second << " ";
    }
    std::cout << std::endl;

    // 测试查找
    auto it = map.find("banana");
    if (it != map.end()) {
        std::cout << "Found banana: " << it->second << std::endl;
    }
    else {
        std::cout << "Banana not found" << std::endl;
    }

    // 测试删除
    bool erased = map.erase("banana");
    std::cout << "Erase banana: " << (erased ? "success" : "failed") << std::endl;

    // 再次查找
    it = map.find("banana");
    if (it != map.end()) {
        std::cout << "Found banana after erase: " << it->second << std::endl;
    }
    else {
        std::cout << "Banana not found after erase" << std::endl;
    }

    // 测试 size
    std::cout << "Map size: " << map.size() << std::endl;

    // 测试 operator[] 创建新元素
    std::cout << "Watermelon: " << map["watermelon"] << std::endl;
    std::cout << "Map size after accessing watermelon: " << map.size() << std::endl;
}

void test_unordered_set() {
    std::cout << "\n===== Testing unordered_set =====" << std::endl;
    lcz::unordered_set<std::string> set;

    // 测试插入
    auto result1 = set.insert("apple");
    std::cout << "Insert apple: " << (result1.second ? "success" : "failed") << std::endl;

    auto result2 = set.insert("banana");
    std::cout << "Insert banana: " << (result2.second ? "success" : "failed") << std::endl;

    // 测试重复插入
    auto result3 = set.insert("apple");
    std::cout << "Insert apple again: " << (result3.second ? "success" : "failed") << std::endl;

    // 遍历输出
    std::cout << "Set elements: ";
    for (auto& key : set) {
        std::cout << key << " ";
    }
    std::cout << std::endl;

    // 测试查找
    auto it = set.find("banana");
    if (it != set.end()) {
        std::cout << "Found banana" << std::endl;
    }
    else {
        std::cout << "Banana not found" << std::endl;
    }

    // 测试删除
    bool erased = set.erase("banana");
    std::cout << "Erase banana: " << (erased ? "success" : "failed") << std::endl;

    // 再次查找
    it = set.find("banana");
    if (it != set.end()) {
        std::cout << "Found banana after erase" << std::endl;
    }
    else {
        std::cout << "Banana not found after erase" << std::endl;
    }

    // 测试 size
    std::cout << "Set size: " << set.size() << std::endl;
}

void test_hash_conflict() {
    std::cout << "\n===== Testing Hash Conflict Handling =====" << std::endl;
    lcz::unordered_map<std::string, int> map;

    // 插入可能哈希冲突的元素
    map["abc"] = 1;
    map["acb"] = 2;
    map["bac"] = 3;
    map["bca"] = 4;
    map["cab"] = 5;
    map["cba"] = 6;

    // 遍历输出
    std::cout << "Elements after insertion: ";
    for (auto& kv : map) {
        std::cout << kv.first << ":" << kv.second << " ";
    }
    std::cout << std::endl;

    // 删除部分元素
    map.erase("acb");
    map.erase("bca");

    // 再次遍历输出
    std::cout << "Elements after erasure: ";
    for (auto& kv : map) {
        std::cout << kv.first << ":" << kv.second << " ";
    }
    std::cout << std::endl;

    std::cout << "Final size: " << map.size() << std::endl;
}

int main() {
    test_unordered_map();
    test_unordered_set();
    test_hash_conflict();
    return 0;
}