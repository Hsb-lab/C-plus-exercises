//n�ʺ����⣺���������㣬Ҫ��n����������Ļʺ󣬰���n*n�������ϣ�
//���಻�ܹ��������ȫ������
//����һ��������n����������N�ʺ������ȫ���ڷ���
//���������ÿһ�ж�����һ�ְڷ�������ĵ�i����ѧ
//�����n���ʹ����i�еĻʺ�Ӧ�÷��ڵ�n�С�
//�ʺ���С��б�Ŷ��Ǵ�1��ʼ��
//�������룺
//4
//���������
//2 4 1 3
//3 1 4 2
#include<iostream>
using namespace std;
#include<cmath>
int N;
//���������õĻʺ�λ�ã������Ͻ��ǣ�0��0����
void NQueen(int k);
int queenPos[100];

int main()
{
	cin >> N;
	NQueen(0);//�ӵ�0�п�ʼ�ڻʺ�
	return 0;
}

void NQueen(int k)
{
	//��0~k-1�лʺ��Ѿ��ںõ�����£��ڵ�k�м����Ļʺ�
	int i;
	if (k == N)
	{
		//N���ʺ��Ѿ��ں�
		for (i = 0; i < N; i++) cout << queenPos[i] + 1 << " ";
		cout << endl;
		return;
	}
	for (i = 0; i < N; i++)
	{
		//���Ե�k���ʺ��λ��
		int j;
		for (j = 0; j < k; j++)
		{
			//���Ѿ��ںõ�k���ʺ��λ�ñȽϣ����Ƿ��ͻ
			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))
			{
				//��ͻ��������һ��λ��
				break;
			}
			
		}
		if (j == k)
		{
			//��ǰλ��i����ͻ
			queenPos[k] = i;//����k���ʺ�ڷ���λ��i
			NQueen(k + 1);
		}
	}//for(i = 0;i < N;i++)
}