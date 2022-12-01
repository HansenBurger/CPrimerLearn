#include <iostream>
#include <cstring>
#include <cctype>

const int ArSize = 20;

int main(void)
{
    using namespace std;
    char ch[ArSize];
    int vowels = 0, consonants = 0, others = 0;

    cout << "Enter words (q to quit):" << endl;
    while ((cin >> ch) && strcmp(ch, "q"))
    {
        if (!isalpha(ch[0]))
        {
            ++others;
            continue;
        }
        else
        {
            if (isupper(ch[0]))
                ch[0] = tolower(ch[0]);
            switch (ch[0])
            {
            case 'a':
                ++vowels;
                break;
            case 'e':
                ++vowels;
                break;
            case 'i':
                ++vowels;
                break;
            case 'o':
                ++vowels;
                break;
            case 'u':
                ++vowels;
                break;

            default:
                ++consonants;
                break;
            }
        }
    }
    cout << vowels << " words beginning with vowels" << endl;
    cout << consonants << " words beginning with consonants" << endl;
    cout << others << " others" << endl;

    return 0;
}