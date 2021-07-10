#include <iostream>
using namespace std;
int Stack[100];

int StackPointer = 0;    

void push(int Data)     
{ 
Stack[StackPointer] = Data; 
StackPointer++ ; 
}

int pop()                     
{
StackPointer--;
return Stack[StackPointer]; 
}
int arr[1000];
int primesum(int num)
{
    for (int a = 2; a <= num - 1; a++)
    {
        for (int i = 2; i <= a - 1; i++)
        {
            if (a % i == 0)
            {
                break;
            }
            if (i == a - 1)
            {
                static int j = 0;
                arr[j] = a;
                j++;
            }
        }
    }
    return 0;
}
int main()
{
    int n;
    int b = 0;
    int c = 0;
    cin >> n;
    if (n == 4)
    {
        cout << "2 + 2 =4";
    }
    else
    {
        primesum(n);
        static int s = 0;
        for (b = 0; b < 1000; b++)
        {
            for (c = 0; c < 1000 && c <= b; c++)
            {
                if (arr[b] + arr[c] == n)
                {
                    push(arr[b]);
                    push(arr[c]);
                    s += 1;
                }
            }
        }
        for (int k = 0; k <= s - 1; k++)
        {
            cout << pop() << " + " << pop() << " =" << n << endl;
        }
    }
    
    return 0;
}