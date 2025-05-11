#pragma once
#include<iostream>
using namespace std;

namespace lcz {
	template<class iterator,class Ref,class Ptr>
	struct Reverseiterator {
		typedef <class iterator, class Ref, class Ptr>Self;

		iterator _it;

		Reverseiterator(iterator&it):
		,_it(it)
		{}
		Ref operator*(iterator&it) {
			iterator tmp = it;
			return *--tmp;
		}
		Ptr operator->(iterator& it) {
			return &(operator*());

		}
		Self operator++(iterator& it) {
			--it;
			return *this;
		}
		Self operator--(iterator& it) {
			++it;
			return *this;
		}
		Self operator!=(iterator& it) {
			return _it != it;

		}
		Self operator==(iterator& it) {
			return _it == it;
		}
	private:

	};
}