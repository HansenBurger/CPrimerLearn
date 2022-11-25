#include <iostream>
#include <cstring>

const int ArSize = 20;

int main(void)
{
    using namespace std;

    char word[ArSize]; //如果用char指针，完成初始化(指向对象)才能使用
    int sum = 0;
    cout << "Enter words(to stop, type the word done): " << endl;
    cin >> word;
    while (strcmp(word, "done"))
    {
        sum++;
        cin >> word;
    }
    cout << "your entered a total of " << sum << " words" << endl;

    return 0;
}