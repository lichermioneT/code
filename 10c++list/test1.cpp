#include "test1.h"
using namespace std;

void test1()
{
	list<int> lt;
	list<int> lt1(10, 42);
	list<int> lt2(lt1);

	for (auto& e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	list<int>::iterator it = lt2.begin();
	while (it != lt2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int> lt4(lt1.begin(), lt1.end());

	for (auto& e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;
}

void print_c(const list<int>& lt)
{
	list<int>::const_iterator it = lt.cbegin();
	while (it != lt.cend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

void print_cr(const list<int>& lt)
{
	list<int>::const_reverse_iterator it = lt.crbegin();
	while (it != lt.crend())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

void test2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	list<int>::reverse_iterator it1 = lt.rbegin();
	while (it1 != lt.rend())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	print_c(lt);
	print_cr(lt);
}


void test3()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	cout << lt.empty() << endl;
	cout << lt.size() << endl;
}


void test4()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	cout << lt.front() << endl;
	cout << lt.back() << endl;
}

void test5()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	lt.push_front(66);
	lt.push_front(77);
	lt.pop_back();
	lt.pop_front();

	lt.clear();
}










