#include <iostream>

struct CandyBar
{
    char brand[20];
    double weight;
    unsigned int kcal; // 卡路里没有负值
};

int main(void)
{
    using namespace std;
    CandyBar snack = {"Mocha Munch",
                      2.3,
                      350};
    cout << "Snack brand: " << snack.brand << endl;
    cout << "Snack weight: " << snack.weight << endl;
    cout << "Snack kcal: " << snack.kcal << endl;

    return 0;
}