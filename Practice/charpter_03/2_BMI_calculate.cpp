#include <cmath>
#include <iostream>

double BMI_count(double, double);

int main(void)
{
    using namespace std;
    const double P_per_kg = 2.2;
    const double Ft_per_ich = 12.0;
    const double M_per_ft = 0.0254;

    int h_ich, h_ft, w_p;
    cout << "Enter your height in (ich ft): ";
    cin >> h_ich >> h_ft;
    cout << "Enter your weight in (pounds): ";
    cin >> w_p;

    double h_m, w_kg, bmi;
    h_m = (h_ich * Ft_per_ich + h_ft) * M_per_ft;
    w_kg = w_p / P_per_kg;
    bmi = BMI_count(h_m, w_kg);

    cout << "Your BMI is " << bmi << " in ";
    cout << h_m << "(m) and " << w_kg << "(kg)." << endl;

    return 0;
}

double BMI_count(double h_m, double w_kg)
{
    double bmi;
    bmi = w_kg / pow(h_m, 2);
    return bmi;
}