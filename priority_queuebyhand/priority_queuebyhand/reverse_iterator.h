#pragma once

namespace lcz {
	template<class iterator,class Ref,class Ptr>
	struct reverse_iterator {
		iterator _it;
		typedef reverse_iterator<iterator, Ref, Ptr> self;
		
		reverse_iterator(iterator it):_it(it){}
		
		Ref operator*()
		{
			iterator tmp = _it;
			return *(--tmp);
		}
		Ptr operator->()
		{
			
			return &(operator*());
		}
		self& operator++() {
			--_it;
			return *this;
		}
		self& operator--()
		{
			++_it;
			return *this;
		}

		bool operator!=(const self&r) {
			return _it != r._it;
		}

	
	};
}