//面向对象三大特性 封装 继承 多态
//类与对象
# include<iostream>
using namespace std;

//圆周率
const double PI= 3.14;

//定义一个圆类
class circle
{
	//权限
public:
	//属性    (变量）
	int c_r;
	//行为   （函数）
	double calculate()
	{
		return 2 * PI * c_r;
	}
};

//定义一个学生类
class student
{
	//权限
public:
	//属性  成员属性
	string name;
	string number;

	//行为   成员函数
	void fuzhi()
	{
		cout << "请输入学生信息" << endl;
		cout << "姓名：" << " ";
		cin >> name;
		cout << "学号：" << " ";
		cin >> number;
	}

	void shuchu()
	{
		cout << "输出学生信息" << endl;
		cout << "姓名：" << name << endl;
		cout << "学号：" << number << endl;
	}
};

//访问权限
//public     公共  类内可以访问 类外也可以进行访问
//protected  保护  类内可以访问 类外不可以进行访问
//private    私有  类内可以访问 类外不可以进行访问


//定义一个老师类
class teacher
{
public:
	string name;
protected:
	string car;
private:
	string password;
public:
	void func()   //类内访问
	{
		name = "张三";
		car = "大众";
		password = "123456";
	}
};

//c++中struct 和 class 的区别
//默认访问权限不同 struct 默认公有 class默认私有

class A1
{
	int num1;    //默认访问权限为私有
};

struct A2
{
	int num2;    //默认访问权限为公共
};

//成员属性设置为私有的好处
//1.可以自己设置读写权限
//2.对于写可以检测数据的有效性

class Person
{
public:   //公共成员函数
	void setname(string s)  //可写
	{
		name = s;
	}
	string getname()    //可读
	{
		return name;
	}
	void setage(int a)   //可写
	{
		if (a < 0 || a>150)
		{
			cout << "输入年龄错误！" << endl;
			age = 0;
			return;   //需要加上return返回结果，不然结果还是错误的
		}
		age = a;
	}
	int getage()     //可读
	{
		return age;
	}

	void setlover(string s)  //可写
	{
		lover = s;
	}

private:   //私有成员
	string name;    //可读可写
	int age;        //只读
	string lover;   //只写

};

//int main()
//{
//	//创建一个对象
//	circle c1;
//	c1.c_r = 10;
//	cout << "圆的周长为：" << c1.calculate() << endl;
//
//	//创建一个对象
//	student a1;
//	//赋值
//	a1.fuzhi();
//	//输出
//	a1.shuchu();
//
//	teacher t1;
//	t1.name = "李四";
//	//t1.car = "奔驰";    //保护权限 类外不可以进行访问  会报错
//	//t1.password = "123";  //私有权限 类外不可以进行访问  会报错
//
//	//创建一个对象
//	A1 A1;
//	//A1.num1 = 10;   //报错 不可以进行访问
//	A2 A2;
//	A2.num2 = 20;   //正常访问
//
//	//创建一个对象
//	Person P;
//	P.setname("张三");  //可写
//	cout<<"姓名为："<<P.getname()<<endl;        //可读
//	P.setage(1800);   //可写
//	cout<<"年龄为："<<P.getage()<<endl;   //可读
//	P.setlover("李四");   //可写
//	system("pause");
//	return 0;
//}