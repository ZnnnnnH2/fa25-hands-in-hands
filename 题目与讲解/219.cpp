#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// 比较两个正整数的绝对值大小
// 返回true表示a的绝对值大于b的绝对值
bool absGreater(string a, string b) {
    // 如果长度不同，长度大的数字就大
    if (a.length() != b.length()) {
        return a.length() > b.length();
    }
    // 如果长度相同，按字典序比较
    return a > b;
}

// 两个正整数相加
// 模拟手工加法，从低位到高位逐位相加
string addPositive(string a, string b) {
    string result = "";  // 存储结果
    int carry = 0;       // 进位
    int i = a.length() - 1;  // a的当前位置，从最后一位开始
    int j = b.length() - 1;  // b的当前位置，从最后一位开始

    // 当还有位数没处理完，或者还有进位时，继续循环
    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;  // 先加上进位

        // 如果a还有位数，加上a当前位的数字
        if (i >= 0) {
            sum += a[i] - '0';  // 字符转数字
            i--;
        }

        // 如果b还有位数，加上b当前位的数字
        if (j >= 0) {
            sum += b[j] - '0';  // 字符转数字
            j--;
        }

        // 当前位的结果是sum对10取余
        result = char(sum % 10 + '0') + result;  // 数字转字符，插入到结果前面
        carry = sum / 10;  // 计算进位
    }

    return result;
}

// 两个正整数相减（要求a >= b）
// 模拟手工减法，从低位到高位逐位相减
string subPositive(string a, string b) {
    string result = "";  // 存储结果
    int borrow = 0;      // 借位
    int i = a.length() - 1;  // a的当前位置
    int j = b.length() - 1;  // b的当前位置

    // 从低位到高位逐位相减
    while (i >= 0) {
        int diff = a[i] - '0' - borrow;  // a当前位减去借位

        // 如果b还有位数，再减去b当前位
        if (j >= 0) {
            diff -= (b[j] - '0');
            j--;
        }

        // 如果不够减，需要借位
        if (diff < 0) {
            diff += 10;   // 向高位借10
            borrow = 1;   // 标记借位
        } else {
            borrow = 0;
        }

        result = char(diff + '0') + result;  // 将结果插入到前面
        i--;
    }

    // 去掉前导零（但至少保留一位）
    int pos = 0;
    while (pos < result.length() - 1 && result[pos] == '0') {
        pos++;
    }
    result = result.substr(pos);

    return result;
}

// 处理大整数的加减法运算
// op: 运算符（'+' 或 '-'）
// num1, num2: 两个大整数（可能带负号）
string calculate(char op, string num1, string num2) {
    bool sign1 = true, sign2 = true;  // true表示正数，false表示负数

    // 处理第一个数的符号
    if (num1[0] == '-') {
        sign1 = false;
        num1 = num1.substr(1);  // 去掉负号，保留数字部分
    }

    // 处理第二个数的符号
    if (num2[0] == '-') {
        sign2 = false;
        num2 = num2.substr(1);  // 去掉负号，保留数字部分
    }

    // 如果是减法，将第二个数的符号取反，转化为加法
    // 例如：a - b = a + (-b)，a - (-b) = a + b
    if (op == '-') {
        sign2 = !sign2;
    }

    string result;

    // 情况1：两数同号，做加法
    if (sign1 == sign2) {
        result = addPositive(num1, num2);
        // 如果原来都是负数，结果也是负数
        if (!sign1) {
            result = "-" + result;
        }
    }
    // 情况2：两数异号，做减法
    else {
        // 比较绝对值大小，用大的减小的
        if (absGreater(num1, num2)) {
            result = subPositive(num1, num2);
            // 结果的符号跟绝对值较大的数一致
            if (!sign1) {
                result = "-" + result;
            }
        } else {
            result = subPositive(num2, num1);
            // 结果的符号跟绝对值较大的数一致
            if (!sign2) {
                result = "-" + result;
            }
        }
    }

    // 处理特殊情况：-0 应该显示为 0
    if (result == "-0") {
        result = "0";
    }

    return result;
}

int main() {
    char op;           // 运算符
    string num1, num2; // 两个大整数

    // 读入运算符和两个大整数
    cin >> op;
    cin >> num1;
    cin >> num2;

    // 计算并输出结果
    cout << calculate(op, num1, num2) << endl;

    return 0;
}
