//Josephus�����⣨��list����ʵ�֣�
//n����Χ��һ��Բ�����ӵ�i����ʼ����1��interval���������ࣩ���ϱ�����������interval�ĳ��У�
//ֱ������Ϊֹ�����е��˰��Ⱥ�˳�򹹳�һ���µ����С�
#include<iostream>
using namespace std;
#include<list>

//����Լɪ��
void CreateCircle(list<int> & L, int n)//Ҫ�����õķ�ʽ�����ö�����
{
	for (int i = 0; i < n; i++)
	{
		L.push_back(i+1);
	}
}

//���ܺ���
void func(list<int>L, int begin, int interval)
{
	list<int>::iterator it = L.begin();

	//Ѱ�ҿ�ʼ��λ��
	for (int i = 0; i < begin - 1; i++)
	{
		it++;
		if (it == L.end()) it = L.begin();
	}

	//��ʼ����Լɪ��
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
	cout << "������������" << endl;
	int n;//n����������
	cin >> n;
	CreateCircle(L,n);//����Լɪ��

	//���Դ��� 
	//for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	//{
	//	cout << *it << " ";
	//}
	//cout << endl;

	cout << "�����뿪ʼλ��" << endl;
	int begin;//begin����ʼλ��
	cin >> begin;

	cout << "��������" << endl;
	int interval;//interval������
	cin >> interval;

	func(L, begin, interval);
}

int main()
{
	test01();
}