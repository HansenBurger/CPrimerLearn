// const int * pt;  == int const * pt;
// int * const pt; 区别主要在于const和 *之间的相对位置
// const int * const pt;

#include <iostream>

using namespace std;

int main(void)
{
    int n = 10;
    // int m = 100;
    int *const pt = &n;

    cout << "1) n = " << n << endl;
    *pt = 20; // 此时可以通过指针修改原内容
    cout << "2) n = " << n << endl;

    // pt = &m; // pt指针只读，可以通过指针修改内容，但是不能修改指向对象
    cout << "3) *pt = " << *pt << endl;
    return 0;
}
