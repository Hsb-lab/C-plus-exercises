//4.ɾ���ڵ�
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
	if (head->date == key)//��ɾ�ڵ���ͷ�ڵ�
	{
		p = head;
		head = head->next;
		delete p;//�ͷ�����
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
	//���ļ�ֻ��ɾ�����ܣ�����ϴ���������ʹ��
}