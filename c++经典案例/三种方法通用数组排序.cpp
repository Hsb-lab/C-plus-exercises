//ͨ������������������
//ʹ�����ַ�����ѡ������ð�����򡢲�������
//�������ɣ���������sizeof(T)�Ĳ�ͬ���жϲ�ͬ���������ͣ���ϧ�����������û�еõ�ʵ�֣����أ�

#include<iostream>
using namespace std;

//ʵ�ֽ������ܵĺ���
template<typename T>
void Swap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}

//��������
template<typename T>
void InsertSort(T arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j] < arr[j - 1])  Swap(arr[j], arr[j - 1]);
			else break;
		}
	}
}

//ѡ������
template<typename T>
void ChooseSort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i + 1; j < len; j++)
		{
			if (arr[min] > arr[j]) min = j;//�����±�
		}
		if (min != i)
			Swap(arr[min], arr[i]);
	}
}

//ð������
template<typename T>
void BubbleSort(T arr[] , int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

//ʵ���������ĺ���
template<typename T>
void printArray(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test01()
{
	char arr01[] = "rhrtgasdfasdghrthrfeqfqfsxdfrg";
	int len01 = sizeof(arr01)/sizeof(char) - 1;
	//BubbleSort(arr01, len01);
	//ChooseSort(arr01, len01);
	InsertSort(arr01, len01);
	printArray(arr01, len01);

	int arr02[] = { 1,5,5,2,8,2,8,2,8,2,8,2,67,882,8,5285 };
	int len02 = sizeof(arr02)/sizeof(int);
	//BubbleSort(arr02, len02);
	//ChooseSort(arr02, len02);
	InsertSort(arr01, len01);
	printArray(arr02, len02);

}

int main()
{
	test01();
}