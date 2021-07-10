//定义一个整数栈类IntStack（包括类的实现）。数据成员包括一个整型数组指针stack、栈指针pos和栈数组尺寸size。
//成员函数为构造函数（参数为栈大小）、析构函数、压栈操作push和出栈pop。
//（说明：主函数里输入栈操作序列，0为压栈，1为出栈，根据你实现的成员函数，最终的输出序列应该为以下之一：
//若栈空仍继续出栈操作，输出：empty(当为空时用系统函数exit(0)结束整个程序的运行)
//若栈满仍继续入栈操作，输出：full(当为满时用系统函数exit(0)结束整个程序的运行)
//否则，在输入序列遇到 - 1时停止输入并输出栈内元素，每个元素后都有一个空格）
#include<iostream>
#include"stdlib.h"
using  namespace  std;
class  IntStack {
public:
    IntStack(int  s);
    ~IntStack();
    void Push(int  data);
    void  Pop(int& data);
    void  Print();
private:
    int pos;//栈数组的长度
    int* stack;
    int size;
};

IntStack::IntStack(int  s)
{
    size = s;
    stack = new int[size];
    pos = 0;
}

IntStack::~IntStack()
{
    delete stack;

}

void  IntStack::Push(int  data)
{
    if (pos == size)
    {
        cout << "full" << endl; exit(0);
    }
    else
    {
        stack[pos] = data;
        pos++;
    }


}

void  IntStack::Pop(int& data)
{

    data = 0;
    if (pos == 0)
    {
        cout << "empty" << endl; exit(0);
    }
    else
    {
        stack[pos] = 0;
        pos--;
    }


}

void  IntStack::Print()
{
    int  i;
    for (i = 0; i < pos; i++)
        cout << stack[i] << "  ";
}

int  main()
{
    IntStack  is(5);
    int  a[10] = { 2,5,1,7,5,4,2,7,3,6 };
    int  i = 0;
    int  d;
    int  x;
    cin >> x;
    while (x != -1) {
        if (x == 0) {
            is.Push(a[i]);
            i++;
        }
        else  is.Pop(d);
        cin >> x;
    }
    is.Print();
    return  0;
}