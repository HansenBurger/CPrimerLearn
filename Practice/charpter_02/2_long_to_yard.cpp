#include <iostream>

int main(void)
{
    using namespace std;
    long length;
    cout << "Enter the distance: ";
    cin >> length;
    int yard = 220 * length;
    cout << length << "long = ";
    cout << yard << " yard." << endl;
    return 0;
}