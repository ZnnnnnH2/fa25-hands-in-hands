#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);                  // 读取需要转换的数字个数
  for (int j = 1; j <= n; j++) {    // 循环处理每个转换任务
    char s[200];                    // 创建一个数组来存储源语言中字符到其数值的映射
    memset(s, 0, sizeof(s));        // 初始化数组
    string str1, yuan, mubiao;      // str1: 待转换的数字, yuan: 源语言, mubiao: 目标语言
    string ans = "";                // ans: 存储转换结果的字符串
    cin >> str1 >> yuan >> mubiao;  // 读取输入

    // --- 步骤 1: 将源语言 (source_language) 的数字 (alien_number) 转换为十进制 ---
    int len = str1.length();           // 待转换数字的长度
    int len_yuan = yuan.length();      // 源语言的基数（即字符集的数量）
    int len_mubiao = mubiao.length();  // 目标语言的基数

    // 创建一个从源语言字符到其十进制值的映射
    // 数组的索引是字符的ASCII码，值是该字符在计数系统中的顺序（0, 1, 2...）
    for (int i = 0; i < len_yuan; i++) {
      s[yuan[i]] = i;
    }

    long long sum = 0;  // 用于存储转换后的十进制数
    // 遍历待转换数字的每一位，计算其十进制值
    for (int i = 0; i < len; i++) {
      sum *= len_yuan;    // 每次将当前总和乘以源语言的基数
      sum += s[str1[i]];  // 加上当前位的数值
    }

    // --- 步骤 2: 将十进制数转换为目标语言 (target_language) ---
    if (sum == 0) {  // 特殊情况：如果十进制数是0
      ans += mubiao[0];
    } else {
      // 使用“除基取余法”将十进制数转换为目标语言
      while (sum > 0) {
        ans += mubiao[sum % len_mubiao];  // 取余得到最低位，并找到目标语言中对应的字符
        sum /= len_mubiao;                // 整除基数，去掉最低位
      }
      // 因为转换时是从低位到高位生成的，所以需要反转字符串
      reverse(ans.begin(), ans.end());
    }

    // --- 步骤 3: 输出结果 ---
    printf("Case #%d: ", j);  // 按格式输出案例编号
    cout << ans;              // 输出转换后的数字
    printf("\n");
  }
  return 0;
}