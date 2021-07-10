/*2. 在一维数组中查找最大值，要求用递归实现。
【题目描述】
设递归函数Max对数组的处理区间是[low, high]，以中间位置mid将原问题分解为两个子问题，
查找区间分别是[low, mid]和[mid+1, high]，在左半区间查找最大值maxL，
在右半区间查找最大值maxR，则maxL和maxR的较大值即是区间[low, high]的最大值。
多次比较得出整个数组最大值。
【输入格式】
输入共一行，第一个数是 n 表示数组中元素的个数。
接下来有 n 个数，表示数组内各个元素的值。
【输出格式】
输出一个数表示数组中最大的元素的值。
【样例输出】
7 1 2 3 4 7 6 5
【样例输出】
7                */
#include<iostream>
using namespace std;
int mid(int m, int n) {//取中间值
	return (n - m) / 2 + m;
}
int max2(int x, int y) {//取最大值
	if (x > y) return x;
	else return y;
}
int max(int m, int n,int a[]) {//递归
	if (m == n) return a[m];//如果区间两端相等，则返回数组中的数
	else {//否则继续分
		return max2(max(m, mid(m, n), a), max(mid(m, n) + 1, n, a));//分成两个子区间，单独比较
	}
}
int main() {
	int a[100],n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << max(0, n - 1, a);//区间长度为n,下标从0到n-1
	return 0;
}