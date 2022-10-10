# Charpter 3 编程练习

## 3.1

题: 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;

    int h_ft;
    double h_ic;
    const double Ft_per_ich = 12.0; // 都是整型的话计算结果则是整型

    cout << "Enter your height in ft:__\b\b";
    cin >> h_ft;

    h_ic = h_ft / Ft_per_ich;

    cout << "Your height " << h_ft << " ft";
    cout << " = " << h_ic << " ich" << endl;

    return 0;
}
```

## 3.2

题: 编写一个小程序，要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。（使用3个变量来存储这些信息。）该程序报告其BMI（Body Mass Index，体重指数）。为了计算BMI，该程序以英寸的方式指出用户的身高（1英尺为12英寸），并将以英寸为单位的身高转换为以米为单位的身高（1英寸=0.0254米）。然后，将以磅为单位的体重转换为以千克为单位的体重（1千克=2.2磅）。最后，计算相应的BMI—体重（千克）除以身高（米）的平方。用符号常量表示各种转换因子。

答:

```c++
#include <cmath>
#include <iostream>

double BMI_count(double, double);

int main(void)
{
    using namespace std;
    const double P_per_kg = 2.2;
    const double Ft_per_ich = 12.0;
    const double M_per_ft = 0.0254;

    int h_ich, h_ft, w_p;
    cout << "Enter your height in (ich ft): ";
    cin >> h_ich >> h_ft;
    cout << "Enter your weight in (pounds): ";
    cin >> w_p;

    double h_m, w_kg, bmi;
    h_m = (h_ich * Ft_per_ich + h_ft) * M_per_ft;
    w_kg = w_p / P_per_kg;
    bmi = BMI_count(h_m, w_kg);

    cout << "Your BMI is " << bmi << " in ";
    cout << h_m << "(m) and " << w_kg << "(kg)." << endl;

    return 0;
}

double BMI_count(double h_m, double w_kg)
{
    double bmi;
    bmi = w_kg / pow(h_m, 2);
    return bmi;
}
```

## 3.3

题: 编写一个程序，要求用户以度、分、秒的方式输入一个纬度，然后以度为单位显示该纬度。1度为60分，1分等于60秒，请以符号常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。

下面是该程序运行时的情况：

```cmd
Enter a latitude in degrees, minutes, and secounds:
First, enter the degrees: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19
37 degrees, 51 minutes, 19 seconds = 37.8553 degrees
```

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    const double M_per_d = 60.0;
    const double S_per_m = 60.0;

    int d_in, m_in, s_in;
    cout << "Enter a latitude in degrees, minutes, and secounds:" << endl;
    cout << "First, enter the degrees: ";
    cin >> d_in;
    cout << "Next, enter the minutes of arc: ";
    cin >> m_in;
    cout << "Finally, enter the seconds of arc: ";
    cin >> s_in;

    double d_out;
    d_out = (s_in / S_per_m + m_in) / M_per_d + d_in;

    cout << d_in << " degrees, ";
    cout << m_in << " minutes, ";
    cout << s_in << " seconds = " << d_out << " degrees" << endl;

    return 0;
}
```

## 3.4

题: 编写一个程序，要求用户以整数方式输入秒数（使用long或long long变量存储），然后以天、小时、分钟和秒的方式显示这段时间。使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多少秒。

该程序的输出应与下面类似：

```cmd
Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds
```

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    const int H_per_d = 24;
    const int M_per_h = 60;
    const int S_per_m = 60;

    long long s_in;
    cout << "Enter the number of seconds: ";
    cin >> s_in;

    int d_out, h_out, m_out, s_out;
    s_out = s_in % S_per_m;
    m_out = s_in / S_per_m % M_per_h;
    h_out = s_in / S_per_m / M_per_h % H_per_d;
    d_out = s_in / S_per_m / M_per_h / H_per_d;

    cout << s_in << " seconds = ";
    cout << d_out << " days, ";
    cout << h_out << " hours, ";
    cout << m_out << " minutes, ";
    cout << s_out << " seconds" << endl;

    return 0;
}
```

## 3.5

题: 编写一个程序，要求用户输入全球当前的人口和美国当前的人口（或其他国家的人口）。将这些信息存储在long long变量中，并让程序显示美国（或其他国家）的人口占全球人口的百分比。

该程序的输出应与下面类似：

```cmd
Enter the world's population: 6898758899
Enter the population of the US: 310783781
The population of US is 4.50492% of the world population.
```

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    long long cn_p, tot_p;

    cout << "Enter the world's population: ";
    cin >> tot_p; // 7983321000
    cout << "Enter the population of the CN: ";
    cin >> cn_p; // 1412600000

    double cn_per_tot;
    cn_per_tot = 100.0 * cn_p / tot_p;
    // 需要注意，自动类型同样遵守运算顺序，如果最后乘100.0，前面的结果还是整数类型

    cout << "The population of US is ";
    cout << cn_per_tot << "\% of the world population." << endl;

    return 0;
}
```

## 3.6

题: 编写一个程序，要求用户输入驱车里程（英里）和使用汽油量（加仑），然后指出汽车耗油量为一加仑的里程。如果愿意，也可以让程序要求用户以公里为单位输入距离，并以升为单位输入汽油量，然后指出欧洲风格的结果—即每100公里的耗油量（升）。

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    const double Km_per_mi = 1.609344;
    const double L_per_gal = 3.78541178;

    double dist_mi, fuel_gal;

    cout << "Enter the distance(mile) your car traveled: ";
    cin >> dist_mi;
    cout << "Enter the consumed fuel(gallon): ";
    cin >> fuel_gal;

    double c_l_per_100_km;
    c_l_per_100_km = 100.0 * (dist_mi * Km_per_mi) / (fuel_gal * L_per_gal);

    cout << "Your car's fuel consumption per 100 km: " << c_l_per_100_km << " L." << endl;

    return 0;
}
```

## 3.7

题: 编写一个程序，要求用户按欧洲风格输入汽车的耗油量（每100公里消耗的汽油量（升）），然后将其转换为美国风格的耗油量—每加仑多少英里。注意，除了使用不同的单位计量外，美国方法（距离/燃料）与欧洲方法（燃料/距离）相反。

100公里等于62.14英里，1加仑等于3.875升。因此，19mpg大约合12.4l/100km，27mpg大约合8.71/100km。

答:

```c++
#include <iostream>

int main(void)
{
    using namespace std;
    const double mi_per_100km = 62.14;
    const double l_per_gallon = 3.875;

    double euro_unit;
    cout << "Enter the fuel consumption of your car (L/100km): ";
    cin >> euro_unit;

    double us_unit;
    us_unit = mi_per_100km / (euro_unit / l_per_gallon);

    cout << euro_unit << " L/100km = ";
    cout << us_unit << " mpg" << endl;

    return 0;
}
```
