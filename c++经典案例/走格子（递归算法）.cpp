//����Ŀ������
//����һ�� m* n �����񣬴������Ͻǳ�����ÿ��ֻ�����һ��������ƶ�һ�����ж����ֲ�ͬ�ķ������Ե��������½ǵĸ��ӣ�
//�������ʽ��
//һ������������ʾ m, n
//�������ʽ��
//һ��һ��������ʾ��
//������������
//2 2
//�����������
//2
#include <iostream>
using namespace std;
int waysum(int m , int n)
{
	int sum = 0;
	if (m == 1 || n == 1) return 1;
	else if (m == 2 && n == 2) return 2;
	else if (m == 2 && n == 3 || m == 3 && n == 2) return 3;
	else { sum += waysum(m - 1, n) + waysum(m, n - 1); return sum; }
}
int main()
{
	int m, n; cin >> m >> n;
	cout << waysum(m, n);
}