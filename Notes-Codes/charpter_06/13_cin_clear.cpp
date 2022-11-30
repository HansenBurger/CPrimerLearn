#include <iostream>

using namespace std;

int main(void)
{
    int num1, num2;
    cout << "First number:";
    cin >> num1;
    /*
    cin出现类型不匹配，cin返回false，并设置一个错误标记
    会直接影响cin来捕获数据，停止运行
    出现错误标记的cin，输入捕获功能就会禁用，cin.get()也失效
    需要复位cin的功能，利用clear()标记
    */
    cin.clear();              // reset input重启功能
    while (cin.get() != '\n') // 消耗错误输入
        ;

    cout << "Last number:";
    cin >> num2;

    cout << "num1: " << num1 << ", num2: " << num2 << endl;

    return 0;
}