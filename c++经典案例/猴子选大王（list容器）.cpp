//����ѡ��������list�����
#include <list>
#include<iostream>
using namespace std;

int main() {
	list<int>monkeys;
	int n, m;  //n����һ���м�ֻ���� m��������m�ĺ����˵�Ȧ��
	while (true) {
		cin >> n >> m;
		if (n == 0 || m == 0)  break;
		monkeys.clear();  //���list����
		for (int i = 1; i <= n; ++i)
			monkeys.push_back(i);
		list<int>::iterator it = monkeys.begin(); //��������� ָ��list�ĵ�һ��λ�� Ҳ���ǿ�ʼλ��
		while (monkeys.size() > 1) { //ֻҪ���в�ֹһֻ���ӣ���Ҫ��һֻ�����������
			for (int i = 1; i < m; ++i) { //����
				++it; //������ͬ��������
				if (it == monkeys.end())  it = monkeys.begin();//��������ĺ���һ��λ�� �򷵻���ǰ��
			}
			//����ѭ��˵�������Ϊm����ֻ������  
			it = monkeys.erase(it);//�߳������߳��� ������ָ���һ��λ��
			if (it == monkeys.end()) it = monkeys.begin();//����߳���ָ���һ��λ����������� �򷵻�ǰ��
		}
		cout << monkeys.front() << endl;  //front�������ص�һ��Ԫ�� Ҳ�������ʣ�µ��Ǹ�Ԫ�ص�����
	}
	return 0;
}