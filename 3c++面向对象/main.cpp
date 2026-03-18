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

void Test1()
{
    cout << "========== Test1: 构造和打印 ==========" << endl;
    date d1(2024, 3, 18);
    d1.print();

    date d2(2024, 2, 29);   // 闰年合法
    d2.print();

    // date d3(2023, 2, 29); // 非法日期，打开这行可以测试构造失败
}

void Test2()
{
    cout << "========== Test2: 加天数 ==========" << endl;
    date d1(2024, 3, 18);

    date d2 = d1 + 20;
    d2.print();   // 2024-4-7

    d1 += 365;
    d1.print();
}

void Test3()
{
    cout << "========== Test3: 减天数 ==========" << endl;
    date d1(2024, 3, 1);

    date d2 = d1 - 1;
    d2.print();   // 2024-2-29

    d1 -= 31;
    d1.print();
}

void Test4()
{
    cout << "========== Test4: 前置/后置 ++ -- ==========" << endl;
    date d1(2024, 12, 31);

    cout << "原值: ";
    d1.print();

    cout << "前置++: ";
    (++d1).print();   // 2025-1-1

    cout << "后置++返回旧值: ";
    (d1++).print();   // 2025-1-1

    cout << "自增后当前值: ";
    d1.print();       // 2025-1-2

    cout << "前置--: ";
    (--d1).print();   // 2025-1-1

    cout << "后置--返回旧值: ";
    (d1--).print();   // 2025-1-1

    cout << "自减后当前值: ";
    d1.print();       // 2024-12-31
}

void Test5()
{
    cout << "========== Test5: 日期比较 ==========" << endl;
    date d1(2024, 3, 18);
    date d2(2024, 3, 20);

    cout << (d1 < d2) << endl;   // 1
    cout << (d1 > d2) << endl;   // 0
    cout << (d1 == d2) << endl;  // 0
    cout << (d1 != d2) << endl;  // 1
}

void Test6()
{
    cout << "========== Test6: 两个日期相减 ==========" << endl;
    date d1(2024, 3, 18);
    date d2(2024, 3, 20);
    date d3(2025, 3, 18);

    cout << "d2 - d1 = " << d2 - d1 << endl; // 2
    cout << "d1 - d2 = " << d1 - d2 << endl; // -2
    cout << "d3 - d1 = " << d3 - d1 << endl; // 366，2024是闰年
}


int main()
{
    Test1();
    cout << endl;

    Test2();
    cout << endl;

    Test3();
    cout << endl;

    Test4();
    cout << endl;

    Test5();
    cout << endl;

    Test6();
    cout << endl;

    return 0;
}