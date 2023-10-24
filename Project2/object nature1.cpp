# include <iostream>
using namespace std;

//对象属性
//类对象作为其他类的成员  简单的说就是类里面套类

//手机类
class phone
{
public:
	string phone_name;
	phone(string name)
	{
		cout << "phone构造函数调用" << endl;
		phone_name = name;
	}
	~phone()
	{
		cout << "phone析构函数调用" << endl;
	}
};

//人类中包含手机类，
//先调用手机类的构造函数，再调用人类的构造函数；
//先释放人类的析构，再释放手机的析构;

class person1   
{
public:
	int a1;
	int b1;
	int c1;
	string name;
	phone p_n;    //手机类对象

	//传统初始化  采用有参构造函数进行初始化
	//person(int a, int b, int c)
	//{
	//	a1 = a;
	//	b1 = b;
	//	c1 = c;
	//	cout << "调用有参构造函数进行初始化" << endl;
	//}

	//初始化列表进行初始化
	person1(int a,int b,int c, string d ,string e) :a1(a), b1(b), c1(c),name(d),p_n(e)
	{
		cout << "person1构造函数调用" << endl;
	}
	~person1()
	{
		cout << "person1析构函数调用" << endl;
	}

};

class person2
{
public:
	static int age;   //静态成员变量   1.所有对象都需要同一份数据 2.编译阶段就分配了内存  3.类内声明 类外进行初始化
	static void funcation()   //静态成员函数   静态成员函数只能对静态成员变量进行访问
	{
		age = 100;  
		//age1 = 200;    //报错，因为age1为非静态成员变量
		cout << "静态成员函数的调用" << endl;
	}
	int age1;
private:
	static int agea;

};

int person2::age = 10;  //类外初始化静态成员变量
int person2::agea = 10;

void test01()
{
	person2 p;
	cout <<"年龄为："<< p.age << endl;  //通过创建对象，访问静态成员变量
	person2 p1;
	p1.age = 20;
	cout << "年龄为：" << p.age << endl;   //共享同一个数据，虽然是用p1进行修改的，但是用p进行访问的时候值依然被更改了
	cout << "年龄为：" << person2::age << endl;  //通过类名进行访问静态成员变量   这是与别的变量访问有区别的地方
	//cout << "年龄为：" << person11::agea << endl;  //报错，agea是私有的不可以进行访问
	person2 p2;
	p2.funcation();   //通过创建对象，访问静态成员函数
	person2::funcation();  //通过类名进行访问静态成员函数

}

void test00()
{
	person1 p(10, 20, 30,"张三","苹果手机");
	cout << "a等于" << p.a1 << endl;
	cout << "b等于" << p.b1 << endl;
	cout << "c等于" << p.c1 << endl;
	cout << "姓名：" << p.name << endl;
	cout << "手机：" << p.p_n.phone_name << endl;
}

class person3
{
public:
	int ma;   //非静态成员变量  属于类的对象上
	static int mb;  //静态成员变量 不属于类的对象上
	void funcation1() {}  //非静态成员函数  不属于类的对象上
	static void funcation2() {}  //静态成员函数   不属于类的对象上
	int age;
	person3()    //无参构造
	{

	}
	person3(int age)   //有参构造
	{
		this->age = age;    //this->的作用是防止名称冲突
	}
	person3& personaddperson( person3 &p)
	{
		this->age += p.age;
		return *this;    //返回指向的本体,这样就可以重复操作一个本体
	}
};


int person3::mb = 0;

void test02()
{
	person3 p;
	//C++会为每个空对象分配一个字节空间，目的是为了区分每个空对象所占的内存空间
	cout << "空对象所占的内存空间："<<sizeof(p) << endl;   //空对象所占用一个字节
}

void test03()
{
	person3 p;
	cout << "非静态成员变量所占的内存空间：" << sizeof(p) << endl;   //占用四个字节  int占用4个字节
}

void test04()
{
	person3 p(18);
	cout << "年龄为：" << p.age << endl;
}

void test05()
{
	person3 p1(10);
	person3 p2(20);
	//p2.personaddperson(p1);
	//链式编程思想
	p2.personaddperson(p1).personaddperson(p1).personaddperson(p1);
	cout << "年龄为：" << p2.age << endl;
}

class person4
{
public:
	int age;
	mutable int m_age;    //加上mutable使得在常函数中依然可以改变值的大小
	void showclassname()
	{
		cout << "this is a person4 class" << endl;
	}
	void showpersonage()
	{
		if (this == NULL)   //避免指向为空
		{
			return;
		}
		cout << "age=" << age << endl;
	}
	//在括号后面加上const就会报错，this指针的本质就是指针常量 即指向不可以进行修改，
	//在括号后面加上const使得指向的值也不可以进行修改了，所以会报错
	//常函数
	void showperson() const 
	{
		//age = 100;
		m_age = 100;
	}
};

//空指针访问成员函数
void test06()
{
	person4 * p = NULL;
	p->showclassname();
	p->showpersonage();   //这是一个空操作，因为传入的指针为空
	const person4 pa;     //常对象
	//pa.age = 200;       //报错，常对象指向的值不可以进行修改
	pa.m_age = 200;       //正确有mutable修饰的值可以进行修改
	pa.showperson();      //常对象只能访问常函数
	

}

//int main()
//{
//	//test00();
//	//test01();
//	//test02();
//	//test03();
//	//test04();
//	//test05();
//	test06();
//	system("pause");
//	return 0;
//}