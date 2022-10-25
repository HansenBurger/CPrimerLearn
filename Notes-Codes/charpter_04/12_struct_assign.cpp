#include <iostream>

struct inflatable
{
    std::string name;
    float volume;
    double price;
};

int main(void)
{
    using namespace std;

    inflatable bounquet = {
        "sunflowers",
        0.20,
        12.49};

    inflatable choice;

    cout << "bounquet: " << bounquet.name;
    cout << " for $ " << bounquet.price << endl;

    choice = bounquet;
    cout << "choice: " << choice.name;
    cout << " for $ " << choice.price << endl;

    return 0;
}