#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int Size = 60;

// fileloc: ./Notes-Codes/charpter_06/tmp/score.txt

int main(void)
{
    char file_name[Size];
    cout << "Enter name of data file: ";
    cin.getline(file_name, Size);

    ifstream infile;
    infile.open(file_name); //文件可能打开失败(文件名，权限)
    if (!infile.is_open())  //打开成功真，打开失败假
    {
        cout << "Could not open the file: " << file_name << endl;
        cout << "Program terminating" << endl;
        exit(EXIT_FAILURE); // 标准库，退出
    }
    cout << "Success open the txt file." << endl;

    double value, sum = 0.0;
    int count = 0;
    while (infile >> value && !infile.fail())
    {
        sum += value;
        ++count;
        // 和cin读取一样，最后一行的数字要有空白字符才能读入
    }
    if (infile.eof())
        cout << "End of file reached." << endl;
    else if (infile.fail())
        cout << "Input terminated by data mismachted." << endl;
    else
        cout << "Input terminated by unkonw reason." << endl;

    if (0 == count)
        cout << "No data processed." << endl;
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    infile.close();
    return 0;
}
