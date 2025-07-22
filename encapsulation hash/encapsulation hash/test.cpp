#include "hashtable.h"
#include "unordered_map.h"
#include "unordered_set.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
//    // ÕûĞÍ²âÊÔ
//    hash_bucket::hashTable<int, int> h;
//    cout << "ÕûĞÍ²âÊÔ:" << endl;
//    for (int i = 1; i < 15; i++) {
//        h.insert({ i, i * 10 });
//    }
//    for (int i = 1; i < 15; i++) {
//        auto ret = h.find(i);
//        if (ret) {
//            cout << "ÕÒµ½: " << ret->_kv.first << " -> " << ret->_kv.second << endl;
//        }
//    }
//    h.erase(5);
//    if (!h.find(5)) {
//        cout << "É¾³ı³É¹¦: 5" << endl;
//    }
//
//    // ×Ö·û´®²âÊÔ
//    hash_bucket::hashTable<string, int> hs;
//    cout << "\n×Ö·û´®²âÊÔ:" << endl;
//    hs.insert({ "apple", 100 });
//    hs.insert({ "banana", 200 });
//    hs.insert({ "orange", 300 });
//    hs.insert({ "pear", 400 });
//
//    string keys[] = { "apple", "banana", "orange", "pear", "peach" };
//    for (const auto& k : keys) {
//        auto ret = hs.find(k);
//        if (ret) {
//            cout << "ÕÒµ½: " << ret->_kv.first << " -> " << ret->_kv.second << endl;
//        }
//        else {
//            cout << "Î´ÕÒµ½: " << k << endl;
//        }
//    }
//    hs.erase("banana");
//    if (!hs.find("banana")) {
//        cout << "É¾³ı³É¹¦: banana" << endl;
//    }
    lcz::unordered_set<int>st;
    lcz::unordered_map<int,int>mp;

    return 0;
}