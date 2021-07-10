//【题目描述】
//如果一个字符串可以由某个长度为k的字符串重复多次得到，我们说该串以k为周期。
//例如，abcabcabc以3为周期（注意它也以6和12为周期）。
//输入一个长度不超过80的串，输出它的最小周期。
//【输入格式】
//一行一个字符串
//【输出格式】
//一行一个整数表示最小周期
//【输入样例】
//HoHoHo
//【输出样例】
//2
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
    char word[81];
    cin >> word;
    int len = strlen(word);
    //cout<<len<<endl;
    for (int i = 1; i <= len; i++) {  //i代表周期（周期起码为1，所以从1开始）
        int ok = 1;             //ok表示周期是否成立
        if (len % i == 0) {
            //cout<<"i "<<i<<endl;
            for (int j = i; j < len; j++) {
                if (word[j] != word[j % i]) { ok = 0; break; }
            }
            if (ok) { cout << i << endl; return 0; }
        }

    }
}