#include <iostream>

int main(void)
{
    using namespace std;

    int carrots;
    cout << "Num of carrots ?" << endl;
    cin >> carrots;
    cout << "Num of carrots: " << carrots << endl;
    carrots -= 1;
    cout << "Now you have: " << carrots << endl;
}