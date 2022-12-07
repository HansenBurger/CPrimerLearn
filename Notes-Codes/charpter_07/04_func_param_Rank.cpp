#include <iostream>

using namespace std;

long double probability(unsigned int numbers, unsigned int picks);

int main(void)
{
    unsigned int tot, choices; // choices不能超过tot
    cout << "Enter the total number of choices on the game card and number of picks allowed: ";
    while ((cin >> tot >> choices) && (choices <= tot))
    {
        cout << "You hace one chance in " << probability(tot, choices);
        cout << " of winning." << endl;
        cout << "Please enter next two number(q to quit): ";
    }

    return 0;
}

long double probability(unsigned int numbers, unsigned int picks)
{
    /*
    C = \frac{n!}{m!(n-m!)}
    :param: nubers: total number
    :param: picks: picking number
    */
    long double result = 1.0;
    for (double n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p; // 上一轮的结果乘以两者相除

    return result;
}