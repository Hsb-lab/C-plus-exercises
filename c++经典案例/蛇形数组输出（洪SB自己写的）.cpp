//����Ŀ������
//�� n* n����������1��2����n* n��Ҫ��������Ρ����� n = 4 ʱ����Ϊ��
//10 11 12 1
//9 16 13 2
//8 15 14 3
//7 6 5 4
//����ķ����У�����Ŀո�ֻ��Ϊ�˱��ڹ۲���ɣ������ϸ������n <= 10
//�������ʽ��
//һ��һ�и�����n
//�������ʽ��
//һ�� n * n �ľ����ʾ����������Ľ����
//Ҫ��ÿһ������Ҫռ4λ�������ÿո�ȫ��
//���������롿
//2
//�����������
//4 1
//3 2
#include <iostream>
using namespace std;
void func(int ** arr, int n)
{
	static int count = 1;
	static int  x = 0;
	for (int i = 0 + x ; i < n-x; i++)//��������������
	{
		arr[i][n-1-x] = count++;
	}

	for (int i = n - 2 - x; i >= 0+x; i--)//��������������
	{
		arr[n - 1 - x][i] = count++;
	}

	for (int i = n - 2 - x; i >= 0+x; i--)//��������������
	{
		arr[i][0+x] = count++;
	}

	for (int i = 1 + x; i <= n - 2 - x; i++)//��������������
	{
		arr[0+x][i] = count++;
	}
	x++;
	if ((n-x*2)== -1 ||(n-x*2) == 0)   return;
	else  func(arr, n);
}

int main()
{
	int n; cin >> n;//n����n*n�ľ���
	int** arr = new int* [n];//������̬��ά����
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}
	func(arr, n);
	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n ; j++)
		{   
			cout << arr[i][j] << "   ";
			if (j == n - 1)  cout << endl;
		}
	}
}