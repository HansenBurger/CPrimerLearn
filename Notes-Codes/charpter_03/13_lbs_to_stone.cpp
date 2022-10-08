#include <iostream>

int main(void)
{
    using namespace std;

    const int Lbs_per_stn = 14;
    int lbs;

    cout << "Enter your weight in pounds: ";
    cin >> lbs;
    int stone = lbs / Lbs_per_stn;
    int pounds = lbs % Lbs_per_stn;

    cout << lbs << " pounds = " << stone << " stone, ";
    cout << pounds << " pounds." << endl;

    return 0;
}