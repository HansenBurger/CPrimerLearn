#include <iostream>
#include <climits>

bool is_int(double);

int main(void)
{
    using namespace std;

    // int number; 如果超过int范围，可能存储过程中截取，变为有效
    double number; // 通过double获得更广的取值范围

    cout << "Enter an integer value: ";
    cin >> number;

    while (!is_int(number))
    {
        cout << "Out of range, please enter again: ";
        cin >> number;
    }

    int value = (int)number;
    cout << "You've entered an integer: " << value << endl;

    return 0;
}

bool is_int(double value)
{
    if (value <= INT_MAX && value >= INT_MIN)
        return true;
    else
        return false;
}