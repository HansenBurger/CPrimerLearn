#include <iostream>

int main(void)
{
    using namespace std;

    double number, sum = 0.0;

    cout << "Calculate five numbers sum and average." << endl;
    cout << "Please enter five values: " << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Value " << i << ": ";
        cin >> number;
        sum += number;
    }

    cout << "The sum = " << sum << endl;
    cout << "The average = " << sum / 5.0 << endl;

    return 0;
}