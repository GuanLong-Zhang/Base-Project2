# include<iostream>
using namespace std;

//多继承（实际开发中不建议使用）
class base2
{
public:
	int a;
	base2()   //构造函数赋初值
	{
		a = 100;
	}
};

class base3
{
public:
	int a;
	int b;
	base3()   
	{
		a = 150;
		b = 200;
	}
};

//多继承
class son8 :public base2, public base3
{
public:
	int c;
	int d;
	son8()
	{
		c = 300;
		d = 400;
	}
};

void test41()
{
	son8 s;
	cout << "sizeof s = " << sizeof(s) << endl;   //包含base2,base3中的内容
	cout << "s.base2::a = " << s.base2::a << endl;   //对于重名的需要加作用域
	cout << "s.base3::a = " << s.base3::a << endl;
}

//菱形继承
class animal
{
public:
	int age;

};

class sheep :virtual public animal    //virtual 虚继承
{

};

class tuo :virtual public animal
{

};

class sheeptuo :public sheep, public tuo
{

};

void test42()
{
	sheeptuo st;
	//两个父类有相同的数据，需要加作用域区分
	st.sheep::age = 18;
	st.tuo::age = 28;
	cout << "st.sheep::age = " << st.sheep::age << endl;
	cout << "st.tuo::age = " << st.tuo::age << endl;
	//利用虚继承的方式可以解决资源浪费的问题
	cout << "st.age = " << st.age << endl;

}

//int main()
//{
//	//test41();
//	test42();
//
//	system("pause");
//	return 0;
//}