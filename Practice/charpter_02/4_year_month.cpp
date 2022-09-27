#include <iostream>

int YearToMonth(int);

int main(void)
{
    using namespace std;
    int year;
    cout << "Enter your age: ";
    cin >> year;

    int month = YearToMonth(year);
    cout << year << " Yr = ";
    cout << month << " M." << endl;
    return 0;
}

int YearToMonth(int year)
{
    return 12 * year;
}