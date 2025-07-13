#pragma once
#include<vector>
#include "reverse_iterator.h"
namespace lcz {
	//仿函数
	template<class T>
	struct Less {
		bool operator()(const T& o, const T& p) {
			return o < p;
		}
	};
	template<class T>
	struct Greater {
		bool operator()(const T& o, const T& p) {
			return o > p;
		}
	};

	template<class T,class Container=std::vector<T>,class Compare=Less<T>>
	class priority_queue {
		void adjustdown(size_t parent)
		{

			size_t  child = parent * 2+1;
			while (child < _con.size()) {
				if (child +1< _con.size() && _cmp(_con[child],_con[child + 1]))++child;
				if (_cmp(_con[parent], _con[child])) {
					std::swap(_con[parent], _con[child]);
					parent = child;
					child = parent * 2 + 1;
				}
				else {
					break;
				}
			}
		}
		void updown(size_t child)
		{

			size_t  parent = (child-1)/2;
			while (child>0) {
				
				if (_cmp(_con[parent], _con[child])) {
					std::swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else break;
			}
		}
	public:
		priority_queue(){}
		//区间构造+向下调整

		template<class Inputiterator>
		priority_queue(Inputiterator first, Inputiterator last)
			:_con(first,last)
		{
			if (_con.empty()) return;  // 添加空容器检查
			/*while (first != last) {
				_con.push_back(*first);
				++first;
			}*/
			//减一不能达到效果，不是父亲的位置
			for (size_t i = (_con.size() - 2) / 2; i >= 0; i--)
			{
				adjustdown(i);
			}
		}
	/*	1
	2      3
4     5   6   7*/

		void push(const T& val)
		{
			_con.push_back(val);
			updown(_con.size()-1);
		}
		void pop()
		{
			//if (empty()) throw std::out_of_range("Heap is empty"); // 或断言
			std::swap(_con[0], _con[size() - 1]);
			_con.pop_back();
				adjustdown(0);
		}
		const T& top() {
			//if (empty()) throw std::out_of_range("Heap is empty");
			return _con[0];
		}
		size_t size() {
			return _con.size();
		}
		bool empty() {
			return _con.empty();
		}

		typedef typename Container::iterator iterator;
		typedef typename Container::reverse_iterator std_reverse_iterator;
		typedef lcz::reverse_iterator<iterator, T&, T*> reverse_iterator;

		// 反向迭代器接口
		reverse_iterator rbegin() {
			return reverse_iterator(_con.end());
		}
		reverse_iterator rend() {
			return reverse_iterator(_con.begin());
		}
	private:
		Container _con;
		Compare _cmp;
	};



}