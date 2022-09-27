#include <iostream>

void Cout_1(void);
void Cout_2(void);

int main(void)
{
    Cout_1();
    Cout_1();
    Cout_2();
    Cout_2();
}

void Cout_1(void)
{
    std::cout << "Three blind mice" << std::endl;
}

void Cout_2(void)
{
    std::cout << "See how they run" << std::endl;
}