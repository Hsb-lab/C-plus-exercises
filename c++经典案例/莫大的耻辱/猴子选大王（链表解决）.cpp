//有M（1 000以内）个猴子围成一圈，每个猴子有一个编号，编号从1到M，
//打算从中选出一个大王。经过协商，决定选大王的规则如下：
//从第1个猴子开始，每隔N（任意正整数）个，数到的猴子出圈，
//最后剩下来的就是大王。要求从键盘输入M、N（均为正整数），
//试编程计算编号为多少的猴子将成为大王。
//要求：
//1、用变量m表示猴子的个数；变量n表示出圈数数的基数。
//2、数数规则：每次从1数到n，当前为n的猴子出圈，若有3个猴子，n为2，
//猴子编号：1, 2, 3，出圈猴子的序号：2，1，猴子大王的序号为3。
//3. 请用链表实现（参考课本的约瑟夫环）
//【样例】
//输入：
//３　２
//输出：
//3

#include<iostream>
using namespace std;

//结构体
struct Node
{
	int data;
	Node *next;
};

//创建约瑟夫环的函数
Node* CreateList(int m)
{
	Node* head = new Node;//创建头指针
	head->data = 1;
	head->next = NULL;

	Node *t = NULL,*p = NULL;
	p = head;

	for (int i = 2; i <= m; i++)
	{
		t = new Node;
		t->data = i;
		t->next = NULL;

		p->next = t;
		p = t;//更改移动指针的的位置
	}
	p->next = head;
	return head;
}

//输出测试的函数
void Showlist(Node* head)
{
	Node* p = head;

	do
	{
		cout << p->data << " ";
		p = p->next;
	} while (p != head);

	return;

}

//进行选大王的函数
void ChooseKing(Node *head,int n)
{
	Node* p = NULL, * t = NULL;
	p = head;

	
	while (p->next != p)
	{
		for (int i = 0; i < n - 1; i++)
		{
			t = p;
			p = p->next;
		}
		t->next = p->next;

		delete p;//删除结点
		p = t->next;

	}

	cout << p->data << endl;
	return;

}


int main()
{
	int m, n;//m代表猴子的数量，n代表报数间隔
	cin >> m>>n;
	Node* head = CreateList(m);
	
	//测试代码
	//Showlist(head);

	ChooseKing(head, n);

	return 0;

}