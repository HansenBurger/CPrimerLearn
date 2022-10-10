#include <iostream>

int main(void)
{
    using namespace std;
    const double M_per_d = 60.0;
    const double S_per_m = 60.0;

    int d_in, m_in, s_in;
    cout << "Enter a latitude in degrees, minutes, and secounds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> d_in;
    cout << "Next, enter the minutes of arc: ";
    cin >> m_in;
    cout << "Finally, enter the seconds of arc: ";
    cin >> s_in;

    double d_out;
    d_out = (s_in / S_per_m + m_in) / M_per_d + d_in;

    cout << d_in << " degrees, ";
    cout << m_in << " minutes, ";
    cout << s_in << " seconds = " << d_out << " degrees" << endl;

    return 0;
}