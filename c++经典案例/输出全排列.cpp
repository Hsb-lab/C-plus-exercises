#include<iostream>
using namespace std;

int Array[5] = { 1,2,3,4,5 };

//a,b����������±�
void Swap(int a, int b)
{
	int temp = Array[a];
	Array[a] = Array[b];
	Array[b] = temp;
}

void FullSort(int n)
{
	if (n == 5)
	{
		for (int i = 0; i < 5; i++)
		{
			cout << Array[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = n; i <= 4; i++)
	{
		Swap(n, i);//����
		FullSort(n + 1);
		Swap(n, i);//������
	}
}

int main()
{
	FullSort(0);
	return 0;
}