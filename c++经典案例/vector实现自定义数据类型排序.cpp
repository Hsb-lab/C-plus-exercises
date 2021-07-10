//vectorʵ���Զ���������������
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Person
{
public:
	Person(string name,int age,int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

//ʵ�ִ�ӡ�����ĺ���
void PrintVector(vector<Person>v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������" << it->m_Name << " ���䣺" << it->m_Age << " ��ߣ�" << it->m_Height << endl;
	}
}

//ʵ�ֱȽϹ��ܵĺ���
bool MyCompare(Person &p1,Person &p2)
{
	if (p1.m_Age == p2.m_Age) return p1.m_Height > p2.m_Height;
	else return p1.m_Age > p2.m_Age;
}

void test01()
{
	Person p1("��˿��",17,170);
	Person p2("ͩ��", 15, 170);
	Person p3("���������", 18, 170);
	Person p4("ͩ�Ⱥ���", 15, 175);

	vector<Person>v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	sort(v.begin(), v.end(),MyCompare);
	PrintVector(v);
}

int main()
{
	test01();
}