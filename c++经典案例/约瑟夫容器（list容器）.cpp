//Josephus环问题（用list容器实现）
//n个人围成一个圆环，从第i个开始，由1至interval（间隔，间距）不断报数，凡报到interval的出列，
//直到环空为止。出列的人按先后顺序构成一个新的序列。
#include<iostream>
using namespace std;
#include<list>

//创建约瑟夫环
void CreateCircle(list<int> & L, int n)//要用引用的方式（懂得都懂）
{
	for (int i = 0; i < n; i++)
	{
		L.push_back(i+1);
	}
}

//功能函数
void func(list<int>L, int begin, int interval)
{
	list<int>::iterator it = L.begin();

	//寻找开始的位置
	for (int i = 0; i < begin - 1; i++)
	{
		it++;
		if (it == L.end()) it = L.begin();
	}

	//开始进入约瑟夫环
	while (L.size() != 0)
	{
		for (int i = 0; i < interval - 1; i++)
		{
			it++;
			if (it == L.end()) it = L.begin();
		}
		cout << *it << " ";
		it = L.erase(it);
		if (it == L.end()) it = L.begin();
	}
	cout << endl;
}

void test01()
{
	list<int>L;
	cout << "请输入总人数" << endl;
	int n;//n代表总人数
	cin >> n;
	CreateCircle(L,n);//创建约瑟夫环

	//测试代码 
	//for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	cout << "请输入开始位置" << endl;
	int begin;//begin代表开始位置
	cin >> begin;

	cout << "请输入间隔" << endl;
	int interval;//interval代表间隔
	cin >> interval;

	func(L, begin, interval);
}

int main()
{
	test01();
}