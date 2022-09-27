#include <iostream>

double UnitSwitch(double);

int main(void)
{
    using namespace std;
    double light_yr;
    cout << "Enter the number of light years: ";
    cin >> light_yr;

    double astro_unit = UnitSwitch(light_yr);
    cout << light_yr << " light year = ";
    cout << astro_unit << " astronomical units. " << endl;
    return 0;
}

double UnitSwitch(double light_yr)
{
    return light_yr * 63240;
}