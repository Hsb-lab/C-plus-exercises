//Josephus(Լɪ��)������
//����������
//n����Χ��һ�������ӵ�i����ʼ����1��interval(���,���)���ϱ�����������interval�ĳ��У�
//ֱ������Ϊֹ�����е��˰��Ⱥ�˳�򹹳�һ���µ����С�
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
	int num, val, beg;//num��ʾ��������beg��ʾ��ʼ������λ�ã�val��ʾ�������
	cout << "������������" << endl;
	cin >> num;
	head = Create(num);//��������
	ShowList(head);//����������
	cout << endl;
	cout << "�����뿪ʼ�ı��" << endl;
	cin >> beg;//���뿪ʼ������λ��
	cout << "�����뱨�����" << endl;
	cin >> val;//���뱨�����
	cout << "�µ�����Ϊ" << endl;
	Out(head, beg, val);//��������в�ɾ������
}

Jonse* Create(int n)
{
	Jonse* h , * p ;
	int i;
	h = new Jonse;
	p = h;
	for (i = 1; i <= n; i++)
	{
		p->code = i;//����ÿ���ڵ����
		if (i < n)
		{
			p->next = new Jonse;
			p = p->next;
		}
	}
	p->next = h;//�������Ŀ����Ϊ�˹��ɻ�
	return h;//���ص���ͷ�ڵ��ָ��
}

void ShowList(Jonse* h)
{
	Jonse* p;
	p = h;
	do//�������
	{
		cout << p->code <<'\t';
		p = p->next;
	} while (p != h);//ע��ѭ������
}

void Out(Jonse* h, int i, int d)
{
	Jonse* p , * q ;
	int k;
	p = h;
	//q��p��ǰ��ָ�룬ָ��������Ľڵ�
	for (q = h; q->next != h; q = q->next) ;
		for (k = 1; k < i; k++)//Ѱ�ҿ�ʼ������λ��
		{
			q = p;
			p = p->next;
		}
		while (p != p->next)//����������ֱ��ʣ��һ���ڵ�
		{
			for (k = 1; k < d; k++)//����
			{
				q = p;
				p = p->next;
			}
			cout << p->code << endl;//�������d�ĵ�
			q->next = p->next;//ɾ���ڵ�
			delete p;
			p = NULL;
			p = q->next;
	    }
		cout << p->code << endl;//�������һ���ڵ�
		delete p;
		p = NULL;
}