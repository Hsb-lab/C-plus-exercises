//���ַ������Ӵ�

//��˹��һ��ͨ�أ�

#include<iostream>
using namespace std;

void Swap(string& str1, string& str2)
{
	string temp = str1;
	str1 = str2;
	str2 = temp;
}

//�ж��Ӵ��Ƿ���ڣ�������ڣ������������е���ʼλ��
int Func(string str1,string str2)
{
	int len01 = str1.length();
	int len02 = str2.length();

	//����Ĭ��str1Ϊ������str2Ϊ�Ӵ�
	if (len01 < len02) Swap(str1, str2);

	for (int i = 0; i < len01; i++)
	{
		for (int j = 0,temp = i; j < len02; j++,temp++)
		{
			if (str2[j] != str1[temp]) break;
			if (j == len02 - 1) return i;
		}
	}

	return 0;
}

void test01()
{

	string str1,str2;
	cin >> str1 >> str2;

	int ret = Func(str1, str2);
	if (ret)
	{
		cout << "�Ӵ����������ҵ�" << endl;
		cout << "�������е���ʼλ��Ϊ��" << ret << endl;
	}
	else
	{
		cout << "��������û���ҵ����Ӵ�" << endl;
	}

}

int main()
{
	test01();
}