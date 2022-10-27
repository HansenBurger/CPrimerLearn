#include <iostream>

int main()
{
    using namespace std;

    int updates = 6;
    int *p_updates; // 指针前带有类型代表声明，不取值
    p_updates = &updates;

    cout << "Value: updates = " << updates << endl;
    cout << "Value: p_updates = " << p_updates << endl;

    cout << "Address: updates = " << &updates << endl;
    cout << "*p_updates = " << *p_updates << endl;

    *p_updates = *p_updates + 1;
    cout << "Now Value: updates = " << updates << endl;

    return 0;
}