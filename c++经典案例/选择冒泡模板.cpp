#include<iostream>
using namespace std;

template<typename T>//Ñ¡ÔñÅÅĞòµÄÉùÃ÷
void func02(T arr[], int len);

template<typename T>//½»»»´úÂë
void Swap(T &a, T &b)
{
	T temp = a;
	a = b;
	b = temp;
	return;
}

template<typename T>//Ã°ÅİÅÅĞò
void func01(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
				Swap(arr[j], arr[j + 1]);
		}
	}
}

template<typename T>
void PrintArr(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<typename T>//Ñ¡ÔñÅÅĞò
void func02(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[j] < arr[min])  min = j;
		}
		if (min != i)  Swap(arr[min], arr[i]);
	}
}

void test01()
{
	char a[] = "asddgeg";
	int b[] = { 1,2,8,9,6,9,2,5,8,8,2 };
	int a_len = sizeof(a) / sizeof(char) - 1;
	int b_len = sizeof(b) / sizeof(int);
	func01(a, a_len); PrintArr(a, a_len);
	func02(a, a_len); PrintArr(a, a_len);

	func01(b, b_len); PrintArr(b, b_len);
	func02(b, b_len); PrintArr(b, b_len);
}

int main()
{
	test01();
}