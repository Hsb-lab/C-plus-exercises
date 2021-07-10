//链表
//1.动态链表存储
//构成这种动态链表的每个节点除了存放数据的自身信息外，还应该存放与之相关联的元素的地址。
//在线性表中，每个节点只需要存放后继节点的地址，让一个个元素串联起来，就能够形成一个“单向链表”。


#include<iostream>
using namespace std;
//1.动态链表存储
struct Node//创建结构体
{
	int data;
	Node* next;
};

//2.建立和遍历链表
void CreatList(Node *&head)//引用参数是表头指针
{
	Node* s = NULL , * p = NULL;
	s = new Node;//在堆区创建一个对象
	cin >> s->data;//初始化完成
	while (s->data != 0)//终止条件可以更改
	{
		if (head == NULL)  head = s;//确定头指针
		else   p->next = s;//此节点的指针指向下一个节点

		p = s;//p用来保存上一个对象的地址
		s = new Node;//创建下一个对象
		cin >> s->data;//下一个对象初始化完成
	}
	p->next = NULL;//最后一个节点的指针域赋为空值（NULL）。它不但表示链表结束，还是防止误操作的关键。
	//如果最后一个一个指针是一个随机值，即指向未知单元，那么，对所指对象赋值，可能产生严重的后果
	delete s;//释放结束条件的节点
	return ;
}

//遍历链表须从表头指针开始，使用跟踪指针逐个输出节点值，直到指针为空
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