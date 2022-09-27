#include <iostream>

int stonetolb(int sts);

int main(void)
{
    // using namespace std;
    int stone;
    std::cout << "Enter the weight in stone: ";
    std::cin >> stone;

    int pounds = stonetolb(stone);
    std::cout << stone << " stone = ";
    std::cout << pounds << " pounds." << std::endl;
    return 0;
}

// 1 stone = 14lbs

int stonetolb(int sts)
{
    return 14 * sts; // equal to define before return
}