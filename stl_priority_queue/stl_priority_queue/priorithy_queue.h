#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


namespace lcz {
	template<class T>
	struct Less {
		bool operator()(const T& a, const T& b) {
			return a < b;
		}
	};
	template<class T, class Container = vector<T>,class Compare =Less<T>>
	

	class _priority_queue {

	private:
		


		void adjustdown(int parent)
		{

			int child = parent * 2 + 1;
			while (child<_con.size()) {
				if (child+1 < _con.size() && _con[child] < _con[child + 1])
				{
					++child;
				}
				if (_con[child] > _con[parent]) {
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
		void Adjustup(int child) 
		{
			int parent = (child - 1)/2;
			while (child>0) 
			{
				
				if (_con[child] > _con[parent]) {
					swap(_con[child], _con[parent]);
					child = parent;
					int parent = (child - 1)/2;

				}
				else {
					break;
				}
			}
		}
		

	public:
		_priority_queue() = default;

		template<class Inputiterator>

		_priority_queue(Inputiterator first, Inputiterator last)
			: _con(first, last) {
			while (first != last) {
				_con.push_back(*first);
				++first;
			}

			for (int i = (_con.size() - 2) / 2; i >= 0; --i)
			{
				void adjustdown(i);
			 }
		}
		void pop() {
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			adjustdown(0);
		}
		void push(const T& x) {
			_con.push_back(x);
			Adjustup(_con.size()-1);
		}
		size_t size() {
			return _con.size();

		}
		bool empty() {
			return _con.size() == 0;
		}
		const T& top() {
			return _con[0];
		}
	private:
		Container _con;
		Compare _comp;

	};
	void priority_queue_test1() {
		_priority_queue<int>pq;

	}

};