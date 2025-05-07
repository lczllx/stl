#pragma once
#include<iostream>
using namespace std;

namespace lcz {
	template<class iterator, class Ref, class Ptr>
	struct Reverseiterator {
		typedef Reverseiterator<iterator, Ref, Ptr>Self;

		iterator _it;

		Reverseiterator(iterator it)
			: _it(it)
		{
		}
		Ref operator*() {
			iterator tmp = _it;
			return *--tmp;
		}
		Self operator++(int) {
			Self tmp = *this;
			--_it;
			return tmp;
		}

		Self operator--(int) {
			Self tmp = *this;
			++_it;
			return tmp;
		}
		Ptr operator->() {
			return &(operator*());

		}
		Self& operator++() {
			--_it;
			return *this;
		}
		Self& operator--() {
			++_it;
			return *this;
		}
		bool operator!=(const Self& op) {
			return _it != op._it;

		}
		bool operator==(const Self& op) {
			return _it == op._it;
		}


	};

}