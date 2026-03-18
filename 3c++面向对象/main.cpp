#include <iostream>
#include "date.h"

using namespace std;

// 1. 类的六个默认特殊成员函数
// 即使我们什么都不写，编译器也会自动生成默认版本。
class date1
{
};

// 2. 构造函数：用于初始化对象
// 函数名与类名相同，可以重载，创建对象时自动调用且仅调用一次。
// 默认构造函数：编译器生成的无参或全缺省版本（即不需要传参的构造函数）。
class date2
{
public:
    date2(int year, int month, int day)
        : _year(year)
        , _month(month)
        , _day(day)
    {
        cout << "已经初始化了" << endl;   // 现在可以正常显示中文
    }
private:
    int _year;
    int _month;
    int _day;
};

// c++用户自定义了，编译器将不再生成了。请问默认的有什么用呢？
// 它会调用自定义对象的构造函数的。
class A
{
public:
    A(int a = 10)
        :_a(a)
    {
        cout << "A的构造函数" << endl;
    }
private:
    int _a;
};

class B
{

private:
    A _a;
};


// 3.析构函数类似的，我们不写它会默认生成的 ，也会调用自定义类型的析构函数
// 总结：构造函数和析构函数，写了就用自定义的，不写默认生成的会调用自定义类型的。

// 4.拷贝构造
// 拷贝构造，一般类里面存在指针需要自己实现，完成深拷贝。
// 默认的拷贝构造是字节拷贝构造的。


// 5运算符重载


// 6运算符重载

// 7取地址及const取地址操作符重载




int main()
{
    date d1;
    date d2(1, 3, 4);
    d1 = d2;

    date d3(d1);

    return 0;
}