#include <iostream>
#include <string>
using namespace std;

void test1()
{
	string s;
	string s1("lichermionex");
	string s2(10, 'x');
	string s3(s1);
	cout << s << endl;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
}

void test2()
{
	string s1("lichermionex");
	cout << s1.size() << endl;
	cout << s1.capacity() << endl;
	cout << s1.empty() << endl;

	s1.reserve(100);

	cout << s1.size() << endl;
	cout << s1.capacity() << endl;

	s1.resize(10);

	cout << s1.size() << endl;
	cout << s1.capacity() << endl;


}

void test3()
{
	string s("lichermionex");
	for (auto& e : s)
	{
		cout << e;
	}
	cout << endl;

	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i];
	}
	cout << endl;

	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it;
		++it;
	}
}

void test4()
{
	string s;
	s.push_back('a');
	s.push_back('b');
	s.push_back('c');
	s.append("def");

	s += "ghl";

	const char* p = s.c_str();
	cout << p << endl;


	size_t pos = s.find('d');
	cout << pos << endl;
	pos = s.find("bc");
	cout << pos << endl;

	string s1 = s.substr(2, 4); // ab cdef 起始点然后就是一个步长，返回一个string对象
	cout << s1 << endl;
}


void test5()
{
	string s("lichermionex");
	string s2 = s + "ffffffafsd";
	cout << s2 << endl;

	cin >> s2;
	cout << s2 << endl;

}


