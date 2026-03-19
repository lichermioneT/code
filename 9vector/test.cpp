#include <iostream>
#include <vector>
using namespace std;

void test1()
{
	vector<int> v;
	vector<int> v1(10, 44);
	vector<int> v2(v1);
	vector<int> v3(v1.begin(), v1.end());

	for (auto& e : v)
	{
		cout << e;
	}
	cout << endl;

	for (auto& e : v1)
	{
		cout << e;
	}
	cout << endl;

	for (auto& e : v2)
	{
		cout << e;
	}
	cout << endl;

	for (auto& e : v3)
	{
		cout << e;
	}
	cout << endl;
}

void print(const vector<int>& v)
{
	vector<int>::const_iterator it = v.cbegin();
	while (it != v.cend())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

void print_reverse(const vector<int>& v)
{
	vector<int>::const_reverse_iterator it = v.crbegin();
	while (it != v.crend())
	{
		cout << *it;
		++it;
	}
	cout << endl;
}

void test2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it;
		++it;
	}
	cout << endl;

	vector<int>::reverse_iterator it2 = v.rbegin();
	while (it2 != v.rend())
	{
		cout << *it2;
		++it2;
	}
	cout << endl;

	print(v);
	print_reverse(v);
}


void test3()
{
	vector<int> v;
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.resize(17, 3);
	cout << v.size() << endl;
	cout << v.capacity() << endl;

	v.reserve(23);
	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

void test4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	for (auto& e : v)
	{
		cout << e;
	}
	cout << endl;
	v.pop_back();
	for (auto& e : v)
	{
		cout << e;
	}
	cout << endl;

	vector<int>::iterator it = find(v.begin(), v.end(), 3);
	if (it != v.end())
	{
		*it = 37;
	}
	for (auto& e : v)
	{
		cout << e << endl;
	}
	cout << endl;

	// insert的返回值，插入成功元素的位置的迭代器
	// pos位置开始往后面移动,insert插入那个位置，就是那个位置的。
	it = v.insert(it, 21);
	for (auto& e : v)
	{
		cout << e;
	}
	cout << endl;

	// erase删除元素，返回值也是迭代器
	// 就是删除元素的下一个位置的迭代器的
	it = v.erase(it);
	for (auto& e : v)
	{
		cout << e;
	}
	cout << endl;
	cout << *it << endl;

	for (size_t i = 0; i < v.size(); ++i)
	{
		cout << v[i];
	}
	cout << endl;

}
