#include <iostream>

int main(void)
{
    using namespace std;

    int year;

    cout << "What year was your house built?" << endl;
    cin >> year; // cin 读取保留再输入队列
    cin.get();
    cout << "What is its street address?" << endl;
    char address[80];
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;
}