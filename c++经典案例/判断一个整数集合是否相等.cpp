//【题目描述】
//给定两个集合A和B，判断他们是否相等。(集合元素可能需要去重) 。
//如果两个集合相等，则输出"yes"，否则输出"no"
//【输入格式】
//两行分别表示集合 A 和 B ，每一行先输入一个数 n 表示集合的大小，接下来输入 n 个数表示集合的元素
//【输出格式】
//按要求输出 "yes" 或 "no" (不带引号)
//【输入样例】
//4 1 2 3 4
//4 4 3 2 1
//【输出样例】
//yes
//【样例解释】
//第一个集合里不重复的元素为{ 1,2,3,4 }，第二个集合也为{ 1,2,3,4 }，故两个集合相等
#include <iostream>
using namespace std;
//给集合排序的函数
void func01(int*& arr_i, int len)//传入数组和数组的长度
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr_i[j] > arr_i[j + 1])
			{
				int temp = arr_i[j];
				arr_i[j] = arr_i[j + 1];
				arr_i[j + 1] = temp;
			}
		}
	}
}

//给集合去重的函数
int* func02(int* arr_i, int& n)
{
	int len = n;
	for (int i = 0; i < n; i++)
	{
		if (arr_i[i] == arr_i[i + 1]) len--;
	}

	int* array = new int[len];
	for (int i = 0, j = 0; i < n - 1; i++)
	{
		if (arr_i[i] == arr_i[i + 1]) continue;
		else { array[j] = arr_i[i]; j++; }
	}
	array[len - 1] = arr_i[n - 1];
	n = len;
	return array;
}

//判断两个集合是否相等的函数
int func03(int* p1, int* p2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p1[i] != p2[i]) { return 0; }
		if (p1[n - 1] == p2[n - 1] && i == (n - 1)) { return 1; }

	}

}
int main()
{    //创建第一个集合
	int n1, m1, x1; cin >> n1; m1 = n1; //n1表示输入元素的个数，m1是工具人,x1表示输入的数据
	int* arr_1 = new int[n1];
	int i = 0;//i为工具人
	while (m1)//将输入的数据赋值到动态数组中
	{
		cin >> x1;  arr_1[i] = x1;
		i++;
		m1--;
	}
	//创建第二个集合
	int n2, m2, x2; cin >> n2; m2 = n2; //n2表示输入元素的个数，m2是工具人,x2表示输入的数据
	int* arr_2 = new int[n2];
	int j = 0;//i为工具人
	while (m2)//将输入的数据赋值到动态数组中
	{
		cin >> x2;  arr_2[j] = x2;
		j++;
		m2--;
	}
	//利用函数给集合排序
	func01(arr_1, n1);
	func01(arr_2, n2);

	/*for (int temp = 0; temp < n1; temp++)
	{
		cout << arr_1[temp] << " ";
	}
	cout << endl;
	for (int temp = 0; temp < n2; temp++)
	{
		cout << arr_2[temp] << " ";
	}
	cout << endl;*/

	//利用函数给集合去重
	int* p1 = func02(arr_1, n1);
	int* p2 = func02(arr_2, n2);

	/*for (int temp = 0; temp < n1; temp++)
	{
		cout << p1[temp] << " ";
	}
	cout << endl;
	for (int temp = 0; temp < n2; temp++)
	{
		cout << p2[temp] << " ";
	}
	cout << endl;
	cout << n1 << " " << n2 << endl;*/
	//判断两个集合是否相等
	if (n1 != n2)  cout << "no" << endl;
	else {
		if (func03(p1, p2, n1)) { cout << "yes" << endl; return 0; }
		else  cout << "no" << endl;
	}
}