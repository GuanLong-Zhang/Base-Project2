# include<iostream>
using namespace std;

//函数提高

//函数的默认参数
int funcation0(int a, int b, int c)  //不带默认值
{
	return a + b + c;
}

int funcation1(int a, int b=20, int c=30)   //带默认值  如果某个位置已经有默认参数，那个从这个位置往后，都需要默认参数,不然会报错
{
	return a + b + c;
}

//函数声明和函数实现只能有一个作为默认值，如果两个都带默认值，就会发生歧义，运行就会报错

//函数占位参数
void funcation2(int a,int)    //空int表示占位参数  占位参数可以有默认的值
{
	cout << "this is a funcation2" << endl;
}

void funcation3(int a, int=10)    //占位参数可以有默认的值
{
	cout << "this is a funcation3" << endl;
}

//函数重载
//需要满足的三个条件 ：1、必须在同一个作用域下 2、函数名称相同 3、函数参数类型不同 或个数不同 或顺序不同

void funcation()
{
	cout << "1" << endl;
}

void funcation(int a)
{
	cout << "2" << endl;
}

void funcation(double a)
{
	cout << "3" << endl;
}

void funcation(double a,int b)
{
	cout << "4" << endl;
}

void funcation(int a,double b)
{
	cout << "5" << endl;
}

// 函数重载的注意事项
// 引用作为函数重载
void funcation(float & a)
{
	cout << "6" << endl;
}

void funcation(const float& a)
{
	cout << "7" << endl;
}

//当函数重载遇到默认参数，需要谨慎，调用的时候容易出现二义性，会报错

//int main()
//{
//	cout<<"三个数进行相加和为："<<funcation0(10, 20, 30)<<endl;   
//	cout<< "三个数进行相加和为："<< funcation1(10,30) << endl;     //传了值就用传的值，没有传就用默认值
//	funcation2(10, 10);   //调用占位参数必须进行填充，不然会报错
//	funcation3(10);
//	cout << "**************************" << endl;
//	funcation();
//	funcation(10);
//	funcation(3.14);
//	funcation(3.14, 6);
//	funcation(6,3.14);
//	float a = 3.14;
//	funcation(a);
//	system("pause");
//	return 0;
//
//}