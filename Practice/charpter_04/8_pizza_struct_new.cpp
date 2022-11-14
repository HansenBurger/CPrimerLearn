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
    Pizza *pizza_ = new Pizza;
    cout << "Enter the size(cm) of pizza: ";
    cin >> *((*pizza_).diameter);
    cout << "Enter the company of pizza: ";
    cin.get(); // 捕获没放入队列的回车符号
    cin.getline(pizza_->company, Str_len);
    cout << "Enter the weight(g) of pizza: ";
    cin >> *((*pizza_).weight);
    cout << "Pizza's Brand: " << pizza_->company << endl;
    cout << "Pizza's Diameter: " << *(pizza_->diameter) << endl;
    cout << "Pizza's Weight: " << *(pizza_->weight) << endl;

    delete pizza_;

    return 0;
}
