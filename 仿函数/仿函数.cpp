#include <iostream>
using namespace std;

class add
{
public:
	int a = 0;
	int operator()(int x)
	{
		return a += x;
	}
};
void test1()
{
	add a;
	a(99);
	a(99);
	a(1);
	a(1);

	cout << a.a << endl;
	cout << add()(999) << endl;
}

template<class T>
class Add
{
public:
	T operator()(const T& a, const T& b)
	{
		return a + b;
	}
};


int main()
{
	cout << Add<int>()(44, 99) << endl;
	Add<double> d;
	cout << d(33.4, 44.7) << endl;

// double不需要添加任何东西
// floate添加:f
// long double添加：L
	return 0;
}