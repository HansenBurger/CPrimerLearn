#include <iostream>
#include <string>

int main(void)
{
    using namespace std;

    string word;
    int sum = 0;
    cout << "Enter words(to stop, type the word done): " << endl;
    cin >> word;
    while (word != "done")
    {
        sum++;
        cin >> word;
    }
    cout << "your entered a total of " << sum << " words" << endl;

    return 0;
}