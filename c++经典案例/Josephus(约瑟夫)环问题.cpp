//Josephus(约瑟夫)环问题
//案例描述：
//n个人围成一个环，从第i个开始，由1至interval(间隔,间距)不断报数，凡报到interval的出列，
//直到环空为止。出列的人按先后顺序构成一个新的序列。
#include<iostream>
#include<iomanip>
using namespace std;
struct Jonse
{
	int code;
	Jonse* next;
};

Jonse* Create(int);
void ShowList(Jonse*);
void Out(Jonse*, int, int);
int main()
{
	Jonse* head ;
	int num, val, beg;//num表示总人数，beg表示开始报数的位置，val表示报数间隔
	cout << "请输入总人数" << endl;
	cin >> num;
	head = Create(num);//创建链环
	ShowList(head);//输出链环序号
	cout << endl;
	cout << "请输入开始的编号" << endl;
	cin >> beg;//输入开始数数的位置
	cout << "请输入报数间隔" << endl;
	cin >> val;//输入报数间隔
	cout << "新的链表为" << endl;
	Out(head, beg, val);//输出新序列并删除链表
}

Jonse* Create(int n)
{
	Jonse* h , * p ;
	int i;
	h = new Jonse;
	p = h;
	for (i = 1; i <= n; i++)
	{
		p->code = i;//赋给每个节点序号
		if (i < n)
		{
			p->next = new Jonse;
			p = p->next;
		}
	}
	p->next = h;//这个操作目的是为了构成环
	return h;//返回的是头节点的指针
}

void ShowList(Jonse* h)
{
	Jonse* p;
	p = h;
	do//输出链环
	{
		cout << p->code <<'\t';
		p = p->next;
	} while (p != h);//注意循环条件
}

void Out(Jonse* h, int i, int d)
{
	Jonse* p , * q ;
	int k;
	p = h;
	//q是p的前驱指针，指向最后建立的节点
	for (q = h; q->next != h; q = q->next) ;
		for (k = 1; k < i; k++)//寻找开始报数的位置
		{
			q = p;
			p = p->next;
		}
		while (p != p->next)//处理链环，直至剩下一个节点
		{
			for (k = 1; k < d; k++)//报数
			{
				q = p;
				p = p->next;
			}
			cout << p->code << endl;//输出报到d的点
			q->next = p->next;//删除节点
			delete p;
			p = NULL;
			p = q->next;
	    }
		cout << p->code << endl;//处理最后一个节点
		delete p;
		p = NULL;
}