//3.插入节点
//链表便于实现插入和删除节点的动态操作，关键是正确修改节点指针。要插入或删除的节点，首先要查找，
//确定操作位置，然后按位置不同分别处理
#include <iostream>
using namespace std;
struct List
{
	int data;
	List* next;
};

void insert(List * & head , int num)//head为表头指针，num为要插入的数据
{
	List* p = NULL, * q = NULL , *s = NULL;
	s = new List;
	s->data = num;
	s->next = NULL;
	if (head == NULL)//若表空，则建立一个节点的链表
	{   
		head = s;
		return;
	}

	if (head->data > s->data)//被插数据最小插入表头
	{   
		s->next = head;
		head = s;
		return;
	}

	for (q = head, p = head->next; p; q = p, p = p->next)//搜索插入
	{
		if (p->data > s->data)
		{
			s->next = q;
			q->next = s;
			return; 
		}
	}
	q->next = s;//被插入数据最大，插入表尾
	return;
}

void ShowList(List * head)
{
	while (head)
	{
		cout << head->data << endl;
		head = head->next;
	}
}
int main()
{
	List* head = NULL;
	int k ; cin >> k;
	while (k)           //建立有序列表
	{
		insert(head, k);
		cin >> k;
	}
	ShowList(head);//输出有序链表

	return 0;
}