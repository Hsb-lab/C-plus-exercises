//���ֲ���
//�򵥲��ҵ�ʱ�临�Ӷ�ΪO(n)
//���ֲ��ҵ�ʱ�临�Ӷ�ΪO(logn)
//�õݹ�ʵ�ֶ��ֲ��ң�
//��������������ֻ����һ��Ԫ�ء�������Ҫ���ҵ�ֵ�����Ԫ����ͬ�����ҵ��ˣ�����˵�����������С�
//�ݹ�������������ֳ����룬������һ�붪����������һ��ִ�ж��ֲ��ҡ�

//�Ҹ��˶Զ��ֲ��ҵĲ���˵����
//1.��������ݱ������Ѿ�����õģ�������������У�������⣩
//2.���ֲ��ҵ���;�Ƚ���խ�����÷�ΧС�������ڿ��ԱȽϵ����ݣ�,ֻ�����ڲ����������Ƿ����Ŀ������
#include<iostream>
using namespace std;

//nΪĿ�����ݡ�leftΪ�����һ��Ԫ���±ꡢrightΪ�������һ��Ԫ���±�
//һ��Ҫע�����±�ѽ��
int func(int arr[],int left , int right , int n)
{
	if (left == right && arr[left] == n)  return left;
	else if (left < right)
	{
		int mid = (left + right) / 2;
		if (n > arr[mid])   return func(arr, mid+1, right, n);//�����+1 �� -1�Ǳ���ģ�����������д���
		else if (n < arr[mid])  return  func(arr, left, mid-1, n);
		else return mid;
	}
	return -1;
}

int main()
{
	//ע������һ��Ҫ��������˵ģ�������������У�
	//һ��Ҫע�����
	int arr[] = { 0,1,2,3,4,5,6,7,8,9};
	cout << "������Ҫ��ѯ������" << endl;
	int n;
	cin >> n;
	int result = func(arr, 0, 9 , n);
	if (result == -1)
	{
		cout << "δ�ҵ�������" << endl;
	}
	else
	{
		cout << "�ҵ������ݣ������ݼ�Ϊ�����е�arr[" << result << "]" << endl;
	}
}