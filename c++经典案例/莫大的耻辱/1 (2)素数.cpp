#include<iostream>
#include<cmath>
using namespace std;
int is_prime(int n)
{
    if (n == 0 || n == 1)
        return 0;
    else
    {
        //平方细节，不要考虑2的情况
        for (int j = 2; j * j <= n; j++)
        {
            if (n % j == 0)
                return 0;
        }
    }
    return 1;
}
int main()
{
    int n;
    cin >> n;
    if (is_prime(n))
        cout << "Y";
    else
        cout << "N";
    return 0;
}
