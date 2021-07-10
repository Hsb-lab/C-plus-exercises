//放苹果（可一次测量多组数据）
//把M个同样的苹果放在N个同样的盘子里，允许有的盘子空着不放，问公有多少种不同的分法？
#include<iostream>
using namespace std;
#define MAXSIZE 21 
int layApple(int m, int n) {
	//将0个苹果放在n个盘中，有1种放法，即全部为空。 
	if (m == 0) {
		return 1;
	}
	//将m个苹果放在0个盘子中，没有放法。 
	if (n == 0) {
		return 0;
	}
	//将m个苹果放在n个盘子中，我们可以分情况讨论
	//1.当m小于n时，即苹果数小于盘子数，由于苹果盘子均相同，所以m个苹果放在n个盘子中，相当于m个苹果放在m个盘子中 
	if (m < n) {
		return layApple(m, m);
	}
	//2.当m大于n时，即苹果数大于盘子数，这时候又可以将其分为两种情况，两种情况所产生的方法总和 
	//2.1.有盘子为空，则最少有1个盘子为空，那么方法总数等于将m个苹果放在n-1个盘子中
	//2.2.没有盘子为空，则相当于每个盘子都放了一个，转化为m-n个苹果放在了n个盘子中。 
	else {
		return layApple(m - n, n) + layApple(m, n - 1);
	}
}
int main() {
	int m, n;		//m个苹果放在n个盘子里 
	int* result = new int[MAXSIZE];
	int t;			//测试数据的数目
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> m >> n;
		result[i] = layApple(m, n);
	}
	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	return 0;
}