#include <iostream>

void show_time(int, int);

int main(void)
{
    using namespace std;
    int hour, minutes;
    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> minutes;
    show_time(hour, minutes);
    return 0;
}

void show_time(int h, int m)
{
    std::cout << "Time: " << h << ":" << m << std::endl;
}