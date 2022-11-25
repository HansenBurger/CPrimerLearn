#include <iostream>

int main(void)
{
    using namespace std;

    unsigned int v;
    unsigned long sum = 0;

    cout << "Enter the integer and calculate the sum value above all(0 to end):" << endl;

    cin >> v;
    while (v)
    {
        sum += v;
        cout << "Sum: " << sum << endl;
        cin >> v;
    }

    return 0;
}