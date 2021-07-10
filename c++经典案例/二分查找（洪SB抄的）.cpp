//二分查找
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

	cout << "请输入要查找的数据" << endl;
	int x;//x代表要查找的数据
	cin >> x;

	int result = func(arr, 0, len - 1, x);
	if (result == -1)
	{
		cout << "未查找到数据" << endl;
	}
	else
	{
		cout << "查找到该数据" << endl;
		cout << "该数据再数组中的arr[" << result << "]位置" << endl;
	}
}

int main()
{
	test01();
}