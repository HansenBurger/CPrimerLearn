#include <iostream>

int main(void)
{
    using namespace std;
    int i_start, i_end;

    cout << "Enter two integers and calculate the sum between them: " << endl;
    cout << "Integer 1: ";
    cin >> i_start;
    cout << "Integer 2: ";
    cin >> i_end;

    int sum = 0;
    for (int i = i_start; i <= i_end; i++)
        sum += i;

    cout << "Sum value: " << sum << endl;

    return 0;
}