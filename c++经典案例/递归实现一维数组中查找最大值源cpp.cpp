/*2. ��һά�����в������ֵ��Ҫ���õݹ�ʵ�֡�
����Ŀ������
��ݹ麯��Max������Ĵ���������[low, high]�����м�λ��mid��ԭ����ֽ�Ϊ���������⣬
��������ֱ���[low, mid]��[mid+1, high]�����������������ֵmaxL��
���Ұ�����������ֵmaxR����maxL��maxR�Ľϴ�ֵ��������[low, high]�����ֵ��
��αȽϵó������������ֵ��
�������ʽ��
���빲һ�У���һ������ n ��ʾ������Ԫ�صĸ�����
�������� n ��������ʾ�����ڸ���Ԫ�ص�ֵ��
�������ʽ��
���һ������ʾ����������Ԫ�ص�ֵ��
�����������
7 1 2 3 4 7 6 5
�����������
7                */
#include<iostream>
using namespace std;
int mid(int m, int n) {//ȡ�м�ֵ
	return (n - m) / 2 + m;
}
int max2(int x, int y) {//ȡ���ֵ
	if (x > y) return x;
	else return y;
}
int max(int m, int n,int a[]) {//�ݹ�
	if (m == n) return a[m];//�������������ȣ��򷵻������е���
	else {//���������
		return max2(max(m, mid(m, n), a), max(mid(m, n) + 1, n, a));//�ֳ����������䣬�����Ƚ�
	}
}
int main() {
	int a[100],n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	cout << max(0, n - 1, a);//���䳤��Ϊn,�±��0��n-1
	return 0;
}