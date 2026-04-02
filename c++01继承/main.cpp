#include <iostream>
#include <string>
using namespace std;

// 1.继承也是代码复用的手段，在基类的基础上进行扩充。
// 继承就是把多个类中的公共成员提取到父类中，让子类直接复用，
// 并在此基础上扩展自己的特有功能。
// public继承：基类的成员属性和成员方法，   不变的
// protected继承：基类的成员属性和成员方法，public变protected
// private继承：基类的成员属性和成员方法，public变private, protected变private
// private不能够被继承下去的。

class Person
{
public:
	void print()
	{
		cout << "Person" << endl;
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
public:
	string _name = "1";
	int _age = 1;
};

class Teacher : public Person
{
public: 
	void print(int a = 100)
	{
		cout << "a = " << a << endl;
		cout << "Person" << endl;
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	}
public:
	int _jobid = 2;
	int _age = 2;
};

void test1()
{
	cout << sizeof(Person) << endl;
	cout << sizeof(Teacher) << endl;
}

// 2.切片和切割
// 派生类 赋值给 基类。
// 对象，指针，引用。
// 基类可以通过强制类型转换赋值给派生类的。可能出现越界的。
// 小心的。


// 3.继承中的作用域的
// 1.基类和派生类的作用域互相独立的
// 2.隐藏和重定义
// 3.函数名一样就构成隐藏
// 派生类对象.基类::属性。
void test2()
{

	Teacher t;
	t.print(44);
	cout << "派生类：" << t._jobid << endl;
	cout << "派生类：" << t._age << endl;

	t.Person::print();
	t.Person::_age = 99;
	cout << t.Person::_age << endl;
}


// 4同样的构造函数也是自己调用自己的，需要显示的调用，如果没有默认的成员函数的。
class A
{
public:
	A()
	{
		cout << "A" << endl;
	}
	
	A(const A& a)
	{
		cout << "A(const A& a)" << endl;
	}

	~A()
	{
		cout << "~A" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B" << endl;
	}

	B(const B& a)
	{
		cout << "B(const A& a)" << endl;
	}

	~B()
	{
		cout << "~B" << endl;
	}

};

// 5友元关系不能够继承下去的。

// 6static成员
// 无论怎么继承，这个类只会存在一个静态的成员。

// 7菱形继承。需要关键virtual登场。
// 虚基表指针
// 通过虚继承下去，对象的成员属性会被放在一个具体的位置，继承的基类会存放的的偏移量的。

// is-a
// has-a

int main()
{


	return 0;
}
