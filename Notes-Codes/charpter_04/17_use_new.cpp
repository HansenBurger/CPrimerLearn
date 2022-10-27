#include <iostream>

int main(void)
{
    using namespace std;

    int nights = 1001;
    int *pt = new int;
    *pt = 1001;

    cout << "nights value = " << nights << " : location = " << &nights << endl;
    cout << "int value = " << *pt << " : location = " << pt << endl;

    double *pd = new double;
    *pd = 1000001.0;

    cout << "double value = " << *pd << " : location = " << pd << endl;

    // 对指针变量取地址则是，存放地址的地址
    cout << "location of pointer pd = " << &pd << endl;

    cout << "size of pt = " << sizeof pt << endl;
    cout << "size of *pt = " << sizeof *pt << endl; // int 内容占用4字节

    cout << "size of pd = " << sizeof pd << endl;   // 指针的类型都占用8个字节
    cout << "size of *pd = " << sizeof *pd << endl; // doubel 内容占用8字节

    return 0;
}