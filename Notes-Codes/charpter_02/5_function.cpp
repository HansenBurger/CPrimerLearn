#include <iostream>
#include <cmath>

int main(void)
{
    using namespace std;
    double area;

    cout << "Enter the floor area, in square feet of your home" << endl;
    cin >> area; // auto change the type between var and stream

    double side;
    side = sqrt(area);

    cout << "That's the equivalent of a square " << side << " feet to the side." << endl;

    return 0;
}