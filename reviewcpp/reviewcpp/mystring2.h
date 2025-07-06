#pragma once
#include<assert.h>
#include<string.h>
#include<iostream>
namespace lcz {
	
	class string {
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
	
		string(const char*str="")
			:_size(strlen(str))
			, _capacity(_size)
			, _str(new char[_capacity+1])
		{
			memcpy(_str, str, _capacity + 1);
		}
		string(const string& str  )
		{
			_str = new char[str._capacity + 1];
			_size = str._size;
			_capacity = str._capacity;
			memcpy(_str, str._str, _capacity + 1);

		}
		~string() {

			delete[]_str;
			_size = _capacity = 0;
		}
		char* c_str() {
			return _str;
		}

		iterator begin() {
			return _str;
		}
		const_iterator begin() const
		{
			return _str;
		}
		iterator end() {
			return _str+_size;

		}
		const_iterator end()const 
		{
			return _str+_size;
		}

		char& operator[](size_t pos) {
			assert(pos < _size);
			return _str[pos];
		}
		const char& operator[](size_t pos) const 
		{
			assert(pos < _size);
			return _str[pos];
		}
		void append(const char* str) {
			size_t len = strlen(str);
			if (len + _size >= _capacity)reserve(len + _size);

			memcpy(_str + _size, str, len + 1);
			_size = _size + len;

		}
		void push_back(char ch) 
		{
			if (_size == _capacity) {
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}
		void insert(size_t pos,char ch) 
		{
			assert(pos <= _size);

		}
		void reserve(size_t n) 
		{
			if (n > _capacity) {
				char* tmp = new char[n + 1];
				memcpy(tmp, _str, _size);
				delete[]_str;
				_str = tmp;
				_capacity = n;

			}
		}
		void resize(size_t n, char ch = '\0') 
		{
			if (n < _capacity) {
				_str[n] = '\0';
				_size = n;
			}
			else {
				reserve(n);
				for (size_t i = _size; i < n; i++)_str[i] = ch;
				_size = n;
				_str[n] = '\0';
			}
		}
		void erase(size_t pos,size_t n=npos)
		{
			assert(pos <= _size);
			if (pos + n < _size && n!=npos) {
				
				size_t end = pos + n;
				while(end<=_size)
				_str[_size++] = _str[end++];

				_size -= n;
			}
			else {
				_str[pos] = '\0';
				_size = pos;
			}
		}
		string& substr(size_t pos = 0, size_t len = npos)
		{
			assert(pos < _size);

			size_t n = (len == npos || pos + len > _size) ? _size - pos : len;
			string tmp;
			tmp.resize(n);  
			memcpy(tmp._str, _str + pos, n);  
			tmp._str[n] = '\0';  
			return tmp;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos <= _size);
			const char* ret = strstr(_str, str);
			if (!ret)return npos;
			else return ret - _str;
		}
		//std::ostream& operator<<(std::ostream& out, string& s);

		void swap(string& str) 
		{
			std::swap(_size, str._size);
			std::swap(_capacity, str._capacity);
			std::swap(_str, str._str);
		}

		void clear() 
		{
			_size = 0;
			_str[_size] = '\0';
		}

		string& operator=(string& str) 
		{

			swap(str);
		
			return *this;
		}
		string& operator+=(const char* str) 
		{
			append(str);
			return *this;
		}

		bool operator==(const string& str)const 
		{
			return _size == str._size && memcmp(_str, str._str, _size)==0;
		}
		bool operator!=(const string& str)const
		{
			return !(*this==str);
		}
		bool operator>=(const string& str)const
		{
			return !(*this < str);
		}
		bool operator<=(const string& str)const
		{
			return !(*this > str);
		}
		bool operator>(const string& str)const
		{
			return !(*this== str)&&!(*this<str);
		}
		bool operator<(const string& str)const 
		{
			bool ret = memcmp(_str, str._str, (_size > str._size) ? str._size : _size);
			return ret == 0 ? (_size < str._size) : ret < 0;
		}
	private:
		size_t _size;
		size_t _capacity;
		char* _str;

	public:
		const static size_t npos;
	};
	const size_t string::npos = -1;

	std::ostream& operator<<(std::ostream& out,const string& s) 
	{
		for (auto e : s) {
			out << e;
		}
		
		return out;
	}
	std::istream& operator>>(std::istream& in, string& s) 
	{
		char ch;
		while(ch=in.get()&&ch==' '||ch=='\n'){}
		char buff[128];
		int i = 0; string str;
		ch = in.get();
		while (ch != ' ' && ch != '\n') {
			buff[i++] = ch;
			if (i == 127) {
				buff[i] = '\0';
				str += buff;
				i = 0;
			}
			ch = in.get();
		}
		if (i) {
			buff[i] = '\0';
			str += buff;

		}

		return in;
	}



};
