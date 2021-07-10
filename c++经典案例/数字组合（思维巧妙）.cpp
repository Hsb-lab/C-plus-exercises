//用1，2，3...9组成3元组<abc，def，ghi>，每个数字恰好使用一次。
//要求三个数的比例为abc：def：ghi = 1：2：3。输出所有3元组。
//【输入格式】
//无
//【输出格式】
//若干行, 每行三个数表示一个三元组(每个数之间用一个空格分隔)
#include <iostream>
using namespace std;
void func(int i ,int& result_add,int& result_mul)
{
	int a = i % 10; int b = (i / 10) % 10; int c = i / 100;
	result_add += a + b + c; result_mul *= a * b * c;//+= 、*= 这种细节要注意 
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
