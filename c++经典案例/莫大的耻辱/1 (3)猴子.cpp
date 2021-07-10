#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<ctime>
#include<list>
#include<vector>
using namespace std;
list<int>list1;
int main()
{
	int m, n;
	cin >> m >> n;
	int * monkey = new int[m];
	for (int i = 0; i < m; i++)
	{
		monkey[i] = i + 1;
		list1.push_back(monkey[i]);
	}
	list<int>::iterator it = list1.begin();
	list<int>::iterator pos = list1.begin();
	while (list1.size() > 1)
	{
		for (int i = 1; i < n; i++)
		{
			it++;
			if (it == list1.end())
				it = list1.begin();
		}
		it = list1.erase(it);
		if (it == list1.end())
			it = list1.begin();
	}
	it = list1.begin();
	cout << *it;
	return 0;
}
