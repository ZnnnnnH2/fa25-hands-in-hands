#include "head.h"

//// 内存
//// 打开内存窗口： 开始调试后：“调试”-“窗口”-“内存”
//int main()
//{
//	//
//	int a = 0;
//	int b = 0x12345678;// 小端存储
//	// 思考：如何用移位运算符，判断你的机器是 大端 还是 小端？
//	cout << &a;
//
//	return 0;
//}
//
////指针的定义
//int main()
//{
//	int* p = NULL;// NULL为0，右键“转到定义”可以查看
//	cout << sizeof(char*) / sizeof(int*) << endl;
//
//	return 0;
//}
//
//// 指针变量占用内存的大小
//// 尝试 切换 x86/x64
//int main()
//{
//	int* p1 = NULL;
//	cout <<"p1: " <<  sizeof(p1) << endl;
//	char* p2 = NULL;
//	cout << "p2: " << sizeof(p2) << endl;
//
//	return 0;
//}
//
////解引用
//int main()
//{
//	int a = 0x12345678;
//	cout << "a: 0x" << hex << a << endl;
//	int* p = &a;
//	*p = 1;
//	cout << "a: " << a;
//
//	return 0;
//}
//
////指针的种类是一种视角
////
////int* p;
////*p
////从地址p开始，往后看4个格，并且把这4格里的东西解码为整数
////
////char* p;
////*p
////从地址p开始，往后看1个格，并且把这1格里的东西解码为字符
////
//int main()
//{
//	int a = 0x12345678;
//	char* p = (char*) &a;// 需要强制类型转换
//	*p = 0;
//
//	return 0;
//}
//
//
//int main()
//{
//	int a = 0x12345678;
//	char* pc = (char*) &a;
//	int* pi = &a;
//	printf("pc + 1 = %p\n", pc + 1);
//	printf("pi + 1 = %p\n", pi + 1);
//
//	return 0;
//}
//
//
//指向数组的某个元素

//void PrintArr(int arr[])
//{
//	printf("%d %d %d\n", arr[0], arr[1], arr[2]);
//}
//
//int main()
//{
//	int arr[3] = { 0,1,2 };
//	int* p = arr;// &arr[0]
//	cout << *p << endl << *(p+1) << endl;
//	cout << "---------------------------------------------------\n";
//
//	////数组名 的 含义 一般是 首元素的地址
//	//// 两个特例：
//	//cout << sizeof(arr) / sizeof(arr[0]) << endl;
//	//// arr + 1: + 4 Byte
//	//// &arr + 1: + 4*3 Byte
//
//	cout << "---------------------------------------------------\n";
//
//	cout << &arr[2] - &arr[0] << endl;
//
//	cout << "---------------------------------------------------\n";
//
//	for (int i = 0; i < 3; i++)
//	{
//
//	}
//
//	for (int* p = &arr[3]; p > &arr[0];)
//	{
//		*--p = -1;
//	}
//
//	PrintArr(arr);
//
//	//除了做题，自己写代码请不要使用
//	for (int* p = &arr[2]; p >= &arr[0]; p--)//有的编译器会报错，因为指针会落到&arr[-1]的位置
//	{
//		*p = -2;
//	}//标准规定是 可以 指针可以落到&arr[3]，但是不能落到&arr[-1]
//
//	PrintArr(arr);
//
//	return 0;
//}

