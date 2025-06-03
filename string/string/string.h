#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<iostream>
#include<assert.h>
using namespace std;
namespace bbt {
	class string {
	public:
		/*typedef const char* const_iterator;
		const_iterator begin() {
			return _str;
		}
		const_iterator end() {
			return _str + _size;
		}*/
		typedef char* iterator;
		iterator begin() {
			return _str;
		}
		iterator end() {
			return _str + _size;
		}
		string(const char* str = "")

		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);

		}
		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos)const {
			assert(pos < _size);
			return _str[pos];
		}
		/*string()
			:_size(0)
			,_capacity(0)
			,_str(new char[1])
		{
			_str = '\0';
		}
		string(const char* str)
			:_size(strlen(str))
		{
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}*/

		~string() {
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
		}

		const char* c_str()
		{
			return _str;
		}
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';

		}
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		/*void erase(size_t pos,size_t len=nops)
		{

		}*/
		void insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);

			}
			size_t end = _size;
			while (end >= pos && end != npos)
			{
				_str[end + len] = _str[end];
				--end;
			}
			for (size_t i = 0; i < len; i++)
			{
				_str[pos + i] = str[i];

			}
			_size += len;
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;

		const static size_t npos;
	};
	const size_t string::npos = -1;
};

#pragma once
