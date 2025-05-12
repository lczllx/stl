#pragma once
#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

namespace lcz {
	template <class T, class Container = deque<T> >
	class _queue {

	public:
		
		void push(const T& x)
		{
			_con.push_back(x);
			
		}
		void pop()
		{
			if (_con.size() == 0)return;
			_con.pop_front();
			
		}
		T& top()
		{
			if (_con.size() == 0)throw std::out_of_range("Stack is empty");
			//if (_size == 0)return T();

			return _con.front();
		}
		const T& top()const
		{
			if (_con.size() == 0)throw std::out_of_range("Stack is empty");
			//if (_size == 0)return T();

			return _con.front();
		}

		bool empty() const
		{
			return _con.size() == 0;
		}
		size_t size()
		{
			return _con.size();
		}
		T& back() {
			return _con.back();
		}
		T& back()const {
			return _con.back();
		}
		void swap(_queue& tmp)
		{
			if (this == &tmp)return;
			std::swap(_con, tmp._con);
			//swap(_size, tmp._size);
		}
		void clear()
		{
			_con.clear();
			
		}

	private:
		Container _con;
		
	};

	void queuetest() {
		_queue<int>q;
		q.push(1);
		q.push(2);
		q.push(3);
		q.push(4);
		q.push(51);
		while (q.size()) {
			cout << q.top() << endl;
			q.pop();
		}
		cout << q.size() << endl;


	}


}