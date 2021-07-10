//Josephus(Լɪ��)������
//����������
//n����Χ��һ�������ӵ�i����ʼ����1��interval(���,���)���ϱ�����������interval�ĳ��У�
//ֱ������Ϊֹ�����е��˰��Ⱥ�˳�򹹳�һ���µ����С�
#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};

Node* CreateCircle(int num)//����Բ��
{
	Node* p = NULL, * s = NULL,*head = NULL;//��������ָ��
	p = new Node;
	head = p;//s��ͷָ��ĵ�ַ�����������ֵַ������
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
	Node* p = head;//����ͷָ��
	do
	{
		cout << head->data << " ";
		head = head->next;
	} while (head != p);
	cout << endl;
}

void ShowJosephusCircle(Node * head,int begin,int d)//���Լɪ��
{
	Node* p = NULL; Node* s = NULL,*q = NULL;//��������������ָ��
	q = head;//����ͷ�ڵ�ĵ�ַ
	for (s = head; s->next != head; s = s->next)
	{
		if (s->data == begin)
		{
			while (s != s->next)//ʣ���һ���ڵ�ʱ����ѭ��
			{
				for (int k = 1; k < d; k++)
				{
					p = s;//p������һ���ڵ�ĵ�ַ
					s = s->next;
				}
				cout << s->data << " ";//�������d�Ľڵ�
				p->next = s->next;
				delete s;//ɾ���ڵ�
				s = NULL;
				s = p->next;
			}
			cout << s->data << endl;//�������һ���ڵ�
			delete s;
			s = NULL;
			return;
		}
	}
}

int main()
{
	int num, begin, d;//num��ʾ��������begin��ʾ��ʼ��λ�ã�d���������
	cout << "������������" << endl;
	cin >> num;
	Node* head = CreateCircle(num);//����Բ������ȡͷָ��
	cout << "������Բ��Ϊ" << endl;
	ShowCircle(head);
	cout << "�����뿪ʼ������λ��" << endl;
	cin >> begin;
	cout << "�����뱨�����" << endl;
	cin >> d;
	ShowJosephusCircle(head, begin, d);
}