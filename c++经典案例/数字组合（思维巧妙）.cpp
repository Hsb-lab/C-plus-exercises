//��1��2��3...9���3Ԫ��<abc��def��ghi>��ÿ������ǡ��ʹ��һ�Ρ�
//Ҫ���������ı���Ϊabc��def��ghi = 1��2��3���������3Ԫ�顣
//�������ʽ��
//��
//�������ʽ��
//������, ÿ����������ʾһ����Ԫ��(ÿ����֮����һ���ո�ָ�)
#include <iostream>
using namespace std;
void func(int i ,int& result_add,int& result_mul)
{
	int a = i % 10; int b = (i / 10) % 10; int c = i / 100;
	result_add += a + b + c; result_mul *= a * b * c;//+= ��*= ����ϸ��Ҫע�� 
}
int main()
{
	int i, j, k, result_add = 0, result_mul = 1;
	for (i = 123; i < 329; i++)
	{
		j = i * 2; k = i * 3;
		result_add = 0;result_mul = 1;
		func(i, result_add, result_mul);
		func(j, result_add, result_mul);
		func(k, result_add, result_mul);
		if (result_add == 45 && result_mul == 362880) cout << i << " " << j << " " << k << endl;
	}

}
