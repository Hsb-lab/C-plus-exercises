//斐波拉契竖列：1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144…
//递归



//方法一 递归
//#include <iostream>
//using namespace std;
//
//int fib(int n);
//int main() {
//	int n;
//	cout << "n=";
//	cin >> n;
//	cout << "结果：" << fib(n) << endl;
//	system("pause");
//	return 0;
//}
//int fib(int n) {
//	if (n <= 1) return 1;
//	return fib(n - 1) + fib(n - 2);
//}


//方法二 非递归
//#include <iostream>
//using namespace std;
//
//int fibFor(int n);
//int main() {
//	int n;
//	cout << "n=";
//	cin >> n;
//	cout << "结果：" << fibFor(n) << endl;
//	system("pause");
//	return 0;
//}
//int fibFor(int n) {
//	int a = 1;
//	int b = 1;
//	int result;
//	if (n <= 1) return 1;
//	else
//	{
//		for (int i = 1; i < n; i++)
//		{
//			result = a + b;
//			a = b;
//			b = result;
//		}
//		return result;
//	}
//}