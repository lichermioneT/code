#include <iostream>
using namespace std;


//1.
// 实现一一个函数，实现交换数据的交换。
// 这类的函数逻辑一样的，函数数据类型不一样的。
template<class T>
void Swap(const T& left, const T& right)
{
	T tmp = left;
	left = right;
	right = tmp;
}
//泛型编程：编写与类型无关的通用代码，是代码复用的一种手段。模板是泛型编程的基础。
// 2.函数模板
// 函数模板操作的数据是泛型的，实例化是根据实际参数 进行实例化出真正的函数。
// 尽量知名函数模板的类型。

int main()
{




	return 0;
}