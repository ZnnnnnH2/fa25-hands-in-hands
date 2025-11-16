/*
yoj492（加分表达式：【问题描述】
给定一个数字字符串S，在其中添加n个加号使其形成一个加法表达式。遍历所有可以构成合法加法表达式的加号添加方案，计算这些合法加法表达式的值，并按从大到小的顺序输出。
例如：对于数字字符串12345，添加3个加号可以构成的加法表达式包括：
a.      1+2+3+45=51
b.     1+2+34+5=42
c.      1+23+4+5=33
d.     12+3+4+5=24
按从大到小的顺序输出的结果是：51 42 33 24 
【输入格式】
一行，包含一个只含有数字的字符串，长度不超过15。
【输出格式】
一行，若干整数，依次是从大到小输出所有构造合法的加法表达式的计算结果，每2个整数之间用一个空格隔开。
【输入样例】
12345
【输出样例】
51 42 33 24

【数据描述】
数字字符串 S 的长度不超过 15。）
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
typedef long long ll;
typedef int *intt;
typedef char *charr;

const int inf=0x3f3f3f3f;
const int N=1e5+5;

using namespace std;

vector<int> ans;

int main() {
    string s;
    cin >> s;
    int len = s.length();
    for(int i=1; i<=len-3; i++) {
        for(int j=i+1; j<=len-2; j++) {
            for(int k=j+1; k<=len-1; k++) {
                int a = stoi(s.substr(0, i));
                int b = stoi(s.substr(i, j-i));
                int c = stoi(s.substr(j, k-j));
                int d = stoi(s.substr(k, len-k));
                ans.push_back(a + b + c + d);
            }
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for(auto a: ans) {
        cout << a << " ";
    }
    return 0;
}