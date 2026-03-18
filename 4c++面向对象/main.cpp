#include <iostream>
#include <vector>
using namespace std;

// 1.在谈构造函数
// 引用成员变量
// const成员变量
// 自定义类型成员(该类没有默认构造函数)
// 尽量使用初始化列表：构造函数和拷贝构造

//成员变量在类中声明次序就是其在初始化列表中的初始化顺序，与其在初始化列表中的先后次序无关
//上述代码可读性不是很好，用explicit修饰构造函数，将会禁止单参构造函数的隐式转换。



class A
{
public:
	A(int a)
	 :_a(a)
	{}
private:
	int _a;
};

class B
{
public:
	B(int a, int b, int c)
		:_a(a)
		,_b(b)
		,_c(c)
	{ }

private:
	const int _a;
	int& _b;
	A _c;
};


// 2.static成员
// 1.静态属性属于全部对象，不属于某个具体的对象
// 2.静态成员属性必须在类外面进行初始化
// 3.直接突破类域访问(受访问限定符)
// 4.没有this指针的
// 5.和它函数一样，受访问限定符影响，也有函数的返回值。


class C
{
public:
	C()
	{++a;}

	C(const C& c)
	{++a;}

	static void print()
	{
		cout << " a =  " << a << endl;
	}


private:
	static int a;
};

int C::a = 0;
void test()
{
	B b(1, 3, 3);
	C cnum[1000];
	cnum[0].print();
	C::print();
}

// 3
// C++11支持非静态成员变量在声明时进行初始化赋值，但是要注意这里不是初始化，这里是给声明的成员变量缺省值。

class D
{
private:
	int _a = 100;
	int _b = 100;
	int _c = 100;
};

// 4友元
// 1.友元函数可以访问对象里面的全部属性，不受访问限定符约束。需要在类里面进行声明
// firend 函数声明。
// 
// 友元函数可以访问私有和保护成员，但是不是类的成员函数
// 友元函数不能添加const(例如输出输入)
// 友元函数不受访问限定符约束
// 一个对象可以有多个友元函数
// 

namespace lic
{

#include <vector>
	class A
	{
	public:
		A()
		{
			_a += 1;
			_sum += _a;
		}
	public:
		static int _a;
		static int _sum;
	};
	int A::_a = 0;
	int A::_sum = 0;
	class Solution
	{
	public:
		int Sum_Solution(int n)
		{
			vector<A> arr(n);
			return A::_sum;
		}
	};

	const int accumDays[13] = { 0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

	void test()
	{
		int a, b, c;
		while (cin >> a >> b >> c)
		{ // 注意 while 处理多个 case

			if ((b > 2) && ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)))
			{
				c += 1;
			}

			cout << accumDays[b] + c << endl;
		}
	}

}
int main()
{
	D d;

	return 0;
}