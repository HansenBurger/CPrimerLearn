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

    inflatable guests[2] = {
        {"Bambi", 0.5, 21.99},
        {"Godzilla", 200, 565.99}};

    cout << "The guests " << guests[0].name << " and " << guests[1].name;
    cout << " have a combined volume of " << guests[0].volume + guests[1].volume << " cubic feet." << endl;
    return 0;
}