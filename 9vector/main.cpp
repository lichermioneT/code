#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

template<class T>
class vector
{
	using iterator = char*;
	using const_iterator = const char*;
public:
	vector()
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{}

	vector(size_t n, const T& value = T())
		: _start(nullptr)
		, _finish(nullptr)
		, _endOfStorage(nullptr)
	{
		reserve(n);
		while (n > 0)
		{
			push_back(value);
			n--;
		}
	}
	
	vector(const vector<T>& v)
		:_start(nullptr)
		,_finish(nullptr)
		,_endOfStorage(nullptr)
	{
		reserve(v.capacity());
		for (size_t i = 0; i < v.size(); i++)
		{
			*(_start + i) = *(v._start + i);
		}
	}

	vector<T>& operator=(const vector<T> v)
	{
		Swap(v);
		return *this;
	}

	~vector()
	{
		delete[] _start;
		_start = _finish = _endOfStorage = nullptr;
	}
private:
	void Swap(vector<T>& v)
	{
		std::swap(_start, v._start);
		std::swap(_finish, v._finish);
		std::swap(_endOfStorage, v._endOfStorage);
	}
public:
	T& operator[](size_t i)
	{
		assert(i < size());
		return _start[i];
	}

	const T& operator[](size_t i) const 
	{
		assert(i < size());
		return _start[i];
	}
public:
	iterator insert(iterator pos, const T& val)
	{
		if (_finish == _endOfStorage)
		{
			size_t newCapacity = (capacity() == 0 ? 2 : capacity() * 2);
			reserve(newCapacity);
		}

		iterator it = end();
		while (it != pos)
		{
			*it = *(it - 1);
			--it;
		}
		
		*pos = val;
		++_finish;

		return pos;
	}

public:
	void reserve(size_t n)
	{
		if (n > capacity())
		{
			size_t oldsize = size();
			T* tmp = new T[n];

			// 这里只能进行复制的
			for (size_t i = 0; i < oldsize; ++i)
			{
				tmp[i] = _start[i];
			}
			delete[] _start;

			_start = tmp;
			_finish = _start + oldsize;
			_endOfStorage = _start + n;
		}
	}

	void resize(size_t n, const T& val = T())
	{
		if (n < size())
		{
			return;
		}
		else
		{
			if (n > capacity())
			{
				reserve(n);
			}
			while (_finish < _start + n)
			{
				*_finish = val;
				++_finish;
			}
		}
	}

public:
	void push_back(const T& t)
	{
		if (_finish == _endOfStorage)
		{
			size_t newCapacity = (capacity() == 0 ? 2 : capacity() * 2);
			reserve(newCapacity);
		}
		*_finish = t;
		++_finish;
	}

	void pop_back()
	{
		assert(_start < _finish);
		--_finish;
	}

public:

	iterator begin() { return _start; }
	iterator end() { return _start + size(); }
	const_iterator cbegin() const { return _start; }
	const_iterator cend() const { return _start + size(); }


public:
	size_t size() const { return _finish - _start;}
	size_t capacity() const {return _endOfStorage - _start;}
	bool empty() const { return _finish == _finish; }


private:
	T* _start;
	T* _finish;
	T* _endOfStorage;
};

int main()
{
	vector<int> v(10,22);
	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << i << ":" << v[i] << endl;
	}
	cout << endl;

	vector<int> v1;

	return 0;
}