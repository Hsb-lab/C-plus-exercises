//����Ŀ������
//������������A��B���ж������Ƿ���ȡ�(����Ԫ�ؿ�����Ҫȥ��) ��
//�������������ȣ������"yes"���������"no"
//�������ʽ��
//���зֱ��ʾ���� A �� B ��ÿһ��������һ���� n ��ʾ���ϵĴ�С������������ n ������ʾ���ϵ�Ԫ��
//�������ʽ��
//��Ҫ����� "yes" �� "no" (��������)
//������������
//4 1 2 3 4
//4 4 3 2 1
//�����������
//yes
//���������͡�
//��һ�������ﲻ�ظ���Ԫ��Ϊ{ 1,2,3,4 }���ڶ�������ҲΪ{ 1,2,3,4 }���������������
#include <iostream>
using namespace std;
//����������ĺ���
void func01(int*& arr_i, int len)//�������������ĳ���
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if (arr_i[j] > arr_i[j + 1])
			{
				int temp = arr_i[j];
				arr_i[j] = arr_i[j + 1];
				arr_i[j + 1] = temp;
			}
		}
	}
}

//������ȥ�صĺ���
int* func02(int* arr_i, int& n)
{
	int len = n;
	for (int i = 0; i < n; i++)
	{
		if (arr_i[i] == arr_i[i + 1]) len--;
	}

	int* array = new int[len];
	for (int i = 0, j = 0; i < n - 1; i++)
	{
		if (arr_i[i] == arr_i[i + 1]) continue;
		else { array[j] = arr_i[i]; j++; }
	}
	array[len - 1] = arr_i[n - 1];
	n = len;
	return array;
}

//�ж����������Ƿ���ȵĺ���
int func03(int* p1, int* p2, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (p1[i] != p2[i]) { return 0; }
		if (p1[n - 1] == p2[n - 1] && i == (n - 1)) { return 1; }

	}

}
int main()
{    //������һ������
	int n1, m1, x1; cin >> n1; m1 = n1; //n1��ʾ����Ԫ�صĸ�����m1�ǹ�����,x1��ʾ���������
	int* arr_1 = new int[n1];
	int i = 0;//iΪ������
	while (m1)//����������ݸ�ֵ����̬������
	{
		cin >> x1;  arr_1[i] = x1;
		i++;
		m1--;
	}
	//�����ڶ�������
	int n2, m2, x2; cin >> n2; m2 = n2; //n2��ʾ����Ԫ�صĸ�����m2�ǹ�����,x2��ʾ���������
	int* arr_2 = new int[n2];
	int j = 0;//iΪ������
	while (m2)//����������ݸ�ֵ����̬������
	{
		cin >> x2;  arr_2[j] = x2;
		j++;
		m2--;
	}
	//���ú�������������
	func01(arr_1, n1);
	func01(arr_2, n2);

	/*for (int temp = 0; temp < n1; temp++)
	{
		cout << arr_1[temp] << " ";
	}
	cout << endl;
	for (int temp = 0; temp < n2; temp++)
	{
		cout << arr_2[temp] << " ";
	}
	cout << endl;*/

	//���ú���������ȥ��
	int* p1 = func02(arr_1, n1);
	int* p2 = func02(arr_2, n2);

	/*for (int temp = 0; temp < n1; temp++)
	{
		cout << p1[temp] << " ";
	}
	cout << endl;
	for (int temp = 0; temp < n2; temp++)
	{
		cout << p2[temp] << " ";
	}
	cout << endl;
	cout << n1 << " " << n2 << endl;*/
	//�ж����������Ƿ����
	if (n1 != n2)  cout << "no" << endl;
	else {
		if (func03(p1, p2, n1)) { cout << "yes" << endl; return 0; }
		else  cout << "no" << endl;
	}
}