//����
//1.��̬����洢
//�������ֶ�̬�����ÿ���ڵ���˴�����ݵ�������Ϣ�⣬��Ӧ�ô����֮�������Ԫ�صĵ�ַ��
//�����Ա��У�ÿ���ڵ�ֻ��Ҫ��ź�̽ڵ�ĵ�ַ����һ����Ԫ�ش������������ܹ��γ�һ��������������


#include<iostream>
using namespace std;
//1.��̬����洢
struct Node//�����ṹ��
{
	int data;
	Node* next;
};

//2.�����ͱ�������
void CreatList(Node *&head)//���ò����Ǳ�ͷָ��
{
	Node* s = NULL , * p = NULL;
	s = new Node;//�ڶ�������һ������
	cin >> s->data;//��ʼ�����
	while (s->data != 0)//��ֹ�������Ը���
	{
		if (head == NULL)  head = s;//ȷ��ͷָ��
		else   p->next = s;//�˽ڵ��ָ��ָ����һ���ڵ�

		p = s;//p����������һ������ĵ�ַ
		s = new Node;//������һ������
		cin >> s->data;//��һ�������ʼ�����
	}
	p->next = NULL;//���һ���ڵ��ָ����Ϊ��ֵ��NULL������������ʾ������������Ƿ�ֹ������Ĺؼ���
	//������һ��һ��ָ����һ�����ֵ����ָ��δ֪��Ԫ����ô������ָ����ֵ�����ܲ������صĺ��
	delete s;//�ͷŽ��������Ľڵ�
	return ;
}

//����������ӱ�ͷָ�뿪ʼ��ʹ�ø���ָ���������ڵ�ֵ��ֱ��ָ��Ϊ��
void ShowList(Node * head)
{
	while (head)
	{
		cout << head->data << endl;
		head = head->next;
	}
}

int main()
{
	Node* head = NULL;
	CreatList(head);
	ShowList(head);
}