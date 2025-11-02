/*
 * 题目：字符串编辑
 * 功能：对给定字符串进行统计、删除、插入、替换操作
 * 操作命令：
 *   C str - 统计子串str无重叠出现次数
 *   D str - 删除第一次出现的子串str
 *   I str1 str2 - 在最后一个str1前面插入str2
 *   R str1 str2 - 用str2替换所有str1
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s; // 原字符串
    char cmd; // 命令字符

    getline(cin, s); // 读取原字符串
    cin >> cmd;      // 读取命令字符

    // C命令：统计子串无重叠出现次数
    if (cmd == 'C')
    {
        string str;
        cin >> str; // 读取要统计的子串

        int count = 0; // 计数器
        int pos = 0;   // 当前查找位置

        // 从头开始查找子串
        while (pos <= s.length() - str.length())
        {
            // 找到子串，计数加1，并跳过这个子串继续查找
            if (s.substr(pos, str.length()) == str)
            {
                count++;
                pos += str.length(); // 无重叠，跳过整个子串长度
            }
            else
            {
                pos++; // 没找到，移动一位继续查找
            }
        }

        cout << count << endl;
    }
    // D命令：删除第一次出现的子串
    else if (cmd == 'D')
    {
        string str;
        cin >> str; // 读取要删除的子串

        // 查找子串第一次出现的位置
        int pos = s.find(str);

        // 如果找到了，删除它
        if (pos != string::npos)
        {
            s.erase(pos, str.length());
        }

        cout << s << endl;
    }
    // I命令：在最后一个str1前面插入str2
    else if (cmd == 'I')
    {
        string str1, str2;
        cin >> str1 >> str2; // 读取两个字符串

        int pos = -1; // 最后一次出现的位置

        // 查找str1最后一次出现的位置
        for (int i = 0; i <= s.length() - str1.length(); i++)
        {
            if (s.substr(i, str1.length()) == str1)
            {
                pos = i; // 记录每次找到的位置
            }
        }

        // 如果找到了，在最后一次出现的位置前插入str2
        if (pos != -1)
        {
            s.insert(pos, str2);
        }

        cout << s << endl;
    }
    // R命令：用str2替换所有str1
    else if (cmd == 'R')
    {
        string str1, str2;
        cin >> str1 >> str2; // 读取两个字符串

        int pos = 0; // 当前查找位置

        // 遍历字符串，查找并替换所有str1
        int a = s.length() - str1.length();

        while (pos <= a)
        {
            // 找到str1，用str2替换
            if (s.substr(pos, str1.length()) == str1)
            {
                s.erase(pos, str1.length()); // 删除str1
                s.insert(pos, str2);         // 插入str2
                pos += str2.length();        // 跳过替换后的str2，避免重复替换
            }
            else
            {
                pos++; // 没找到，移动一位继续查找
            }
        }

        cout << s << endl;
    }

    return 0;
}
