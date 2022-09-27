#include <iostream>

void simon(int n); // 函数的原型

int main(void)
{
    using namespace std;
    cout << "Pick an interger: ";
    int count;
    cin >> count;
    simon(count); // 函数的调用
    cout << "Done !";
    return 0; // main函数的返回值是返回给操作系统
}

void simon(int n) // 函数的定义
{
    using namespace std;

    cout << "Simon says touch your toes " << n << " times." << endl;
}