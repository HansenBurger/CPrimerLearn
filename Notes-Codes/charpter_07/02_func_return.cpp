#include <iostream>

using namespace std;

void cheers(int);
double cube(double);

int main(void)
{
    cheers(5);
    cout << "Give me a number: ";
    double side;
    cin >> side;
    double volume = cube(side);
    cout << side << " cube = " << volume << endl;
    // 返回的double作为参数传递给cheers，发生一次类型转换
    cheers(cube(2));
    return 0;
}

void cheers(int n)
{
    for (int i = 0; i < n; i++)
        cout << "cheers;";
    cout << endl;
}

double cube(double x)
{
    return x * x * x;
}