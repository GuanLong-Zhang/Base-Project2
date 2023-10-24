#include <iostream>
using namespace std;

//对象特性

class person
{
public:
	int age;
	int* height;
	//构造函数实现初始化
	person()      //无参的构造函数  (默认构造)   创建对象的时候自动调用，而且只调用一次   可以有参数 也可以无参数
	{
		cout << "无参构造函数的调用" << endl;
	}
	person(int a)      //有参的构造函数  单个的参数 
	{
		age = a;
		cout << "有参构造函数的调用" << endl;
	}
	person(int a,int b)      //有参的构造函数     多个参数
	{
		height = new int(b);  //通过new在堆区开辟内存空间  height表示存放的地址
		age = a;
		cout << "有参构造函数的调用" << endl;
	}
	person(const person &p)  //拷贝构造函数
	{
		age = p.age;
		//height = p.height;   //这行代码就是编译器默认实现浅拷贝的代码，对于堆区数据存在问题
		cout << "拷贝构造函数的调用" << endl;
		//深拷贝
		height = new int(*p.height);    //重新在堆区开辟一个内存空间，防止被重复释放


	}
	//析构函数实现清理   在函数释放时会被自动调用   一定没有参数
	~person()
	{
		//将堆区的数据进行释放
		if (height != NULL)
		{
			delete height;
			height = NULL;   //防止野指针的出现
		}
		cout << "析构函数的调用" << endl;
	}
};

void test()
{
	//括号法
	//person p1;       //无参构造调用   创建一个局部对象   存放在栈区 运行完就释放掉了，所以即调用了构造函数也调用了析构函数
	//person p2(10);   //有参构造调用
	//person p3(p2);   //拷贝构造调用

	//注意事项
	//在使用括号法调用无参构造函数的时候不要加括号，因为编译器会把这种形式当作函数声明
	//cout << "p2的age为：" << p2.age << endl;
	//cout << "p3的age为：" << p3.age << endl;

	//显示法
	//person p1;
	//person p2 = person(10);   
	//person p3 = person(p2);

	//person(10);    //person(10)是匿名对象 当前执行后，系统会立即回收匿名对象
	//person(p2);    //不要利用拷贝构造函数来初始化匿名对象,会报错

	//隐式转换法
	//person p1;
	//person p2 = 10;
	//person p3 = p2;

	

}

void test0()
{
	//拷贝构造函数的调用时机
	//1、使用一个创建好的对象来初始化一个新的对象
	person p2(10);
	person p3(p2);
}

void dowork(person p)
{

}

void test1()
{
	//拷贝构造函数的调用时机
	//2、值传递的方式给函数参数赋值
	person p;
	dowork(p);

}

person dowork1()
{
	person p1;
	cout << "dowork中的地址"<<(int)&p1 << endl;
	return p1;
}

void test2()
{
	//拷贝构造函数的调用时机
	//3、值方式返回局部变量    
	//备注：编译器开了返回值优化RVO,所以test2和dowork1返回的地址一样,这样就没有调用拷贝构造函数了
	person p = dowork1();
	cout << "test2中的地址 "<<(int)&p << endl;
}

//c++构造函数调用规则
//编译器至少为一个类创建3个函数 无参构造函数(空实现) 析构函数(空实现) 拷贝构造函数(值拷贝)

void test3()
{
	person p;
	p.age = 18;
	person p1(p);  //即使自己没有定义拷贝构造函数，但是编译器会默认创建，然后进行值拷贝
	cout << "p1的年龄为：" << p1.age << endl;
}

void test4()
{
	person p(28);    //当自己定义了有参构造函数，那么编译器就不会创建无参构造函数了，但是依然会创建拷贝构造函数进行值拷贝
	person p1(p);
	cout << "p1的年龄为：" << p1.age << endl;
}

//当自己定义了拷贝构造函数，那么编译器就不会去创建别的构造函数了，(有参构造函数 和 无参构造函数)

//深拷贝 和 浅拷贝
void test5()
{
	person p(38);
	cout << "p的年龄为：" << p.age << endl;
	person p1(p);   //由编译器自动生成的拷贝构造函数，进行值拷贝都是浅拷贝   p1先释放 p后释放 先进后出
	cout << "p1的年龄为：" << p1.age << endl;
}

void test6()
{
	person p(38,166);
	cout << "p的年龄为：" << p.age << endl;
	cout << "p的身高为：" << *p.height<< endl;   //p.height表示数据存放的地址，如果需要具体的值需要*p.height
	person p1(p);   //   先释放p1，再释放p   浅拷贝存在的问题为堆区的内存被重复释放 利用深拷贝可以解决这一问题
	cout << "p1的年龄为：" << p1.age << endl;
	cout << "p1的身高为：" << *p1.height << endl;
}

//int main()
//{
//	//test();
//	//test0();
//	//test1();  
//	//test2();
//	//test3();
//	//test4();
//	//test5();
//	test6();
//	//person p;  //此处只调用了构造函数，当点任意键时才会调用析构函数，也就是说只有程序释放掉才调用析构函数
//	system("pause");
//	return 0;
//
//}
