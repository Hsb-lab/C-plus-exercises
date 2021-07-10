//【问题描述】
//编写一个程序，先设计一个整数链表List类，然后从此链表派生出一个整数集合类Set。
//集合类的插入操作与链表相似（只是不插入重复元素）。
//根据上述要求编写类，实现插入、删除操作。打印函数已经写好。
//【样例输入输出】
//i 40 i 40 i 30 d 30 ? (输入List元素，i -- 插入，d--删除， ? --操作结束)
//40 40 （输出整个List）
//i 40 i 40 i 50 i 50 d 50 ? (输入Set元素，i -- 插入，d--删除， ? --操作结束)
//40
#include<iostream>
using  namespace  std;

struct  Node {
    int  data;
    Node* next;
};

class  List//空白
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
        p = s;//用p保留上一个对象的地址
        return;
    }
    virtual void Delete(int num)
    {
        if (node->next == NULL)   return;//链表已空
        if (node->next->data == num)//被删节点是头节点
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

class  Set : public  List //空白
{
public:
    virtual void Insert(int num)
    {
        //去重操作
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
        p = s;//用p保留上一个对象的地址
        return;
    }
    virtual void Delete(int num)
    {
        if (node->next == NULL)   return;//链表已空
        if (node->next->data == num)//被删节点是头节点
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
