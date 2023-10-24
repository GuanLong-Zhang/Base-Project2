# include<iostream>
using namespace std;

// 程序内存中的四个分区  代码区 全局区 栈区 堆区

//创建全局变量   函数体外的变量为全局变量
int c = 10;
int d = 10;

//全局常量
const int g = 10;

int* funcation()   //子函数定义的局部变量   局部变量和函数形参都保留在栈区中，
{
	int a = 10;    //局部变量存放在栈区，栈区的数据在函数执行完内存就自动释放了，所以不要返回局部变量的地址
	return &a;
}
int* funcation1()
{
	//利用new将数据开辟到堆区
	int* p = new int(10);
	return p;

}

double* funcation2()  //在堆区创建数据
{
	//在堆区利用new创建浮点型数据
	//new返回的是该数据类型的指针
	double* p = new double(12.5);
	return p;
}

void funcation3()
{
	//在堆区利用new创建10个整型的数组
	int *p=new int[10]; //此处的10表示数组有10个元素
	for (int i = 0; i < 10; i++)    //给数组赋值
	{
		p[i] = i;   //0-9
	}

	for (int i = 0; i < 10; i++)
	{
		cout << p[i] << " ";
	}
	cout << endl;

	//释放堆区数组时需要加[]
	delete[] p;

}
void printinfo()  //输出结果
{
	double* p = funcation2();
	cout << *p << endl;
	cout << *p << endl;
	cout << *p << endl;
	//可以利用delete进行内存空间的释放
	delete p;
	//cout << *p << endl;  //p已经被释放掉了，所以继续输出会进行警告使用了未初始化的内存p
}

//int main()
//{
//	//全局区  存放全局变量 静态变量 常量（全局常量，字符串常量）
//	// 
//	//创建局部变量   函数体内的变量为局部变量
//	int a = 10;
//	int b = 10;
//	cout << "局部变量a的地址为：" <<(int) & a << endl;
//	cout << "局部变量b的地址为：" << (int) & b << endl;
//
//	cout << "全局变量c的地址为：" << (int)&c << endl;
//	cout << "全局变量d的地址为：" << (int)&d << endl;   //全局变量和局部变量不在一个内存区域
//
//	//创建静态变量   在数据类型前面加上static
//	static int e = 10;
//	static int f = 10;
//
//	cout << "静态变量e的地址为：" << (int)&e << endl;
//	cout << "静态变量f的地址为：" << (int)&f << endl;   //全局变量和静态变量都在同一个内存区域
//
//	//常量  字符串常量  const修饰的变量(修饰的全局变量称为全局常量，修饰的局部变量称为局部常量）
//	cout << "字符串常量的地址为：" << (int) & "hello,world" << endl;
//	
//	//局部常量
//	const int h = 10;
//
//	cout << "全局常量g的地址为：" << (int)&g << endl;
//	cout << "局部常量h的地址为：" << (int)&h << endl;
//
//	cout << "***************************" << endl;
//	//栈区 编译器自动分配和释放  不要返回局部变量的地址
//	int* p = funcation();
//	cout << *p << endl;   //第一次正常打印，是因为编译器做了保留，
//	cout << *p << endl;   //第二次就不会进行保留了会生成一个乱码随机数   注意这种现在只出现在x86情况下，x64情况下会一直输出10
//
//	cout << "***************************" << endl;
//	//堆区 由程序员去分配和释放   若程序员不释放，程序结束由系统回收
//	int* p1 = funcation1();
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//	cout << *p1 << endl;
//
//	cout << "***************************" << endl;
//	funcation2();  //创建数据
//	printinfo();   //输出数据
//	funcation3();  //输出new创建的数组
//
//}