#pragma once
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

namespace lcz {
	template <class T, class Container = vector<T> > 
	class _stack {
		
	public:
		/*_stack()
			:_con()
			, _size(0)
		{}
		_stack(const _stack& tmp) {
			_con = tmp._con;
			_size = tmp._size;
		}*/


		void push(const T& x)
		{
			_con.push_back(x);
			_size++;
		}
		void pop() 
		{
			if (_size ==  0)return;
			_con.pop_back();
			_size--;
		}
		T& top() 
		{
			if (_size == 0)throw std::out_of_range("Stack is empty");
			//if (_size == 0)return T();

			return _con.back();
	    }
		const T& top()const
		{
			if (_size == 0)throw std::out_of_range("Stack is empty");
			//if (_size == 0)return T();

			return _con.back();
		}

		bool empty() const
		{
			return _size == 0;
		}
		size_t size() 
		{
			return _size;
		}
		T& back() {
			return _con.back();
		}
		T& back()const {
			return _con.back();
		}
		void swap(_stack& tmp) 
		{
			if (this == &tmp)return;
			swap(_con, tmp._con);
			swap(_size, tmp._size);
		}
		void clear() 
		{
			_con.clear();
			_size = 0;
		}

	private:
		Container _con;
		size_t _size;
	};

	void stacktest() {
		_stack<int>st;
		st.push(1);
		st.push(2);
		st.push(3);
		st.push(4);
		st.push(51);

		cout << st.top() << endl;
		st.pop();
		cout << st.top() << endl;

	}

	
}