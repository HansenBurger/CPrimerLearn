#include <iostream>

double Convert(double);

int main(void)
{
    using namespace std;
    double light_yr;
    cout << "Enter the number of light years: ";
    cin >> light_yr;

    double astro_unit = Convert(light_yr);
    cout << light_yr << " light years = ";
    cout << astro_unit << " astronomical units. " << endl;
    return 0;
}

double Convert(double light_yr)
{
    return light_yr * 63240;
}