#include<iostream>
using namespace std;

//普通实现

//java界面
//class java
//{
//public:
//	void header()
//	{
//		cout << "首页，公开课，登录，注册......(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内地图......(公共尾部)" << endl;
//	}
//	void lefter()
//	{
//		cout << "java,python,c++,c......(公共左边)" << endl;
//	}
//	void content()
//	{
//		cout << "java课程" << endl;
//	}
//};

//python页面
//class python
//{
//public:
//	void header()
//	{
//		cout << "首页，公开课，登录，注册......(公共头部)" << endl;
//	}
//	void footer()
//	{
//		cout << "帮助中心，交流合作，站内地图......(公共尾部)" << endl;
//	}
//	void lefter()
//	{
//		cout << "java,python,c++,c......(公共左边)" << endl;
//	}
//	void content()
//	{
//		cout << "python课程" << endl;
//	}
//};


//继承的方式  
//语法   class 子类 ：继承方式 父类
//优点   减少重复代码


//公共的部分
class basepage
{
public:
	void header()
	{
		cout << "首页，公开课，登录，注册......(公共头部)" << endl;
	}
	void footer()
	{
		cout << "帮助中心，交流合作，站内地图......(公共尾部)" << endl;
	}
	void lefter()
	{
		cout << "java,python,c++,c......(公共左边)" << endl;
	}
};

//java页面
class java:public basepage    //继承公共部分
{
public:
	void content()
	{
		cout << "java课程" << endl;
	}
};


//python页面
class python:public basepage   //继承公共部分
{
public:
	void content()
	{
		cout << "python课程" << endl;
	}
};

void test31()
{
	cout << "java页面" << endl;
	java ja;
	ja.header();
	ja.lefter();
	ja.content();
	ja.footer();

	cout << "*******************************************" << endl;
	cout << "python界面" << endl;
	python py;
	py.header();
	py.lefter();
	py.content();
	py.footer();
}

//继承规制
//无论何种继承方式，都不可以子类都不可以访问父类中的私有属性
//公共继承，父类中的公共属性和保护属性在子类中依然是公共和保护的
//保护继承，父类中的公共属性和保护属性在子类中都是保护属性
//私有继承，父类中的公共属性和保护属性在子类中都是私有属性

class base1   //父类
{
public:
	int a;
	static int s_a;
protected:
	int b;
private:
	int c;
public:
	base1()  //构造函数
	{
		cout << "父类中的构造函数" << endl;
		a = 100;
	}
	~base1()  //析构函数
	{
		cout << "父类中的析构函数" << endl;
	}
	void func()
	{
		cout << "base1 func" << endl;
	}
	void func(int a)
	{
		cout << "base1 func(int a)" << endl;
	}
	static void func1()
	{
		cout << "base1 static func1" << endl;
	}
	static void func1(int a)
	{
		cout << "base1 static func1(int a)" << endl;
	}
};
int base1::s_a = 100;

class son :public base1   //公共继承
{
public:
	void func()
	{
		a = 10;  //父类中的公共 在子类中依然是公共
		b = 20;  //父类中的保护 在子类中依然是保护
		//c = 30;  //报错 父类中的私有 在子类中不可访问
	}
};

class son1 :protected base1  //保护继承
{
public:
	void func()
	{
		a = 10;  //父类中的公共 在子类中是保护
		b = 20;  //父类中的保护 在子类中是保护
		//c = 30;  //报错 父类中的私有 在子类中不可访问
	}

};

class son2 :private base1  //私有继承
{
public:
	void func()
	{
		a = 10;  //父类中的公共 在子类中是私有
		b = 20;  //父类中的保护 在子类中是私有
		//c = 30;  //报错 父类中的私有 在子类中不可访问
	}

};

void test32()
{
	son s;
	s.a = 100;
	//s.b = 200; //报错  保护属性 类外不可以进行访问
}

void test33()
{
	son1 s;
	//s.a = 100;   //报错 保护属性 类外不可以进行访问
	//s.b = 200;   //报错 保护属性 类外不可以进行访问
}

void test34()
{
	son2 s;
	//s.a = 100;   //报错 私有属性 类外不可以进行访问
	//s.b = 200;   //报错 私有属性 类外不可以进行访问
}

//继承中的对象模型
class son3 :public base1   //父类中的非静态成员属性都会被子类继承，即使不可以进行访问，但是确实是继承过来了
{
public:
	int d;
};

class son4 :protected base1   
{
public:
	int d;
};

class son5 :private base1
{
public:
	int d;
};

void test35()
{
	cout << "sizeof(son3)=" << sizeof(son3) << endl;   //大小为16字节,包含父类中的内容
	cout << "sizeof(son4)=" << sizeof(son4) << endl;
	cout << "sizeof(son5)=" << sizeof(son5) << endl;
}

//继承中的构造和析构函数的顺序
//先父类构造，再子类构造；
//先子类析构，再父类析构。
class son6 :public base1
{
public:
	son6()  //构造函数
	{
		cout << "子类中的构造函数" << endl;
	}
	~son6()  //析构函数
	{
		cout << "子类中的析构函数" << endl;
	}
};

void test36()
{
	son6 s;
}

//继承中同名成员的处理方式
class son7 :public base1
{
public:
	int a;  //子类中的a与父类中的a重名了
	static int s_a;
	static void func1()
	{
		cout << "son7 static func1" << endl;
	}
	son7()   //构造函数初始化
	{
		a = 200;
	}
	void func()
	{
		cout << "son7 func" << endl;
	}
};
int son7::s_a = 200;   //静态成员变量 类内声明 类外初始化


void test37()
{
	son7 s;
	cout << "son   a=" << s.a << endl;
	cout << "base1 a=" << s.base1::a << endl;  //访问父类中的同名成员需要加作用域
	s.func();
	s.base1::func();                           //访问父类中的同名函数需要加作用域
	s.base1::func(10);
	//通过对象访问静态成员变量
	cout << "son   s_a="<<s.s_a<<endl;
	cout << "base1 s_a=" << s.base1::s_a << endl;
	//通过类名访问静态成员变量
	cout << "son   s_a=" << son7::s_a << endl;
	cout << "base1 s_a=" << son7::base1::s_a << endl;
	//通过对象访问
	s.func1();
	s.base1::func1();
	//通过类名访问
	son7::func1();
	son7::base1::func1();
	son7::base1::func1(100);

}

//int main()
//{
//	//test31();
//	//test35();
//	//test36();
//	test37();
//
//	system("pause");
//	return 0;
//
//}