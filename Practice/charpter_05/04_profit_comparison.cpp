#include <iostream>

const double InitDeposit = 100.0;
const double SimInterest = 0.1;
const double ComInterest = 0.05;

int main(void)
{
    using namespace std;

    int years = 0;
    double cleos = InitDeposit;
    double daphnes = InitDeposit;

    do
    {
        years++;
        daphnes += SimInterest * InitDeposit;
        cleos += cleos * ComInterest;
    } while (cleos <= daphnes);

    cout << "When investing " << years << " yrs, Cleo's deposit exceed Daphne's: " << endl;
    cout << "Daphen:\t" << daphnes << " $" << endl;
    cout << "Cleo:\t" << cleos << " $" << endl;

    return 0;
}