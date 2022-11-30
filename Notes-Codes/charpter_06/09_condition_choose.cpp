#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c; // c为a和b中较大的那个

    cout << "Enter two integers: ";
    cin >> a >> b;

    c = a > b ? a : b;

    cout << "The larger of " << a << " and " << b << " is " << c << endl;

    return 0;
}