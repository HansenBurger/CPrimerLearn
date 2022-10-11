#include <iostream>

int main(void)
{
    using namespace std;
    const int Inch_per_ft = 12;

    int h_inch_in, h_ft_out, h_inch_out;
    cout << "Enter your height in ich:__\b\b";
    cin >> h_inch_in;

    h_ft_out = h_inch_in / Inch_per_ft;
    h_inch_out = h_inch_in % Inch_per_ft;

    cout << "Your height = " << h_ft_out << " ft ";
    cout << h_inch_out << " inch." << endl;
}