#include <iostream>

using namespace std;

const int Max = 5;
int fill_array(double *arr, int limit);
void show_array(const double arr[], int n);
void revalue(double r, double arr[], int n);

int main(void)
{
    double properties[Max];
    // 1. 填充数组函数
    int arr_size = fill_array(properties, Max);
    // 2. 显示数组内的内容
    show_array(properties, arr_size);
    // 3. 重新评估每一个房地产的价值
    if (arr_size > 0)
    {
        cout << "Enter revaluation factor: ";
        double factor;
        while (!(cin >> factor))
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input: input again: ";
        }
        revalue(factor, properties, arr_size);
        show_array(properties, arr_size);
    }
    return 0;
}

int fill_array(double *arr, int limit)
{
    // 返回成功过存储的个数
    int size = 0;
    for (int i = 0; i < limit; i++)
    {
        double tmp;
        cout << "Enter value #" << i + 1 << ": ";
        cin >> tmp;
        if (!cin)
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input: input process terminated." << endl;
            break;
        }
        else if (tmp < 0)
            break;
        else
        {
            arr[i] = tmp;
            size++;
        }
    }
    return size;
}

void show_array(const double arr[], int n)
{
    //增加const以后，无法通过指针修改数组内容
    for (int i = 0; i < n; i++)
        cout << "Porperty #" << i + 1 << " " << *(arr + i) << " $" << endl;
}

void revalue(double r, double arr[], int n)
{
    // 让数组中每个值乘上一个比例系数
    for (int i = 0; i < n; i++)
        arr[i] *= r;
}