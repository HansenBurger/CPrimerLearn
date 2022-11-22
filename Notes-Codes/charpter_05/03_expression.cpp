#include <iostream>

int main(void)
{
    using namespace std;

    int x;

    cout << "The expression x = 100 has the value ";
    cout << (x = 100) << endl; // <<优先级高于=，需要添加括号，赋值运算的值就是x的值
    cout << "Now x = " << x << endl;

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl; // cout输出bool类型会强制转换为int

    cout.setf(ios_base::boolalpha); // 设置cout输出bool

    cout << "The expression x < 3 has the value ";
    cout << (x < 3) << endl;
    cout << "The expression x > 3 has the value ";
    cout << (x > 3) << endl;

    return 0;
}