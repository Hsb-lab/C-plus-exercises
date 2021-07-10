//����һ������ջ��IntStack���������ʵ�֣������ݳ�Ա����һ����������ָ��stack��ջָ��pos��ջ����ߴ�size��
//��Ա����Ϊ���캯��������Ϊջ��С��������������ѹջ����push�ͳ�ջpop��
//��˵����������������ջ�������У�0Ϊѹջ��1Ϊ��ջ��������ʵ�ֵĳ�Ա���������յ��������Ӧ��Ϊ����֮һ��
//��ջ���Լ�����ջ�����������empty(��Ϊ��ʱ��ϵͳ����exit(0)�����������������)
//��ջ���Լ�����ջ�����������full(��Ϊ��ʱ��ϵͳ����exit(0)�����������������)
//������������������ - 1ʱֹͣ���벢���ջ��Ԫ�أ�ÿ��Ԫ�غ���һ���ո�
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
    int pos;//ջ����ĳ���
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