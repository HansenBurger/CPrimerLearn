#include <cmath>
#include <iostream>

double BMI_count(double, double);

int main(void)
{
    using namespace std;
    const int Inch_per_ft = 12;
    const double P_per_kg = 2.2;
    const double M_per_inch = 0.0254;

    int h_inch, h_ft;
    double w_p;
    cout << "Enter your height in (ft inch): ";
    cin >> h_ft >> h_inch;
    cout << "Enter your weight in (pounds): ";
    cin >> w_p;

    double h_m, w_kg, bmi;
    h_m = (h_ft * Inch_per_ft + h_inch) * M_per_inch;
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