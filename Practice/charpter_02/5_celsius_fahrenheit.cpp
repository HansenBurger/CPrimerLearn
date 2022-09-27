#include <iostream>

double UnitSwitch(double);

int main(void)
{
    using namespace std;
    double celsius;
    cout << "Please enter a Celsius value: ";
    cin >> celsius;
    double fahrenheit = UnitSwitch(celsius);
    cout << celsius << " degrees Celsius is ";
    cout << fahrenheit << " degrees Fahrenheit." << endl;
    return 0;
}

double UnitSwitch(double degree)
{
    return 1.8 * degree + 32.0;
}