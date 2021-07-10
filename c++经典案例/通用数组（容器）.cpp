//用容器实现通用数组的排列（升序）
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

template<typename T>
vector<T> mySort(T arr[], int len)
{
	vector<T>v;
	for (int i = 0; i < len; i++)
	{
		v.push_back(arr[i]);
	}

	//注意要包含标准算法的头文件
	sort(v.begin(), v.end());
	return v;
}

template<typename T>
void printVector(vector<T> v)
{
	for (vector<T>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test01()
{
	char arr01[] = "qwertyuiopasdfghjklzxcvbnm";
	int len01 = sizeof(arr01) / sizeof(char) - 1;
	vector<char>v1 = mySort<char>(arr01, len01);
	printVector(v1);

	int arr02[] = { 5,8,2,4,6,7,9,1,3 };
	int len02 = sizeof(arr02) / sizeof(int);
	vector<int>v2 = mySort<int>(arr02, len02);
	printVector(v2);
}

int main()
{
	test01();
}