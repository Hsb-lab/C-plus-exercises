//vector实现自定义数据类型排序
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

//实现打印容器的函数
void PrintVector(vector<Person>v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高：" << it->m_Height << endl;
	}
}

//实现比较功能的函数
bool MyCompare(Person &p1,Person &p2)
{
	if (p1.m_Age == p2.m_Age) return p1.m_Height > p2.m_Height;
	else return p1.m_Age > p2.m_Age;
}

void test01()
{
	Person p1("亚丝娜",17,170);
	Person p2("桐人", 15, 170);
	Person p3("结城明日奈", 18, 170);
	Person p4("桐谷和人", 15, 175);

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