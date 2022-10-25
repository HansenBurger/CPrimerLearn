#include <iostream>

using namespace std;

union one2all
{
    char ch;
    int n;
};

int main(void)
{
    one2all num;

    cout << "Size of num: " << sizeof num << endl;

    num.ch = 'A';

    // 相当于可以访问同一个变量的不同形式，只要赋值一次，其余的成员变量就会有值

    cout << "num.ch = " << num.ch << endl;
    cout << "num.n = " << num.n << endl;
}