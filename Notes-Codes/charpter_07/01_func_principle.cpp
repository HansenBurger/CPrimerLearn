#include <iostream>

using namespace std;

void simple(void); // 2.函数的原型
// main 函数置顶便于检查
int main(void)
{
    cout << "main() will call the simple function: " << endl;
    simple(); // 3. 函数的调用
    return 0;
}

void simple(void) // 1. 函数的定义
{
    cout << "I'm but a simple function." << endl;
}
