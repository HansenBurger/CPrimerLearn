#include <iostream>

const int ArSize = 12;

int main(void)
{
    using namespace std;

    const char *month_names[ArSize] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"};
    // string类对象可以直接声明string数组

    int *sales = new int[ArSize];

    cout << "Enter monthly book sales: " << endl;
    for (int i = 0; i < ArSize; i++)
    {
        cout << *(month_names + i) << ": ";
        cin >> sales[i];
    }

    int sum = 0;
    for (int i = 0; i < ArSize; i++)
        sum += sales[i];
    cout << "Total sales for the year: " << sum << endl;

    delete[] sales;

    return 0;
}