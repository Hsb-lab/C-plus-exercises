//����Ŀ������
//��������һ����λ���ֻ�����ͬ����λ�������������ִӴ�С�����õ�a����С���������õ�b��
//Ȼ����a - b�滻ԭ�����������Ҽ���������
//��Ȥ�������������˼��κ��õ���λ��6174������6174���д���Ϊ7641 - 1467 = 6174���ص������Լ���
//����һ��nλ������һ������λ����������������У�ֱ����һ�γ���ѭ����
//���뱣֤��ѭ��֮ǰ���ֻ�����1000��������
//ע�⣺������0�������
//�������ʽ��
//һ��һ������
//�������ʽ��
//һ�������������(����һ��ʼ����)
//��ע�������е�ÿ����ͨ��һ���ո��������
//����������1��
//1234
//���������1��
//1234 3087 8352 6174 6174
//����������2��
//1234567
//���������2��
//1234567 6419754 8319762 8639532 7529643 7419753 8429652 7619733
//8439552 7509843 9529641 8719722 8649432 7519743 8429652
#include<iostream>
#include <cmath>
using namespace std;
//��ȡnλ���ĺ���01
int func01(int n)
{
	return log10(n) + 1;
}

//��ȡ�����n�����ֵ02
int func02(int arr[], int len)
{
	int sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i] * pow(10, i);
	}
	return sum;
}

//��ȡ�����n����Сֵ03
int func03(int arr[], int len)
{
	int sum = 0;
	for (int i = len-1, j= 0; i >=0 ; i--)
	{
		sum += arr[i] * pow(10, j); j++;
	}
	return sum;
}

//��ȡ��������ֵ�����������ֵ��ȥ��Сֵ��
int func04(int n)
{
	int len = func01(n);//len��ʾn��λ��
	int* arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = (n % 10); n /= 10;
	}

	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	return func02(arr, len) - func03(arr, len);

}
int main()
{
	int n; cin >> n; if (n == 0)  return 0;
	cout << n << " ";//n��ʾ������������� 
	int x = 0; int array[1000] ;  array[0] = n;
	while (1)
	{
		cout << func04(n) <<" "; x++;
		array[x] = func04(n);
		for (int i = 0; i < x; i++)
		{
			if (array[x] == array[i])
			{
			  return 0;
		}

		}
		
		n = func04(n);
	}
	return 0;
}