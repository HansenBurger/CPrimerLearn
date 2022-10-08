#include <iostream>

int main(void)
{
    using namespace std;

    float a = 2.34E22;
    float b = a + 1.0;

    cout << "a = " << a << endl;
    cout << "b - a = " << b - a << endl;

    // b-a输出结果为0

    return 0;
}