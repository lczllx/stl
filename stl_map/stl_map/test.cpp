#pragma once
#include<iostream>
#include "RBtree.h"
#include "stl_map.h"
//#include "stl_set.h"


using namespace std;
int main() {

	lcz::map<int, int>mp;
	mp.insert({ 1,2 });
	mp.insert({ 12,52 });
	mp.insert({ 61,25 });
	mp.insert({ 41,23 });

	auto it = mp.begin();
	//it->first = 1;
	it->second = 1;

	for (auto e : mp)cout << e.first << " ";
	return 0;
}
