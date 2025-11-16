/*
 * 题目：1214. 成绩位次
 * 功能：根据高考成绩计算学生位次
 * 排序规则：
 *   1. 总分从高到低
 *   2. 总分相同，语文从高到低
 *   3. 语文相同，数学从高到低
 *   4. 数学相同，英语从高到低
 *   5. 英语相同，自选科目相同（同分考生，位次相同）
 */

#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105; // 最多100个学生，留5个余量

// 学生结构体，存储学生的各科成绩信息
struct Student
{
    int zongfen;  // 总分
    int yuwen;    // 语文成绩
    int shuxue;   // 数学成绩
    int yingyu;   // 英语成绩
    int zixuan;   // 自选3科总分
    int id;       // 学号

    // 初始化函数，根据各科成绩计算总分并赋值
    void init(int _yuwen, int _shuxue, int _yingyu, int _zixuan, int _id)
    {
        zongfen = _yuwen + _shuxue + _yingyu + _zixuan;  // 计算总分
        yuwen = _yuwen;
        shuxue = _shuxue;
        yingyu = _yingyu;
        zixuan = _zixuan;
        id = _id;
    }
};

int n;               // 学生人数
Student s[N];        // 学生数组
int aim_id;          // 目标学号（需要查询位次的学生）
int top_rank;        // 本组第一名的位次

// 比较函数，用于排序（按位次规则）
// 参数x, y是学生数组的下标
bool cmp(int x, int y)
{
    Student &a = s[x];  // 引用方式访问，避免拷贝
    Student &b = s[y];

    // 规则1：总分不同，总分高的排前面
    if (a.zongfen != b.zongfen)
        return a.zongfen > b.zongfen;

    // 规则2：总分相同，语文成绩高的排前面
    if (a.yuwen != b.yuwen)
        return a.yuwen > b.yuwen;

    // 规则3：语文相同，数学成绩高的排前面
    if (a.shuxue != b.shuxue)
        return a.shuxue > b.shuxue;

    // 规则4：数学相同，英语成绩高的排前面
    if (a.yingyu != b.yingyu)
        return a.yingyu > b.yingyu;

    // 规则5：英语也相同，说明所有科目都相同，同分考生
    return false;
}

int a[N];  // 索引数组，用于间接排序（存储学生在s数组中的下标）

int main()
{
    cin >> n;  // 读入学生人数

    // 读入每个学生的成绩信息
    for (int i = 1; i <= n; i++)
    {
        int id, yuwen, shuxue, yingyu, zixuan;
        cin >> id >> yuwen >> shuxue >> yingyu >> zixuan;
        s[i].init(yuwen, shuxue, yingyu, zixuan, id);  // 初始化学生信息
        a[i] = i;  // a[i]存储学生在s数组中的位置
    }

    cin >> top_rank >> aim_id;  // 读入本组第一名的位次和目标学号

    // 对索引数组a进行排序，按照位次规则排序
    sort(a + 1, a + n + 1, cmp);

    int rank = 0;  // 相对位次（在本组内的位次，从1开始）

    // 遍历排序后的学生，计算目标学生的位次
    for (int i = 1; i <= n; i++)
    {
        // 调试输出：可以查看排序后的学生成绩
        // cout<<s[a[i]].zongfen<<" "<<s[a[i]].yuwen<<" "<<s[a[i]].shuxue<<" "<<s[a[i]].yingyu<<endl;

        // 判断当前学生是否与前一个学生成绩完全相同
        // 如果不同（即不是同分考生），则位次+1
        if (!(s[a[i]].zongfen == s[a[i - 1]].zongfen &&
              s[a[i]].yuwen == s[a[i - 1]].yuwen &&
              s[a[i]].shuxue == s[a[i - 1]].shuxue &&
              s[a[i]].yingyu == s[a[i - 1]].yingyu))
        {
            rank++;  // 位次递增
        }

        // 找到目标学生，退出循环
        if (s[a[i]].id == aim_id)
        {
            break;
        }

        // 调试输出：查看位次变化
        // cout << rank << endl;
    }

    // 输出目标学生的绝对位次
    // 绝对位次 = 本组第一名的位次 + 相对位次 - 1
    cout << top_rank + rank - 1 << endl;
}