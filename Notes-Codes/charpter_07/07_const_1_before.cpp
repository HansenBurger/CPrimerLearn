// const int * pt;
// int * const pt;
// const int * const pt;

#include <iostream>

using namespace std;

int main(void)
{
    int n = 10, m = 100;
    int *pt = &n;

    cout << "1) n = " << n << endl;
    *pt = 20; // 通过指针修改原内容
    cout << "2) *pt = " << n << endl;

    const int *pt_ = &n;
    // *pt_ = 30; const //不能通过指针修改指向的内容，但本身指向对象可以转变
    pt_ = &m;
    cout << "3) *pt_ = " << *pt_ << endl;
    return 0;
}
