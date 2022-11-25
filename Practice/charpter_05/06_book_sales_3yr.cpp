#include <iostream>

const int MtSize = 12;
const int YrSize = 3;

int main(void)
{
    using namespace std;

    const char *month_names[MtSize] = {
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

    int sales[YrSize][MtSize];

    for (int y = 0; y < YrSize; y++)
    {
        cout << "Enter " << y + 1 << "'s monthly book sales: " << endl;
        for (int m = 0; m < MtSize; m++)
        {
            cout << *(month_names + m) << ": ";
            cin >> sales[y][m];
        }
    }

    int sum = 0;
    for (int y = 0; y < YrSize; y++)
        for (int m = 0; m < MtSize; m++)
            sum += sales[y][m];

    cout << "Total sales for" << YrSize << " year: " << sum << endl;

    return 0;
}