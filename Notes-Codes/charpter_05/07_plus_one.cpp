#include <iostream>

int main(void)
{
    using namespace std;

    int a = 20, b = 20;

    cout << "a: " << a << ", b: " << b << endl;
    cout << "a++: " << a++ << ", ++b: " << ++b << endl;
    cout << "now a: " << a << ", b: " << b << endl;

    return 0;
}