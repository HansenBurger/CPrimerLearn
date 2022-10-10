#include <iostream>

int main(void)
{
    using namespace std;
    const double Km_per_mi = 1.609344;
    const double L_per_gal = 3.78541178;

    double dist_mi, fuel_gal;

    cout << "Enter the distance(mile) your car traveled: ";
    cin >> dist_mi;
    cout << "Enter the consumed fuel(gallon): ";
    cin >> fuel_gal;

    double c_l_per_100_km;
    c_l_per_100_km = 100.0 * (dist_mi * Km_per_mi) / (fuel_gal * L_per_gal);

    cout << "Your car's fuel consumption per 100 km: " << c_l_per_100_km << " L." << endl;

    return 0;
}