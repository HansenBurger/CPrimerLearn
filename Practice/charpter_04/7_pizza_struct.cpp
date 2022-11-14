#include <iostream>

const int Str_len = 20;

struct Pizza
{
    char *company = new char[Str_len];
    double *diameter = new double;
    double *weight = new double;
};

int main(void)
{
    using namespace std;
    Pizza pizza_;
    cout << "Enter the company of pizza: ";
    cin.getline(pizza_.company, Str_len);
    cout << "Enter the size(cm) of pizza: ";
    cin >> *pizza_.diameter;
    cout << "Enter the weight(g) of pizza: ";
    cin >> *pizza_.weight;
    cout << "Pizza's Brand: " << pizza_.company << endl;
    cout << "Pizza's Diameter: " << *pizza_.diameter << endl;
    cout << "Pizza's Weight: " << *pizza_.weight << endl;

    return 0;
}
