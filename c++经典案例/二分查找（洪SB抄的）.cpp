//���ֲ���
#include<iostream>
using namespace std;

int func(int arr[], int left, int right, int x)
{
	if (left == right && arr[left] == x) return left;
	if (left < right)
	{
		int mid = (left + right) / 2;
		if (arr[mid] == x) return mid;
		else if (arr[mid] < x) return func(arr, mid + 1, right, x);
		else return func(arr, left, mid - 1, x);
	}
	return -1;
}

void test01()
{
	int arr[] = { 1,3,5,7,9,11,13,15,17,19,21,23,25,27,29 };
	int len = sizeof(arr) / sizeof(int);

	cout << "������Ҫ���ҵ�����" << endl;
	int x;//x����Ҫ���ҵ�����
	cin >> x;

	int result = func(arr, 0, len - 1, x);
	if (result == -1)
	{
		cout << "δ���ҵ�����" << endl;
	}
	else
	{
		cout << "���ҵ�������" << endl;
		cout << "�������������е�arr[" << result << "]λ��" << endl;
	}
}

int main()
{
	test01();
}