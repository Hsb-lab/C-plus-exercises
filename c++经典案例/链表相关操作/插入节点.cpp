//3.����ڵ�
//�������ʵ�ֲ����ɾ���ڵ�Ķ�̬�������ؼ�����ȷ�޸Ľڵ�ָ�롣Ҫ�����ɾ���Ľڵ㣬����Ҫ���ң�
//ȷ������λ�ã�Ȼ��λ�ò�ͬ�ֱ���
#include <iostream>
using namespace std;
struct List
{
	int data;
	List* next;
};

void insert(List * & head , int num)//headΪ��ͷָ�룬numΪҪ���������
{
	List* p = NULL, * q = NULL , *s = NULL;
	s = new List;
	s->data = num;
	s->next = NULL;
	if (head == NULL)//����գ�����һ���ڵ������
	{   
		head = s;
		return;
	}

	if (head->data > s->data)//����������С�����ͷ
	{   
		s->next = head;
		head = s;
		return;
	}

	for (q = head, p = head->next; p; q = p, p = p->next)//��������
	{
		if (p->data > s->data)
		{
			s->next = q;
			q->next = s;
			return; 
		}
	}
	q->next = s;//������������󣬲����β
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
	while (k)           //���������б�
	{
		insert(head, k);
		cin >> k;
	}
	ShowList(head);//�����������

	return 0;
}