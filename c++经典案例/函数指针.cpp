//����ָ��
//C++�У������ùؼ���typedef���庯�������������������������һ����ʽΪ��
//typedef ���� ��������������ʽ�����б�
//����������ͳ˧������������ͬ���ͺ�������������ͬ��������־�ı���(��ֻ����ս���Ȩ���SB����)


#include<iostream>
using namespace std;
typedef void FuncType(int, int);
FuncType max, min;
typedef void (*pType)(int, int);
pType p1,p2;

int main()
{
	p1 = max;
	p2 = min;
	p1(10, 20);
	cout << endl;
	p2(10, 20);
}
void max(int a, int b)
{
	if (a > b) cout << a;
	else cout << b;
}
void min(int a, int b)
{
	if (a < b) cout << a;
	else cout << b;
}