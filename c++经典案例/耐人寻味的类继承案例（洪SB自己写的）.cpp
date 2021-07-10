//������������
//ĳ����ϵͳ����ͼ��ʹŴ������ü̳���ƹ����������ࡣ
//Ҫ�����£�����һ������Publication�洢�����������name������price�Լ���������date��
//��Book���Tape��ֱ����ͼ��ʹŴ������Ƕ���Publication��������
//Book����б���ͼ��ҳ�������ݳ�Աpage��Tape����б��沥��ʱ������ݳ�Աplaytime��
//ÿ���඼�й��캯���������������Ҷ������ڴӼ��̻�ȡ���ݵĳ�Ա����inputData()��
//������ʾ���ݵĳ�Ա����display()��
//��˵����display�����д�ӡ�ĸ�ʽΪ��name_price_date_(page��playtime)�س��»���Ϊһ���ո�
//�������Ķ����ʵ�֣���ͨ���������еĴ�����ԡ�
//��������ʽ��
//�������ʽ��
//���������롿
//��
//�����������
//Publication 120 1999 - 2 - 1
//Book 30 2009 - 1 - 1 300
//Tape 15 2003 - 5 - 1 00:48 : 10
//������˵����
//�����ֱ�׼��
#include <iostream>
using namespace std;

class Date//������
{
public:
	Date(){}//Date��Ĭ�Ϲ��캯��
	Date(int year, int month, int day)//Date���вι��캯��
	{
		m_year = year;
		m_month = month;
		m_day = day;
	}
	int m_year;
	int m_month;
	int m_day;
};
class Publication
{
public:
	Publication(){}
	Publication(char * name,int price,Date date)
	{
		m_name = name;
		m_price = price;
		m_date = date;
	}
	char* m_name;
	int m_price;
	Date m_date;
	void display()
	{
	cout << m_name << " " << m_price << " " << m_date.m_year << "-" << m_date.m_month << "-" << m_date.m_day << endl;
	}
};

class Book :public Publication
{
public:
	int m_page;
	Book(char* name, int price, Date date ,int page)
	{
		m_name = name;
		m_price = price;
		m_date = date;
		m_page = page;
	}
	void display()
	{
		cout << m_name << " " << m_price << " " << m_date.m_year << "-" << m_date.m_month << "-" << m_date.m_day;
		cout <<" "<<m_page << endl;
	}
};

class playtime
{
public:
	playtime(){}
	playtime(int hour,int min,int second)
	{
		m_hour = hour;
		m_min = min;
		m_second = second;
	}
	int m_hour;
	int m_min;
	int m_second;
};
class Tape :public Publication
{
public:
	playtime m_playtime;
	Tape(char* name, int price, Date date,playtime play_time)
	{
		m_name = name;
		m_price = price;
		m_date = date;
		m_playtime = play_time;
	}
	void display()
	{
		cout << m_name << " " << m_price << " " << m_date.m_year << "-" << m_date.m_month << "-" << m_date.m_day;
		cout << " "<<"0"<<m_playtime.m_hour<<":"<<m_playtime.m_min<<":"<<m_playtime.m_second << endl;
	}
	
};

void test01()
{
	Date date01(1999,2,1);
	Publication publication((char*)"Publication",120,date01);
	publication.display();

	Date date02(2009, 1, 1);
	Book book((char*)"Book",30,date02,300);
	book.display();

	Date date03(2003,5,1);
	playtime playtime01(00, 48, 10);
	Tape tape((char*)"Tape", 15, date03, playtime01);
	tape.display();
}

int main()
{
	test01();
}