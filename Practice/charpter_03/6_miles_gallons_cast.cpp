#include <iostream>

int main(void)
{
    using namespace std;

    double dist_mi, fuel_gal;
    cout << "Enter the distance(mile) your car traveled: ";
    cin >> dist_mi;
    cout << "Enter the consumed fuel(gallon): ";
    cin >> fuel_gal;

    double consume_gal_mi;
    consume_gal_mi = dist_mi / fuel_gal;
    cout << "Your car's fuel consumption : " << consume_gal_mi << " milles/gallon." << endl;

    double dist_km, fuel_l;
    cout << "Enter the distance(km) your car traveled: ";
    cin >> dist_km;
    cout << "Enter the consumed fuel(L): ";
    cin >> fuel_l;

    double consume_km_l;
    consume_km_l = 100 * (fuel_l / dist_km);
    cout << "Your car's fuel consumption : " << consume_km_l << " L/100km." << endl;

    return 0;
}