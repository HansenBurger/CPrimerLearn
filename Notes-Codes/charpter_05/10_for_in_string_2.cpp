#include <iostream>
#include <string>

/*
将字符串的首尾互换
*/

int main(void)
{
    using namespace std;

    cout << "Please enter a word:";
    string word;
    cin >> word;

    int i, j; // 只是分隔
    char temp;
    for (j = 0, i = word.size() - 1; j < i; j++, i--)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }

    cout << "After process: " << word << endl;
    return 0;
}