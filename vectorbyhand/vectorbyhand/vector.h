#pragma once
#include<iostream>
#include<assert.h>
namespace lcz {
	template<class T>
	class vector {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin() 
		{
			return _start;
		}
		iterator end() 
		{
			return _finish;
		}
		const_iterator begin() const
		{
			return _start;
		}
		const_iterator end() const
		{
			return _finish;
		}
		
		//初始化
		vector(int n, const T& val = T()) {
			resize(n, val);
		}
		vector(std::initializer_list<T> lt) {
			reserve(lt.size());
			for (auto e : lt) {
				push_back(e);
			}
		}
		vector(size_t n,const T&val=T()){
			resize(n, val);
		}
		template<class inputiterator>
		 vector(inputiterator first, inputiterator last) {
			while (first != last) {
				push_back(*first);
				++first;
			}
		}
		 vector(const vector<T>& vct){
			 _start = new T[vct.capacity()];
			 for (int i = 0; i < vct.size(); i++) {
				 _start[i] = vct._start[i];
			 }
			 _finish = _start + vct.size();
			 _end_of_storage = _start + vct.capacity();
		 }
		 vector(){}
		~vector() {
			if (_start) {
				delete[]_start;
				_start = _finish = _end_of_storage = nullptr;
			}
		}

		T& operator[](size_t pos) 
		{
			assert(pos <size());
			return _start[pos];
		}
		const T& operator[](size_t pos) const 
		{
			assert(pos < size());
			return _start[pos];
		}

		vector<T>& operator=(vector<T> vct)
		{
			swap(vct);
			return *this;
		}
		void reserve(size_t n) {
			if (n > capacity()) {
				size_t len = _finish - _start;
				T* tmp = new T[n];
				if (_start) {
					for (size_t i = 0; i < len; i++) {
						tmp[i] = _start[i];
					}
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + len;
				_end_of_storage = _start + n;
			}
		}
		void resize(size_t n,const T&val=T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				reserve(n);

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}
		void push_back(const T&x)
		{
			insert(end(), x);
		}
		void pop_back()
		{
			iterator it = end();
			erase(--it);
		}
		iterator insert(iterator pos,const T&x) 
		{
			assert(pos <= _finish && pos >= _start);
				if (_finish == _end_of_storage)
				{
					size_t len = pos - _start;

					size_t newcapacity = capacity() == 0 ? 4 : capacity() * 2;
					reserve(newcapacity);

					// 解决pos迭代器失效问题
					pos = _start + len;
				}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = x;
			++_finish;

			return pos;

		}

		iterator erase(iterator pos){
			assert(pos >= _start && pos < _finish);

			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				++it;
			}

			--_finish;

			return pos;
		}
		void swap(vector<T>& vct) 
		{
			std::swap(_start, vct._start);
			std::swap(_finish, vct._finish);
			std::swap(_end_of_storage, vct._end_of_storage);
		}

		size_t size() const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _end_of_storage - _start;
		}
		bool empty() const 
		{
			return _start == _finish;
		}
		void clear() 
		{
			_finish = _start;
		}

	private:
		iterator _start = nullptr;       // 数据块起始位置
		iterator _finish = nullptr;      // 有效数据末尾的下一位
		iterator _end_of_storage = nullptr;  // 内存块末尾的下一位
	};



}