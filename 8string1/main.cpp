#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
using std::swap;

template<class Iterator, class Ref, class Ptr>
struct StringIterator
{
	Iterator _it;

	StringIterator(Iterator it)
		: _it(it)
	{
	}

	Ref operator*()
	{
		return *_it;
	}

	Ptr operator->()
	{
		return &(*_it);
	}

	StringIterator& operator++()
	{
		++_it;
		return *this;
	}

	StringIterator operator++(int)
	{
		StringIterator tmp(*this);
		++_it;
		return tmp;
	}

	StringIterator& operator--()
	{
		--_it;
		return *this;
	}

	StringIterator operator--(int)
	{
		StringIterator tmp(*this);
		--_it;
		return tmp;
	}

	bool operator!=(const StringIterator& s) const
	{
		return _it != s._it;
	}

	bool operator==(const StringIterator& s) const
	{
		return _it == s._it;
	}
};

template<class Iterator, class Ref, class Ptr>
struct ReverseIterator
{
	Iterator _it;

	ReverseIterator(Iterator it)
		: _it(it)
	{
	}

	Ref operator*()
	{
		Iterator tmp = _it; // 因为传入的是v.end();
		--tmp;
		return *tmp;
	}

	Ptr operator->()
	{
		return &(operator*());
	}

	ReverseIterator& operator++()
	{
		--_it;
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
		++_it;
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
	typedef StringIterator<char*, char&, char*> iterator;
	typedef StringIterator<const char*, const char&, const char*> const_iterator;

	typedef ReverseIterator<iterator, char&, char*> reverse_iterator;
	typedef ReverseIterator<const_iterator, const char&, const char*> const_reverse_iterator;

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
private:
	void Swap(string& s)
	{
		swap(_size, s._size);
		swap(_capacity, s._capacity);
		swap(_str, s._str);
	}

public:
	iterator begin()
	{
		return iterator(_str);
	}

	iterator end()
	{
		return iterator(_str + _size);
	}

	const_iterator begin() const
	{
		return const_iterator(_str);
	}

	const_iterator end() const
	{
		return const_iterator(_str + _size);
	}

	reverse_iterator rbegin()
	{
		return reverse_iterator(end());
	}

	reverse_iterator rend()
	{
		return reverse_iterator(begin());
	}

	const_reverse_iterator rbegin() const
	{
		return const_reverse_iterator(end());
	}

	const_reverse_iterator rend() const
	{
		return const_reverse_iterator(begin());
	}

public:
	char& operator[](size_t i)
	{
		assert(i < _size);
		return _str[i];
	}

	const char& operator[](size_t i) const
	{
		assert(i < _size);
		return _str[i];
	}

public:
	size_t size() const
	{
		return _size;
	}

	size_t capacity() const
	{
		return _capacity;
	}

	bool empty() const
	{
		return _size == 0;
	}

	const char* c_str() const
	{
		return _str;
	}

public:
	void clear()
	{
		_size = 0;
		_str[_size] = '\0';
	}

	void reserve(size_t n)
	{
		if (n <= _capacity)
		{
			return;
		}

		char* newStr = new char[n + 1];
		memcpy(newStr, _str, _size + 1);

		delete[] _str;
		_str = newStr;
		_capacity = n;
	}

	void resize(size_t n, char ch = '\0')
	{
		if (n < _size)
		{
			_size = n;
			_str[_size] = '\0';
			return ;
		}

		if (n > _capacity)
		{
			reserve(n);
			for (size_t i = _size; i < n; i++)
			{
				_str[i] = ch;
			}
		}

		_size = n;
		_str[_size] = '\0';
	}

public:
	void push_back(char ch)
	{
		if (_size == _capacity)
		{
			size_t newCapacity = (_capacity == 0 ? 4 : _capacity * 2);
			reserve(newCapacity);
		}

		_str[_size++] = ch;
		_str[_size] = '\0';
	}

	void append(const char* str)
	{
		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}
		
		memcpy(_str + _size, str, len + 1); // 
		_size += len;
	}

	string& operator+=(char ch)
	{
		this->push_back(ch);
		return *this;
	}

	string& operator+=(const char* str)
	{
		this->append(str);
		return *this;
	}

public:
	string& insert(size_t pos, char ch)
	{
		assert(pos <= _size);
		if (_size == _capacity)
		{
			size_t newCapacity = (_capacity == 0 ? 2 : _capacity * 2);
			reserve(newCapacity);
		}

		memmove(_str + pos + 1, _str + pos, _size - pos + 1);
		_str[pos] = ch;
		++_size;
	}	
	
	string& insert(size_t pos, const char* str)
	{
		assert(pos <= _size);
		assert(str);

		size_t len = strlen(str);
		if (_size + len > _capacity)
		{
			reserve(_size + len);
		}

		memmove(_str + pos + len, _str + pos, _size - pos + 1);

		memcpy(_str + pos, str, len);
		_size += len;

		return *this;
	}

public:
	bool operator<(const  string& other) const
	{
		return std::strcmp(_str, other._str) < 0;
	}

	bool operator==(const  string& other) const
	{
		return std::strcmp(_str, other._str) == 0;
	}

	bool operator!=(const  string& other) const
	{
		return !(*this == other);
	}

	bool operator<=(const  string& other) const
	{
		return *this < other || *this == other;
	}

	bool operator>(const  string& other) const
	{
		return !(*this <= other);
	}

	bool operator>=(const string& other) const
	{
		return !(*this < other);
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
	string s2(s);
	string::iterator it = s.begin();
	while(it != s.end())
	{
		cout << *it;
		++it;
	}

	return 0;
}