//����ת��
//����ת��������ȡ�࣬��������
//С��ת�����˻�ȡ������������
//������ϵͳ�ı�׼�����Ͳ�Ҫд�Լ����ˣ������������벻���Ĳٵ����
#include<iostream>
using namespace std;
#include<bitset>
#include<cmath>
void test01(int m)
{
	cout << oct << m << endl;//�˽���
	cout << dec << m << endl;//ʮ����
	cout << hex << m << endl;//ʮ������
	cout << bitset<8>(m) << endl;//������
}

void test02(int m , int n)
{
	int sum = 0 , i = 0;
	while (m)
	{
		sum += (m % n) * pow(10, i);
		m = m / n;
		i++;
	}
	cout << sum << endl;
}

int main()
{
	int m; 
	cout << "������Ҫת������" << endl;
	cin >> m;
	//test01(m);//ֱ�ӵ���ϵͳ�ı�׼����
	cout << "������Ҫת���ɵĽ���" << endl;
	int n; 
	cin >> n;
	test02(m, n);
}