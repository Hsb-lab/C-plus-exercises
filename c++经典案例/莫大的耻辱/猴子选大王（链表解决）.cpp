//��M��1 000���ڣ�������Χ��һȦ��ÿ��������һ����ţ���Ŵ�1��M��
//�������ѡ��һ������������Э�̣�����ѡ�����Ĺ������£�
//�ӵ�1�����ӿ�ʼ��ÿ��N�����������������������ĺ��ӳ�Ȧ��
//���ʣ�����ľ��Ǵ�����Ҫ��Ӽ�������M��N����Ϊ����������
//�Ա�̼�����Ϊ���ٵĺ��ӽ���Ϊ������
//Ҫ��
//1���ñ���m��ʾ���ӵĸ���������n��ʾ��Ȧ�����Ļ�����
//2����������ÿ�δ�1����n����ǰΪn�ĺ��ӳ�Ȧ������3�����ӣ�nΪ2��
//���ӱ�ţ�1, 2, 3����Ȧ���ӵ���ţ�2��1�����Ӵ��������Ϊ3��
//3. ��������ʵ�֣��ο��α���Լɪ�򻷣�
//��������
//���룺
//������
//�����
//3

#include<iostream>
using namespace std;

//�ṹ��
struct Node
{
	int data;
	Node *next;
};

//����Լɪ�򻷵ĺ���
Node* CreateList(int m)
{
	Node* head = new Node;//����ͷָ��
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
		p = t;//�����ƶ�ָ��ĵ�λ��
	}
	p->next = head;
	return head;
}

//������Եĺ���
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

//����ѡ�����ĺ���
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

		delete p;//ɾ�����
		p = t->next;

	}

	cout << p->data << endl;
	return;

}


int main()
{
	int m, n;//m������ӵ�������n���������
	cin >> m>>n;
	Node* head = CreateList(m);
	
	//���Դ���
	//Showlist(head);

	ChooseKing(head, n);

	return 0;

}