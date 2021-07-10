//n皇后问题：输入整数你，要求n个国际象棋的皇后，摆在n*n的棋盘上，
//互相不能攻击，输出全部方案
//输入一个正整数n，则程序输出N皇后问题的全部摆法。
//输出结果里的每一行都代表一种摆法。行里的第i个数学
//如果是n，就代表第i行的皇后应该放在第n列。
//皇后的行、列编号都是从1开始算
//样例输入：
//4
//样例输出：
//2 4 1 3
//3 1 4 2
#include<iostream>
using namespace std;
#include<cmath>
int N;
//用来存放算好的皇后位置，最左上角是（0，0）；
void NQueen(int k);
int queenPos[100];

int main()
{
	cin >> N;
	NQueen(0);//从第0行开始摆皇后
	return 0;
}

void NQueen(int k)
{
	//在0~k-1行皇后已经摆好的情况下，摆第k行及其后的皇后
	int i;
	if (k == N)
	{
		//N个皇后已经摆好
		for (i = 0; i < N; i++) cout << queenPos[i] + 1 << " ";
		cout << endl;
		return;
	}
	for (i = 0; i < N; i++)
	{
		//逐尝试第k个皇后的位置
		int j;
		for (j = 0; j < k; j++)
		{
			//和已经摆好的k个皇后的位置比较，看是否冲突
			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j))
			{
				//冲突，测试下一个位置
				break;
			}
			
		}
		if (j == k)
		{
			//当前位置i不冲突
			queenPos[k] = i;//将第k个皇后摆放在位置i
			NQueen(k + 1);
		}
	}//for(i = 0;i < N;i++)
}