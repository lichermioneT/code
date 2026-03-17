#include <iostream>
using namespace std;

//template <class T1, class T2>
//struct pair
//{
//	typedef T1 first_type;
//	typedef T2 second_type;
//	T1 first;
//	T2 second;
//	pair() : first(T1()), second(T2())
//	{
//	}
//
//	pair(const T1& a, const T2& b) : first(a), second(b)
//	{
//	}
//};

//  pair键值对，一个结构体两个构造函数
//  1.不传数据，就是该类型默认的无参构造函数
//  2.传入数据，就是传入的数据进行构造了。

// make_pair()是函数的，返回一个pair的
int main()
{
	pair<int, int> v(1, 3);
	pair<int, int> v1;
	pair<string, string> v2;
	cout << v.first << endl;
	cout << v.second << endl;
	cout << v1.first << endl;
	cout << v1.second << endl;
	cout << v2.first << endl;
	cout << v2.second << endl;

	auto p = make_pair(3,5);
	cout << p.first << endl;
	cout << p.second << endl;

	return 0;
}