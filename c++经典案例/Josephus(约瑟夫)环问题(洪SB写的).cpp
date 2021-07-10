//Josephus(约瑟夫)环问题
//案例描述：
//n个人围成一个环，从第i个开始，由1至interval(间隔,间距)不断报数，凡报到interval的出列，
//直到环空为止。出列的人按先后顺序构成一个新的序列。
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

Node* CreateCircle(int num)//创建圆环
{
	Node* p = NULL, * s = NULL,*head = NULL;//两工具人指针
	p = new Node;
	head = p;//s将头指针的地址保留，以免地址值被覆盖
	p->data = 1;
	p->next = NULL;
	for (int i = 2; i <= num; i++)
	{
		s = new Node;
		s->data = i;
		s->next = NULL;
		p->next = s;
		p = s;
	}
	p->next = head;
	return head;
}

void ShowCircle(Node* head)
{
	Node* p = head;//保存头指针
	do
	{
		cout << head->data << " ";
		head = head->next;
	} while (head != p);
	cout << endl;
}

void ShowJosephusCircle(Node * head,int begin,int d)//输出约瑟夫环
{
	Node* p = NULL; Node* s = NULL,*q = NULL;//创建两个工具人指针
	q = head;//保存头节点的地址
	for (s = head; s->next != head; s = s->next)
	{
		if (s->data == begin)
		{
			while (s != s->next)//剩最后一个节点时结束循环
			{
				for (int k = 1; k < d; k++)
				{
					p = s;//p保留上一个节点的地址
					s = s->next;
				}
				cout << s->data << " ";//输出报到d的节点
				p->next = s->next;
				delete s;//删除节点
				s = NULL;
				s = p->next;
			}
			cout << s->data << endl;//处理最后一个节点
			delete s;
			s = NULL;
			return;
		}
	}
}

int main()
{
	int num, begin, d;//num表示总人数，begin表示开始的位置，d代表报数间隔
	cout << "请输入总人数" << endl;
	cin >> num;
	Node* head = CreateCircle(num);//创建圆环，获取头指针
	cout << "创建的圆环为" << endl;
	ShowCircle(head);
	cout << "请输入开始报数的位置" << endl;
	cin >> begin;
	cout << "请输入报数间隔" << endl;
	cin >> d;
	ShowJosephusCircle(head, begin, d);
}