//����Ŀ������
//���һ���ַ���������ĳ������Ϊk���ַ����ظ���εõ�������˵�ô���kΪ���ڡ�
//���磬abcabcabc��3Ϊ���ڣ�ע����Ҳ��6��12Ϊ���ڣ���
//����һ�����Ȳ�����80�Ĵ������������С���ڡ�
//�������ʽ��
//һ��һ���ַ���
//�������ʽ��
//һ��һ��������ʾ��С����
//������������
//HoHoHo
//�����������
//2
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string m; cin >> m;//���岢����һ���ַ���
	int len = m.length();//��ȡ�ַ����ĳ���
	for (int i = 1; i <= len; i++)//������iΪ����
	{
		if (len % i != 0) continue;
		else
		{
			for (int j = i; j < len; j++)
			{
				if (m[j % i] != m[j])
				{
					break;
				}
				if (j == len - 1)
				{
					cout << i << endl; return 0;
				}
			}
		}
	}
	cout << len << endl;//������ַ���û�����ڣ���ô������С���ھ���������ĳ���
	return 0;
}