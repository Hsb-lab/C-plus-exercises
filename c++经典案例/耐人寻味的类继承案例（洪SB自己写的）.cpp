//【问题描述】
//某出版系统发行图书和磁带，利用继承设计管理出版物的类。
//要求如下：建立一个基类Publication存储出版物的名称name，单价price以及出版日期date。
//用Book类和Tape类分别管理图书和磁带，它们都从Publication类派生。
//Book类具有保存图书页数的数据成员page，Tape类具有保存播放时间的数据成员playtime。
//每个类都有构造函数，析构函数，且都有用于从键盘获取数据的成员函数inputData()，
//用于显示数据的成员函数display()。
//（说明：display函数中打印的格式为：name_price_date_(page或playtime)回车下划线为一个空格）
//请完成类的定义和实现，并通过主函数中的代码测试。
//【输入形式】
//【输出形式】
//【样例输入】
//无
//【样例输出】
//Publication 120 1999 - 2 - 1
//Book 30 2009 - 1 - 1 300
//Tape 15 2003 - 5 - 1 00:48 : 10
//【样例说明】
//【评分标准】
#include <iostream>
using namespace std;

class Date//日期类
{
public:
	Date(){}//Date的默认构造函数
	Date(int year, int month, int day)//Date的有参构造函数
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