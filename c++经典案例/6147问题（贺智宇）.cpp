//6174问题
#include<iostream>
#include<cmath>
using namespace std;
//排序
int order(int m, int arr[10])
{
	int temp;
	for (temp = 0; m % 10 >= 0 && m != 0; temp++)
	{
		arr[temp] = m % 10;
		m = m / 10;
	}
	for (int temp_2 =temp; temp_2 >= 0; temp_2--)
	{
		for (int temp_3 = 0; temp_3 < temp_2; temp_3++)
			if (arr[temp_3] <= arr[temp_3 + 1])
			{
				int temp_4 = arr[temp_3 + 1];
				arr[temp_3 + 1] = arr[temp_3];
				arr[temp_3] = temp_4;
			}
	}
	return arr[10];
}
//找截至下标(包含0)
int flagNum(int arr[10])
{
	int flag_temp = 0;
	for (flag_temp = 0; arr[flag_temp] != -1; )
	{
		flag_temp++;
	}
	return flag_temp;
}
//算最大值
int Max(int arr[], int flag)
{
	int max = 0;
	for (int temp_5 = 0; temp_5 < flag; temp_5++)
	{
		max = max + pow(10, flag-temp_5-1) * arr[temp_5];
	}
	return max;
}
//算最小值
int Min(int arr[], int flag)
{
	int min = 0;
	for (int temp_4 = 0; temp_4 < flag; temp_4++)
	{
		min = min + pow(10, temp_4) * arr[temp_4] ;
	}
	return min;
}
//判断是否有相等值
int equal(int arr_Num[], int num)
{
	for (int temp = 0; temp < num; temp++)
	{
		if (arr_Num[num] == arr_Num[temp] && arr_Num[num] != 0)
		{
			return 5;
		}
	}
	return 0;
}
int main()
{
	int m;
	int num = 0;
	int ret = 0;
	cin >> m;
	int arrNum[1000] = {};
	for (num = 0; ret == 0; num++)
	{
		arrNum[num] = m;
		ret = equal(arrNum, num);
		int arr[10] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1 };
		order(m, arr);
		int flag = flagNum(arr);
		int max = Max(arr, flag);
		int min = Min(arr, flag);
		m = max - min;
	}
	
	for (int x = 0; x < num; x++)
	{
		cout << arrNum[x] <<" ";
	}

	return 0;
}