#include <iostream>

int main(void)
{
    using namespace std;
    const double mi_per_100km = 62.14;
    const double l_per_gallon = 3.875;

    double euro_unit;
    cout << "Enter the fuel consumption of your car (L/100km): ";
    cin >> euro_unit;

    double us_unit;
    us_unit = mi_per_100km / (euro_unit / l_per_gallon);

    cout << euro_unit << " L/100km = ";
    cout << us_unit << " mpg" << endl;

    return 0;
}