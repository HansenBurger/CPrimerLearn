#include <iostream>
#include <array>

int main()
{
    using namespace std;
    array<double, 3> scores;
    cout << "Enter three 40m run scores" << endl;
    cout << "First: ";
    cin >> scores[0];
    cout << "Second: ";
    cin >> scores[1];
    cout << "Third: ";
    cin >> scores[2];

    cout << "The average of the three score is ";
    cout << (scores[0] + scores[1] + scores[2]) / 3.0 << endl;

    return 0;
}