#include <iostream>
#include <vector>
#include <array>

int main(void)
{
    using namespace std;

    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    vector<double> a2(4);
    a2[0] = 1.0 / 3.0;
    a2[1] = 1.0 / 5.0;
    a2[2] = 1.0 / 7.0;
    a2[3] = 1.0 / 9.0;

    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;

    // 模板类之间可以直接传递，拷贝属于深拷贝，地址不带走
    a4 = a3;

    cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
    // vector 的地址在内存的堆，其他为栈
    cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    // 代表元素从数组a1[0]向前查找，已经越界(编译器不检查)
    a1[-2] = 20.2;
    cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
    cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
    cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

    // at可以检查是否超出索引范围
    // cout << a3.at(-1) << endl;

    return 0;
}