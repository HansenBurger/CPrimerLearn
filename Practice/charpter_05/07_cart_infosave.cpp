#include <iostream>
#include <string>

using namespace std;

struct car
{
    string make;
    int year;
};

int main(void)
{
    int cat_size;
    cout << "How many cars do you wish to catalog? ";
    cin >> cat_size;
    cin.get(); // 空白字符仍然存在在队列中

    car *cars = new car[cat_size];
    for (int i = 0; i < cat_size; i++)
    {
        cout << "Car #" << i + 1 << " :" << endl;
        cout << "Please enter the make: ";
        getline(cin, (cars + i)->make);
        cout << "Please enter the year made: ";
        cin >> (cars + i)->year;
        cin.get();
    }

    cout << "Here is your collection: " << endl;
    for (int i = 0; i < cat_size; i++)
        cout << cars[i].year << " " << cars[i].make << endl;

    return 0;
}
