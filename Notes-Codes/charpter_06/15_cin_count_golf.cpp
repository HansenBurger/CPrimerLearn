#include <iostream>

using namespace std;

const int Max = 5;

int main(void)
{
    int golf[Max];
    cout << "Please enter your golf scores." << endl;
    cout << "You must enter " << Max << " rounds." << endl;

    for (int i = 0; i < Max; i++)
    {
        cout << "Round # " << i + 1 << " : ";
        while (!(cin >> golf[i]))
        {
            /*
            step.1 reset the cin tag
            step.2 clear the cin sequence
            step.3 prompt to enter again
            */
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Wrong input, enter again: ";
        }
    }

    double total = 0;
    for (int i = 0; i < Max; i++)
        total += golf[i];

    cout << "Average score: " << total / Max << endl;
    return 0;
}