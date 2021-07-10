//������������
//��дһ�����������һ����������List�࣬Ȼ��Ӵ�����������һ������������Set��
//������Ĳ���������������ƣ�ֻ�ǲ������ظ�Ԫ�أ���
//��������Ҫ���д�࣬ʵ�ֲ��롢ɾ����������ӡ�����Ѿ�д�á�
//���������������
//i 40 i 40 i 30 d 30 ? (����ListԪ�أ�i -- ���룬d--ɾ���� ? --��������)
//40 40 ���������List��
//i 40 i 40 i 50 i 50 d 50 ? (����SetԪ�أ�i -- ���룬d--ɾ���� ? --��������)
//40
#include<iostream>
using  namespace  std;

struct  Node {
    int  data;
    Node* next;
};

class  List//�հ�
{
public:
    Node *node;
    List()
    {
        node = new Node;
        node->next = NULL;
    }

    virtual void Insert(int num)
    {
       static Node* p = NULL;Node *s = NULL;
        s = new Node;
        s->data = num;
        s->next = NULL;
        if (node->next == NULL)   node->next = s;
        else
        {
            s->next = p;
            node->next = s;
        }
        p = s;//��p������һ������ĵ�ַ
        return;
    }
    virtual void Delete(int num)
    {
        if (node->next == NULL)   return;//�����ѿ�
        if (node->next->data == num)//��ɾ�ڵ���ͷ�ڵ�
        {
            Node* p = node->next;//
            node->next = node->next->next;
            delete p;
            p = NULL;
            return;
        }
        for (Node* n = node->next; n->next; n = n->next)
        {
            
            if (n->next->data == num)
            {
                Node* p = n->next;
                n->next = p->next;
                delete p;
                p = NULL;
                return;
            }
        }
    }

    void  Print()
    {
        if (node->next == 0)
            return;
        Node* n = node->next;
        for (; n != 0; n = n->next)
            cout << n->data << "  ";
        cout << endl;
    }
};

class  Set : public  List //�հ�
{
public:
    virtual void Insert(int num)
    {
        //ȥ�ز���
        if (node->next != NULL)
        {
            if (node->next->data == num)   return;
            for (Node* n = node->next; n->next; n = n->next)
            {
                if (n->next->data == num) return;
            }
        }
        static Node* p = NULL; Node* s = NULL;
        s = new Node;
        s->data = num;
        s->next = NULL;
        if (node->next == NULL)   node->next = s;
        else
        {
            s->next = p;
            node->next = s;
        }
        p = s;//��p������һ������ĵ�ַ
        return;
    }
    virtual void Delete(int num)
    {
        if (node->next == NULL)   return;//�����ѿ�
        if (node->next->data == num)//��ɾ�ڵ���ͷ�ڵ�
        {
            Node* p = node->next;//
            node->next = node->next->next;
            delete p;
            p = NULL;
            return;
        }
        for (Node* n = node->next; n != 0; n = n->next)
        {

            if (n->next->data == num)
            {
                Node* p = n->next;
                n->next = p->next;
                delete p;
                p = NULL;
                return;
            }
        }
    }
};

int  main()
{
    List* p, list1;
    Set  set1;
    p = &list1;
    char  opt;
    while (cin >> opt) {
        if (opt == '?')  break;
        int  num;
        cin >> num;
        if (opt == 'i') {
            p->Insert(num);
        }
        else  if (opt == 'd') {
            p->Delete(num);
        }
    }
    p->Print();

    p = &set1;
    while (cin >> opt) {
        if (opt == '?')  break;
        int  num;
        cin >> num;
        if (opt == 'i') {
            p->Insert(num);
        }
        else  if (opt == 'd') {
            p->Delete(num);
        }
    }
    p->Print();
    return  0;
}
