//猴子选大王（用list解决）
#include <list>
#include<iostream>
using namespace std;

int main() {
	list<int>monkeys;
	int n, m;  //n代表一共有几只猴子 m代表数到m的猴子退到圈外
	while (true) {
		cin >> n >> m;
		if (n == 0 || m == 0)  break;
		monkeys.clear();  //清空list容器
		for (int i = 1; i <= n; ++i)
			monkeys.push_back(i);
		list<int>::iterator it = monkeys.begin(); //定义迭代器 指向list的第一个位置 也就是开始位置
		while (monkeys.size() > 1) { //只要还有不止一只猴子，就要找一只猴子让其出列
			for (int i = 1; i < m; ++i) { //报数
				++it; //迭代器同步跟着走
				if (it == monkeys.end())  it = monkeys.begin();//如果到最后的后面一个位置 则返回最前面
			}
			//跳出循环说明到序号为m的那只猴子了  
			it = monkeys.erase(it);//踢出它！踢出后 迭代器指向后一个位置
			if (it == monkeys.end()) it = monkeys.begin();//如果踢出后指向后一个位置是最后的最后 则返回前面
		}
		cout << monkeys.front() << endl;  //front函数返回第一个元素 也就是最后剩下的那个元素的引用
	}
	return 0;
}