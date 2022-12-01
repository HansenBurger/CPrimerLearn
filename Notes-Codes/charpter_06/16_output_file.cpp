#include <iostream> // ostream->cout, istream->cin
#include <fstream>  // ofstream  , ifstream

using namespace std;

int main(void)
{

    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outfile;                                      // 由于没有cin/cout所以要创建一个输出流对象
    outfile.open("./Notes-Codes/charpter_06/carinfo.txt"); // 将创建的对象和文件关联，txt和outfile间操作同步
    // 默认新增加的内容会覆盖

    cout << "Enter the make and model of automobile: ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    d_price = a_price * 0.913;

    cout << fixed;                  // 修改科学计数法为浮点表示
    cout.precision(2);              // 小数点精度
    cout.setf(ios_base::showpoint); // 之后的cout都以这种形式
    cout << "Make and model:\t" << automobile << endl;
    cout << "Year:\t" << year << endl;
    cout << "Was asking:\t" << a_price << endl;
    cout << "Now asking:\t" << d_price << endl;

    // cout如何使用，outfile就如何使用
    outfile << fixed;
    outfile.precision(2);
    outfile.setf(ios_base::showpoint);
    outfile << "Make and model:\t" << automobile << endl;
    outfile << "Year:\t" << year << endl;
    outfile << "Was asking:\t" << a_price << endl;
    outfile << "Now asking:\t" << d_price << endl;

    outfile.close(); // 程序运行结束自动关闭

    return 0;
}