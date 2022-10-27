#include <iostream>

int main(void)
{
    using namespace std;

    int donuts = 6;
    double cups = 4.5;

    cout << "donuts value = " << donuts << ", address = " << &donuts << endl;
    cout << "cups value = " << cups << ", address = " << &cups << endl;

    // 地址的显示和计算机的位数有关
    // 两个连续变量之间间距，主要是由类型的大小决定的(double 4个字节)

    return 0;
}