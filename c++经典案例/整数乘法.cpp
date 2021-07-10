#include <iostream>
#include<string>
#include<cstring>

const int maxn = 5000;
const int maxn2 = maxn * 2;

//将字符串转为整型数组，并返回数组长度
int read_str(char* s, int* a)
{
    int n = strlen(s);//获取字符串的长度

    for (int i = 0; i < n; ++i)
    {
        a[i] = s[n - i - 1] - '0';
    }
    return n;
}

int main(int argc, char* argv[])
{
    char s[maxn];//字符数组
    int a[maxn2], b[maxn2], c[maxn2];//整型数组
    int n1, n2;
    std::cin >> s;
    n1 = read_str(s, a);
    std::cin >> s;
    n2 = read_str(s, b);

    //先将，每个数字相乘
    for (int i = 0; i < n1 + n2; ++i) c[i] = 0;//初始化c数组

    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            c[i + j] += a[i] * b[j];
            //c[i + j] += a[i] * b[j];
        }
    }
       

    //实现乘法的进位操作
    for (int i = 0, m = 0; i < n1 + n2; ++i)
    {
        c[i] += m;
        m = c[i] / 10;
        c[i] %= 10;
    }

    //输出数组
    int n = n1 + n2 - 1;
    for (; c[n] == 0; --n);
    for (; n >= 0; --n)
    {
        std::cout << c[n];
    }
    std::cout << std::endl;
    return 0;
}