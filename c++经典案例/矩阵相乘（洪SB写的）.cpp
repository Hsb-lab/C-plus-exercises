#include<iostream>
using namespace std;

int ** func01(int row , int col)//������̬��ά����
{
	int** a_Arr = new int* [row];//������ָ��
	for (int i = 0; i < row; i++)
	{
		a_Arr[i] = new int[col];//��ÿһ�з����ڴ�
	}
	cout << "������Ԫ��" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> a_Arr[i][j];
		}
	}
	return a_Arr;
}

//�������ʱ���������������⣺
//������ ���� ˵�� ��Ŀ �ļ� �� ��ֹ��ʾ״̬ ���� C3861 ��managerMenu�� : �Ҳ�����ʶ��
//ԭ��ʱ���ú�������֮ǰû�б�д���������������������ǰ����뺯��������
int func03(int** p1, int** p2, int i, int j, int col_1, int row_2);

int** func02(int** p1, int row_1, int col_1, int** p2, int row_2, int col_2)//������˺������
{
	int** a_Arr = new int* [row_1];//������ָ��
	for (int i = 0; i < row_1; i++)
	{
		a_Arr[i] = new int[col_2];//��ÿһ�з����ڴ�
	}

	for (int i = 0; i < row_1; i++)
	{
		for (int j = 0; j < col_2; j++)
		{
			a_Arr[i][j] = func03(p1, p2, i, j,col_1,row_2);//��ʵ����col_1 = row_2
		}
	}
	return a_Arr;
}

int func03(int** p1, int** p2,int i,int j,int col_1,int row_2)//������������˲���
{
	int sum = 0;
	for (int q = 0; q < col_1; q++)
	{
		sum += p1[i][q] * p2[q][j];
	}
	return sum;
}

int main()
{
	int row, col;//row������������һ���ж��ٸ���col������������һ���ж��ٸ�
	cout << "����������������" << endl;
	cin >> row >> col;
	int m = row; int n = col;
	int** p1 = func01(m, n);//������һ������

	cout << "���ٴ���������������" << endl;
	cin >> row >> col;
	if (n != row)
	{
		cout << "���SB���������" << endl;
		cout << "��һ�����������Ӧ����ڶ���������������" << endl;
		cout << "����������������һ�ΰ�" << endl;
		return 0;
	}
	int** p2 = func01(row, col);//�����ڶ�������

	int ** p = func02(p1,m,n,p2,row,col);

	cout << "������˺�ľ���Ϊ" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << p[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}