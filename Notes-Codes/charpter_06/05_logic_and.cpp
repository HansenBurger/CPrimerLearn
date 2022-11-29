#include <iostream>

const int ArSize = 6;

using namespace std;

int main(void)
{
    int i = 0;
    double value[ArSize], temp;

    cout << "Enter six number and compare with your level." << endl;
    cout << "Terminate condition, when you make 6 number or enter a nagative number" << endl;

    cout << "First value: ";
    cin >> temp;
    while (i < ArSize && temp >= 0)
    {
        value[i] = temp;
        ++i;
        if (i < ArSize)
        {
            cout << "Next value: ";
            cin >> temp;
        }
    }

    if (i == 0)
        cout << "No data--byte." << endl;
    else
    {
        cout << "Enter your level:";
        double level;
        cin >> level;

        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if (value[j] > level)
                count++;
        }
        cout << count << " numbers are bigger than your level" << endl;
    }

    return 0;
}