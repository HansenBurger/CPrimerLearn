#include <iostream>

int main(void)
{
    using namespace std;
    const int H_per_d = 24;
    const int M_per_h = 60;
    const int S_per_m = 60;

    long long s_in;
    cout << "Enter the number of seconds: ";
    cin >> s_in;

    int d_out, h_out, m_out, s_out;
    s_out = s_in % S_per_m;
    m_out = s_in / S_per_m % M_per_h;
    h_out = s_in / S_per_m / M_per_h % H_per_d;
    d_out = s_in / S_per_m / M_per_h / H_per_d;

    cout << s_in << " seconds = ";
    cout << d_out << " days, ";
    cout << h_out << " hours, ";
    cout << m_out << " minutes, ";
    cout << s_out << " seconds" << endl;

    return 0;
}