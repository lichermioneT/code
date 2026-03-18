#include <iostream>
using namespace std;

void test1()
{
	// c++关键字后面慢慢熟悉吧，不需要记忆的
}

namespace lic
{
	int a;
	int add(int a, int b)
	{
		return a + b;
	}
}

namespace lic
{
	int sub(int a, int b)
	{
		return a - b;
	}
}

void test2()
{
// 第一种访问方法，突破类域就行了
	lic::a = 100;
	int b = lic::add(1, 3);
	cout << lic::a << endl;
	cout << b << endl;

// using展开一个就行了
	using  lic::add;
	cout << add(100, 33) << endl;

// using  namespace 全部展开
	using namespace lic;
	cout << sub(199, 43) << endl;
}

void test3()
{
	cout << 1 << 1.11 << "asdfdf" << endl;
	int a = 0;
	char ch = 0;
	cin >> a >> ch;
	cout << a << ch << endl;
}

// 缺省参数，也就是默认参数。
// 只能从右往左缺省，只需要声明的时候给就行了。
// 全缺省，半缺省。
void test4(int a = 10, int b = 20, int c = 30)
{
	cout << "a " << a << endl;
	cout << "b " << b << endl;
	cout << "c " << c << endl;
}

// 函数重载，同一个作用域
// 函数参数不同：个数，类型，个数+类型的
// 函数名修饰规则。
//  extern "C"修饰函数  按照c语言的规则编译函数
void test5(int a = 10)
{
	cout << "a " << a << endl;
}
void test5(const string& s, char b = 'd')
{
	cout << "s " << s<< endl;
	cout << "b " << b << endl;
}
void test5(char ch = 'a')
{
	cout << "ch " << ch << endl;
}

// 引用就相当于给一个变量取别名了，
// 1.应用必须初始化
// 2.一个变量多个引用
// 3.引用只能初始化一个实体

// 1.普通引用
// 2.常量引用

// 1.引用做函数参数
// 2.引用做函数返回值

// 指针和引用的区别
// 
void test6()
{
	int a = 10;
	int& b = a;
}

// inline修饰的函数，若编译器执行，则该函数没有地址，不会建立栈帧的。
inline void test7()
{
	cout << "inline" << endl;
}

void test8()
{
	// auto关键字
	int a = 100;
	auto* p1 = &a;
	auto p2 = &a;  // 指针推导的是时候是一样的
	
	//auto推导的时候，一行定义多个变量的类型必须是一样的
	//auto不能再函数的参数
	//auto不能中数组推导类型的
}

void test9()
{
	int a[] = { 1,3,4,4,56,6,7,312 };
	for (auto& e : a)
	{
		cout << e << " ";
	}
	cout << endl;
}

void f(int)
{
	cout << "f(int)" << endl;
}
void f(int*)
{
	cout << "f(int*)" << endl;
}

// nullptr推荐使用
int main()
{
	//test2();
	//test3();
	//test4(1, 2, 3);
	//test4();
	//test5('a');
	//test5("asdffffffffffff");
	//test5(1);


	test9();


	return 0;
}