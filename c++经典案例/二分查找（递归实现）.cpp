//二分查找
//简单查找的时间复杂度为O(n)
//二分查找的时间复杂度为O(logn)
//用递归实现二分查找：
//基线条件：数组只包含一个元素。如果如果要查找的值与这个元素相同，就找到了；否则说明不在数组中。
//递归条件：把数组分成两半，将其中一半丢弃，并对另一半执行二分查找。

//我个人对二分查找的补充说明：
//1.传入的数据必须是已经排序好的（最好是升序排列，便于理解）
//2.二分查找的用途比较狭窄：适用范围小（仅限于可以比较的数据）,只能用于查找数组中是否存在目标数据
#include<iostream>
using namespace std;

//n为目标数据、left为数组第一个元素下标、right为数组最后一个元素下标
//一定要注意是下标呀！
int func(int arr[],int left , int right , int n)
{
	if (left == right && arr[left] == n)  return left;
	else if (left < right)
	{
		int mid = (left + right) / 2;
		if (n > arr[mid])   return func(arr, mid+1, right, n);//这里的+1 和 -1是必须的，否则程序运行错误
		else if (n < arr[mid])  return  func(arr, left, mid-1, n);
		else return mid;
	}
	return -1;
}

int main()
{
	//注意数组一定要是排序好了的，最好是升序排列！
	//一定要注意这点
	int arr[] = { 0,1,2,3,4,5,6,7,8,9};
	cout << "请输入要查询的数字" << endl;
	int n;
	cin >> n;
	int result = func(arr, 0, 9 , n);
	if (result == -1)
	{
		cout << "未找到该数据" << endl;
	}
	else
	{
		cout << "找到该数据，该数据即为数组中的arr[" << result << "]" << endl;
	}
}