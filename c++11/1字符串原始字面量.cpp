#include <iostream>
#include <string>

using namespace std;


int main()
{
    
// 1.c++11字符串原始字面量
// 语法就是 R"XXX()XXX""
// 注意xxx前后的必须相等。
// () 括号里面是什么样，就字面输出。
    string path = R"(D:\QQMusicCache\downloadproxyNew\tp_dp_file\0aad0fc360aecd31021005c429332fcd)";
    string path1 = R"xxx(D:\QQMusicCache\downloadproxyNew\tp_dp_file\0aad0fc360aecd31021005c429332fcd)xxx";

    cout<< path <<endl;
    cout<< path1 <<endl;
    return 0;
}