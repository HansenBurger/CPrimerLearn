#include <iostream>

int main(void)
{
    using namespace std;

    int h_ft;
    double h_ic;
    const double Ft_per_ich = 12.0; // 都是整型的话计算结果则是整型

    cout << "Enter your height in ft:__\b\b";
    cin >> h_ft;

    h_ic = h_ft / Ft_per_ich;

    cout << "Your height " << h_ft << " ft";
    cout << " = " << h_ic << " ich" << endl;

    return 0;
}