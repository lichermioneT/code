#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

// 1.面向过程函数，面向对象就是类
//C语言是面向过程的，关注的是过程，分析出求解问题的步骤，通过函数调用逐步解决问题。
//C++是基于面向对象的，关注的是对象，将一件事情拆分成不同的对象，靠对象之间的交互完成。

// 2.c++的struct
// c++的struct可以定义变量，可以定义函数的。

struct student
{
	void setInfo(int age, const char* name, const char* gender)
	{
		_age = age;
		strcpy(_name, name);
		strcpy(_gender, gender);
	}

	void print_info()
	{
		cout << _name << " " << _gender << " " << _age << endl;
	}

	int _age;
	char _name[20];
	char _gender[20];
};

void test1()
{
	student s;
	s.setInfo(11, "lic", "nan");
	s.print_info();
}


//3.类的定义

class person
{
public:
	static int a;
	void print();
};

// 外面定义：口诀：头不能丢，突破类域
int person::a = 10;
void person::print()
{
	cout << "声明定义分开" << endl;
}

// 4.访问限定符
// 访问限定符
// 想给你看的：private
// 不想给你看，想继承下去的：protected
// 不想给你看，不想继承下去的：private:
// 面向对象的特性：封装。
// 类天然就是了，想给你看的和继承的就给你，不想给你看和继承的就不给你的

// 5.类的作用域
// 类的函数和静态属性 需要声明和定义分开
// 头不能忘，突破类域的

// 6.类的实例化
// 类的定义，定义了属性和方法
// 需要实例化，就是真正的对象了。

// 7类的大小计算
// 类的函数存放在代码段，只需要计算成员属性就行
// c语言的结构体对其。

// 8.this指针
// 对象的非静态成员函数的一个隐藏参数，
// 谁调用函数，对应的函数就有一个指针指向该对象、
//  * const this. 应该是这样的，this指针不能够修改的

int main()
{
	test1();
	return 0;
}详细帮助总结成.md文件，然后没有总到位的总结一下。谢谢GPT.