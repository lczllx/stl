#pragma once
#include<iostream>
#include<vector>
namespace lcz {
	template<size_t N>
	class bitmap {
	public:
		bitmap()
	    {
			_a.resize(N / 32 + 1);
		}
		void set(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_a[i] |= (1 << j);
		}
		void reset(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			_a[i] &= (~(1 << j));

		}
		bool test(size_t x)
		{
			size_t i = x / 32;
			size_t j = x % 32;
			return _a[i] & (1 << j);
		}

	private:
		std::vector<int>_a;
	};
	template<size_t N>
	class twobitset {
	public:
		void set(size_t x)
		{
			if (!_b1.test(x) && !_b2.test(x))
			{
				_b2.set(x);
			}
			else if (_b1.test(x) && !_b2.test(x))
			{
				_b1.set(x);
				_b2.reset(x);
			}
		}

		bool onceup(size_t x)
		{
			return !_b1.test(x) && _b2.test(x);
		}


	private:
		bitmap<N>_b1;
		bitmap<N>_b2;
	};
}
