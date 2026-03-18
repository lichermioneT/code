#include <iostream>
using std::cout;
using std::endl;
using std::swap;

template<class Iterator, class Ref, class Ptr>
struct ReverseIterator
{
	Iterator _it; // 底层正向迭代器

	ReverseIterator(Iterator it)
		: _it(it)
	{}

	Ref operator*()
	{
		Iterator tmp = _it;
		--tmp;           // 先退一个位置，才是真正要访问的元素
		return *tmp;
	}

	Ptr operator->()
	{
		return &(operator*());
	}

	ReverseIterator& operator++()
	{
		--_it;           // 反向迭代器++，底层迭代器要--
		return *this;
	}

	ReverseIterator operator++(int)
	{
		ReverseIterator tmp(*this);
		--_it;
		return tmp;
	}

	ReverseIterator& operator--()
	{
		++_it;           // 反向迭代器--，底层迭代器要++
		return *this;
	}

	ReverseIterator operator--(int)
	{
		ReverseIterator tmp(*this);
		++_it;
		return tmp;
	}

	bool operator!=(const ReverseIterator& rit) const
	{
		return _it != rit._it;
	}

	bool operator==(const ReverseIterator& rit) const
	{
		return _it == rit._it;
	}
};

class string
{
public:
	string(const char* str = nullptr)
		:_str(nullptr)
	{
		if (str == nullptr)
		{
			str = "";
		}

		_size = strlen(str);
		_capacity = _size;
		_str = new char[_capacity + 1];
		std::memcpy(_str, str, _size + 1);
	}
	
	string(const string& s)
	{
		_size = s._size;
		_capacity = s._capacity;
		_str = new char[_capacity + 1];
		std::memcpy(_str, s._str, _size + 1);
	}

	string& operator=(string s)
	{
		Swap(s);
		return *this;
	}

	~string()
	{
		delete[] _str;
		_str = nullptr;
		_size = _capacity = 0;
	}

public:
	using iterator = char*;
	using const_iterator = const char*;
	iterator begin()
	{
		return _str;
	}

	iterator end()
	{
		return _str + _size;
	}

	const_iterator begin() const
	{
		return _str;
	}

	const_iterator end() const 
	{
		return _str + _size;
	}

	using reverse_iterator = ReverseIterator<iterator, char&, char*>;
	using const_reverse_iterator = ReverseIterator<const_iterator, const char&, const char*>;

private:
	void Swap(string& s)
	{
		swap(_size, s._size);
		swap(_capacity, s._capacity);
		swap(_str, s._str);
	}

private:
	char* _str;
	size_t  _size;
	size_t _capacity;
};



int main()
{
	string s("fasdf");
	string s1;

	return 0;
}