# include<iostream>
using namespace std;

//引用的使用

//交换位置
//值传递   形参的改变不影响实参
void swap0(int a, int b)
{
	int num = a;
	a = b;
	b = num;

	cout << "值传递中的e的值为：" << a << endl;
	cout << "值传递中的f的值为：" << b << endl;

}

//地址传递  形参的改变影响实参
void swap1(int* p, int* p1)
{
	int num = *p;
	*p = *p1;
	*p1 = num;

	cout << "地址传递中的e的值为：" << *p << endl;
	cout << "地址传递中的f的值为：" << *p1 << endl;

}

//引用传递   形参的改变影响实参
void swap2(int& a, int& b)
{
	int num = a;
	a = b;
	b = num;

	cout << "引用传递中的e的值为：" << a << endl;
	cout << "引用传递中的f的值为：" << b << endl;

}

//打印数据
void printinfo(const int& a)   //引用作为参数 ，形参改变实参  const进行修饰防止a被修改掉
{
	//a = 1000;  //加上const就会报错,因为不可以被修改
	cout << "函数内h的值为：" << a << endl;
}

//不要返回局部变量的引用
int& test0()
{
	int a = 10;   //局部变量存放在栈区，程序运行完就自动释放内存了
	return a;
}

//函数的调用作为左值
int& test1()
{
	static int a = 10;   //利用static将变量转换为静态变量 存放在全局区
	return a;
}

//int main()
//{
//	//引用的作用：给变量起别名
//	int a = 10;
//	int& b = a;  //引用  b和a指向同一个内存空间
//	cout << "b的值为：" << b << endl;
//	cout << "a的值为：" << a << endl;
//	b = 20;
//	cout << "b的值为：" << b << endl;
//	cout << "a的值为：" << a << endl;
//
//	//引用的注意事项
//	//引用必须进行初始化  
//	int c = 30;
//	//int& d;    //报错，引用必须进行初始化
//	int& d = c;
//	cout << "c的值为：" << c << endl;
//	cout << "d的值为：" << d << endl;
//	//初始化以后就不可以进行修改了
//	//int& d = a;   //报错 d重定义多次初始化
//	d = a;  //赋值操作  d的值发生了改变 c的值也发生了改变 因为他们指向同一个内存空间
//	cout << "a的值为：" << c << endl;
//	cout << "d的值为：" << d << endl;
//	cout << "c的值为：" << c << endl;
//
//	cout << "*************************" << endl;
//	//引用作函数参数
//	int e = 22;
//	int f = 33;
//	cout << "主函数中的e的值为：" << e << endl;
//	cout << "主函数中的f的值为：" << f << endl;
//	swap0(e, f);
//	cout << "主函数中的e的值为：" << e << endl;
//	cout << "主函数中的f的值为：" << f << endl;
//	swap1(&e, &f);
//	cout << "主函数中的e的值为：" << e << endl;
//	cout << "主函数中的f的值为：" << f << endl;
//	swap2(e, f);
//	cout << "主函数中的e的值为：" << e << endl;
//	cout << "主函数中的f的值为：" << f << endl;
//
//	cout << "***************************" << endl;
//	//引用作函数返回值
//	//不要返回局部变量的引用
//	int& ref = test0();
//	cout << "ref的值为：" << ref << endl;   //第一次正常输出 第二次就乱码了，原因是栈区对于局部变量会保留一次结果，后续就释放了
//	cout << "ref的值为：" << ref << endl;
//
//	//函数的调用作为左值   (static静态变量 存放在全局区）
//	int& ref1 = test1();
//	cout << "ref1的值为：" << ref1 << endl;
//	cout << "ref1的值为：" << ref1 << endl;
//	test1() = 1000;  //相当于对于ref1重新赋值
//	cout << "ref1的值为：" << ref1 << endl;
//	cout << "ref1的值为：" << ref1 << endl;
//	
//	cout << "***************************" << endl;
//	//引用的本质 就是一个指针常量 即指向不可以进行修改，而值可以进行修改
//	//这也就说明了为什么引用不可以进行多次初始化，因为它本质上有const修饰，但是对应的值可以进行修改
//
//	//常量引用
//	//修饰形参防止误操作
//	int g = 10;
//	//int& ref2 = 10;   //报错，引用必须引用一块合法的内存空间
//	const int& ref2 = 10;  //编译器给创建了一个临时的内存空间，不会报错，但是也不可以对其进行修改
//
//	int h = 10;
//	printinfo(h);   //输出值
//	cout << "函数外h的值为：" << h << endl;
//
//	system("pause");
//	return 0;
//}