#include <iostream>

int main(void)
{
    using namespace std;
    const double tex_st[4] = {0.0, 0.1, 0.15, 0.20};
    cout << "Calculate the tax you need to pay in Neutronia Kingdom" << endl;
    cout << "Income(tvarps):\t";
    int income;
    double tex = 0;

    while ((cin >> income) && income >= 0)
    {
        if (income <= 5000)
            tex = 0.0;
        else if ((income > 5000) && (income <= 15000))
            tex = (income - 5000) * tex_st[1];
        else if ((income > 15000) && (income <= 35000))
            tex = 10000 * tex_st[1] + (income - 15000) * tex_st[2];
        else
            tex = 10000 * tex_st[1] + 20000 * tex_st[2] + (income - 35000) * tex_st[3];

        cout << "Tex(tvarps):\t" << tex << endl;
        cout << "Income(tvarps):\t";
    }
    cout << "Bye!" << endl;

    return 0;
}