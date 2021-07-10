//插入排序
//实现数组升序排列
#include<iostream>
using namespace std;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void InsertSort(int arr[],int len)
{
	for (int i = 1; i < len; i++)
	{
		for (int j = i; i > 0; j--)
		{
			if (arr[j] < arr[j - 1]) Swap(arr[j], arr[j - 1]);
			else break;
		}
	}
}

void PrintArray(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	int arr[] = { 1,2,5,6,9,2,55,2,8,2,6 };
	int len = sizeof(arr) / sizeof(int);
	InsertSort(arr, len);
	PrintArray(arr, len);
}