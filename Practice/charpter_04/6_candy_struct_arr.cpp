#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    int kcal;
};

int main(void)
{
    using namespace std;
    CandyBar snacks[3] = {{"Mocha Munch", 2.3, 350},
                          {"Hershey", 1.8, 200},
                          {"M&M\'s", 5.5, 440}};

    cout << "Snack 1: " << endl;
    cout << "brand = " << snacks->brand << ", weight = " << snacks->weight << ", kcal = " << snacks->kcal << endl;
    cout << "Snack 2: " << endl;
    cout << "brand = " << (snacks + 1)->brand << ", weight = " << (snacks + 1)->weight << ", kcal = " << (snacks + 1)->kcal << endl;
    cout << "Snack 3: " << endl;
    cout << "brand = " << (snacks + 2)->brand << ", weight = " << (snacks + 2)->weight << ", kcal = " << (snacks + 2)->kcal << endl;

    return 0;
}