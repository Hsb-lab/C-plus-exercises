//利用容器实现通用数组（实现降序）
#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

//创建容器的函数
template<typename T>
vector<T> func01(T arr[],int len)
{
	vector<T>v;
	for (int i = 0; i < len; i++)
	{
		v.push_back(arr[i]);
	}
	return v;
}

//实现排序的函数
template<typename T>
void Sort(vector<T> &v)//一定要用引用的方式传入（懂得都懂）
{
	sort(v.rbegin(), v.rend());
}

//输出容器的函数
template<typename T>
void PrintVector(const vector<T> &v)
{
	for (vector<T>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	char arr01[] = "fergetgbhwefghqwefgghjerhguyjeryhuirehuikeyhtygt";
	int len01 = sizeof(arr01) / sizeof(char) - 1;
	vector<char>v1 = func01(arr01, len01);
	Sort(v1);
	PrintVector(v1);

	int arr02[] = {1,5,456,123,89,62,49,23,59,26 };
	int len02 = sizeof(arr02) / sizeof(int);
	vector<int>v2 = func01(arr02, len02);
	Sort(v2);
	PrintVector(v2);
}

int main()
{
	test01();
}