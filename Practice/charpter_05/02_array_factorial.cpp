#include <array>
#include <iostream>

const int ArSize = 500;

int main(void)
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);

    int n;
    cout << "Enter an integer to calculate the factorial: ";
    cin >> n;

    array<long double, ArSize> factorials;

    factorials[0] = factorials[1] = 1;

    for (int i = 2; i < ArSize; i++)
        factorials[i] = i * factorials[i - 1];

    std::cout << n << "! = " << factorials[n] << std::endl;

    return 0;
}