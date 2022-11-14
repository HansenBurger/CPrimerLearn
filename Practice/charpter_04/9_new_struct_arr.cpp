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
    CandyBar s_1 = {"Mocha Munch", 2.3, 350};
    CandyBar s_2 = {"Hershey", 1.8, 200};
    CandyBar s_3 = {"M&M\'s", 5.5, 440};
    CandyBar *snacks = new CandyBar[3];
    snacks[0] = s_1;
    snacks[1] = s_2;
    snacks[2] = s_3;

    cout << "Snack 1: " << endl;
    cout << "brand = " << snacks->brand;       // snacks = &s_1
    cout << ", weight = " << (*snacks).weight; // *snakes = snakes[0] = s_1
    cout << ", kcal = " << snacks[0].kcal << endl;
    cout << "Snack 2: " << endl;
    cout << "brand = " << (snacks + 1)->brand << ", weight = " << (*(snacks + 1)).weight << ", kcal = " << snacks[1].kcal << endl;
    cout << "Snack 3: " << endl;
    cout << "brand = " << (snacks + 2)->brand << ", weight = " << (*(snacks + 2)).weight << ", kcal = " << snacks[2].kcal << endl;

    delete[] snacks;

    return 0;
}