//4.删除节点
#include<iostream>
using namespace std;
struct List
{
	int date;
	List* next;
};

void del(List*& head, int key)
{
	List* p;
	if(!head)
	{
		cout << "List null!\n";
		return;
	}
	if (head->date == key)//被删节点是头节点
	{
		p = head;
		head = head->next;
		delete p;//释放数据
		p = NULL;
		return;
	}
	for (List* pg = head; pg->next; pg = pg->next)
	{
		if (pg->next->date == key)
		{
			p = pg->next;
			pg->next = p->next;
			delete p;
			p = NULL;
			return;
		}
	}
	cout << "there is not key:" << endl;
	return; 
}

int main()
{
	//本文件只有删除功能，请配合创建链表功能使用
}