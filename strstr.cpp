/*
strstr函数语法介绍：

函数原型：
char* strstr(const char* haystack, const char* needle);

功能：
在字符串haystack中查找子串needle第一次出现的位置

参数：
- haystack: 被搜索的主字符串
- needle: 要查找的子字符串

返回值：
- 如果找到子串，返回指向第一次出现位置的被搜索的主字符串的“下标”
- 如果未找到，返回NULL

使用示例：
#include <cstring>
const char* str = "hello world";
const char* sub = "world";
char* result = strstr(str, sub);
if (result != NULL) {
    // 找到了，result指向"world"的位置
    int pos = result - str;  // 计算位置索引
}

注意事项：
1. strstr是C语言函数，需要包含<cstring>头文件
2. 参数和返回值都是char*类型，处理C风格字符串
3. C++中建议使用string::find()方法代替
4. 区分大小写
5. 如果needle是空字符串，返回haystack
*/

#include <cstdio>
#include <cstring>

char *s1 = "123456789";
char *s2 = "456";

int c = 0;
int main(){

    char *ret = strstr(s1, s2);
    if(ret){
        printf("Found substring at position: %ld\n", ret - s1);
    } else {
        printf("Substring not found.\n");
    }
    return 0;
}