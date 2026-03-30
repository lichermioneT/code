#include <iostream>
#include <string>

using namespace std;


int main()
{
    
    cout << "sizeof(long):" <<sizeof(long) <<endl;
    cout << "sizeof(long long):" << sizeof(long long) <<endl;

    // long num1 = 100L;

    // long long int
    // signed long long
    long long num2 = 100LL;

    // unsigned long long int
    unsigned long long num4 = 100ULL;

// long long至少是8字节的。
// 三个宏值
    cout<< "long long max:" << LLONG_MAX <<endl;
    cout<< "long long min:" << LLONG_MIN <<endl;
    cout<< "unsigned long long max:" << ULLONG_MAX <<endl;

// 整形的隐式类型转换的


    return 0;
}