//����ʽϵ����(�������)
#include<iostream>
using namespace std;

//����i�е�j��Ԫ�ظ�ֵ
void func01(int** array, int i, int j)
{
	if (i == j || j == 0)
	{
		array[i][j] = 1;
		return;
	}
	else
	{
		array[i][j] = array[i - 1][j] + array[i - 1][j - 1];
		return;
	}
}

int main()
{
	int n;
	cin >> n;
	int len = n + 1;

	//������ά����
	int** arr = new int* [len];//������ָ��
	for (int i = 0, j = 1; i < len; i++, j++)
	{
		arr[i] = new int[j];
	}

	//����λ�����е�Ԫ�ظ�ֵ
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			func01(arr, i, j);
		}
	}

	//��ֵ��ά����
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	//�ͷŶ����ڴ�
	for (int i = 0; i < len; i++)
	{
		delete arr[i];
		arr[i] = NULL;
	}
}