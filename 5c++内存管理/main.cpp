#include <iostream>
#include <cstdlib>
using namespace std;

class A
{
public:
	A(int a)
		:_a(a)
	{
		cout << "A的构造函树" << endl;
	}
	~A()
	{
		cout << "A的析构函数" << endl;
	}
private:
	int _a;
};

// 1.c/c++内存布局
// 1.内核区域，用户代码无法进行访问的
// 2.栈区：建立函数栈帧的地方，非静态局部变量，函数返回值，函数参数。栈向下增长的
// 3.内存映射段(进程间通信) 需要复习linux
// 4.堆区：程序员自己维护的，动态开辟的。
// 6.数据段：全局变量和静态数据
// 7.代码段：可执行代码，只读常量。

// 2.c语言管理内存的方式
void test1()
{
	int* p1 = (int*)malloc(sizeof(int) * 100);
	int* p2 = (int*)calloc(100, sizeof(int));
	int* p3 = (int*)realloc(p1, 120*sizeof(int));
	free(p2);
	free(p3);
}

// 3.c++内存管理方式
void test2()
{
	int* p1 = new int;
	int* p2 = new int();
	int* p3 = new int(3);
	int* p4 = new int[10];
	cout << "*p2:" << *p2 << endl;
	delete p1;
	delete p2;
	delete p3;
	delete[] p4;
}

void test3()
{
	A* p = (A*)malloc(sizeof(A));
}

int main()
{
	test3();



	return 0;
}