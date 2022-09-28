#include <iostream>

double Convert(double);

int main(void)
{
    using namespace std;
    double c_degree;
    cout << "Please enter a Celsius value: ";
    cin >> c_degree;
    double f_degree = Convert(c_degree);
    cout << c_degree << " degrees Celsius is ";
    cout << f_degree << " degrees Fahrenheit." << endl;
    return 0;
}

double Convert(double c_degree)
{
    return 1.8 * c_degree + 32.0;
}