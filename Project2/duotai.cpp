#include<iostream>
using namespace std;

//多态

//动物类
class animal
{
public:
	virtual void speak()   //虚函数   虚函数表指针 虚函数表
	{
		cout << "animal is speaking" << endl;
	}
};

//猫类
class cat :public animal
{ 
	virtual void speak()   //重写的函数会替换掉继承自父类的内容
	{
		cout << "cat is speaking" << endl;
	}
};

//狗类
class dog :public animal
{
	virtual void speak()
	{
		cout << "dog is speaking" << endl;
	}
};

//地址在编译阶段就确定了，所以无论传入什么都是animal
//加上virtual 就实现了地址晚绑定，在运行阶段地址才确定
//动态多态的使用：父类的指针或引用去指向子类的对象
void dospeak(animal& a)    //父类的引用指向子类对象
{
	a.speak();
}

void test51()
{
	cat c;
	dospeak(c);
	dog d;
	dospeak(d);
}

void test52()
{
	cout << "sizeof(animal) =  " << sizeof(animal) << endl;    //不加virtual大小为1即为空类；加上virtual大小为4
}

//多态案例1-计算器
//普通写法
class calculate
{
public:
	int m1;
	int m2;
	int getrusult(string p)
	{
		if (p == "+")
		{
			return m1 + m2;
		}
		else if (p == "-")
		{
			return m1 - m2;
		}
		else if (p == "*")
		{
			return m1 * m2;
		}
		else
		{
			return m1 / m2;
		}
	}

	void fuzhi(int a, int b)
	{
		m1 = a;
		m2 = b;
	}
};

void test53()
{
	int a;
	int b;
	calculate c;
	cout << "请输入两个整数" << endl;
	cin >> a >> b;
	c.fuzhi(a, b);
	cout << "两个整数相加为：" << c.getrusult("+") << endl;
	cout << "两个整数相减为：" << c.getrusult("-") << endl;
	cout << "两个整数相乘为：" << c.getrusult("*") << endl;
	cout << "两个整数相除为：" << c.getrusult("/") << endl;
}

//多态写法
//抽象计算器
class abstractcalculate
{
public:
	int m1;
	int m2;
	virtual int getresult()   //虚函数
	{
		return 0;
	}
};

//加法
class addcalculate:public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 + m2;
	}
};

//减法
class subcalculate :public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 - m2;
	}
};

//乘法
class chengcalculate :public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 * m2;
	}
};

//除法
class chucalculate :public abstractcalculate
{
public:
	virtual int getresult()
	{
		return m1 / m2;
	}
};

void test54()
{
	int a;
	int b;
	cout << "请输入两个整数" << endl;
	cin >> a >> b;

	abstractcalculate* ab = new addcalculate;   //new开辟的内存空间是一个指针  父类的指针指向子类对象
	ab->m1 = a;
	ab->m2 = b;
	cout << "两个整数相加为：" << ab->getresult() << endl;
	delete ab;

	ab  = new subcalculate;
	ab->m1 = a;
	ab->m2 = b;
	cout << "两个整数相减为：" << ab->getresult() << endl;
	delete ab;

	ab = new chengcalculate;
	ab->m1 = a;
	ab->m2 = b;
	cout << "两个整数相乘为：" << ab->getresult() << endl;
	delete ab;

	ab = new chucalculate;
	ab->m1 = a;
	ab->m2 = b;
	cout << "两个整数相除为：" << ab->getresult() << endl;
	delete ab;

}

//纯虚函数和抽象类
//只要类中有一个纯虚函数，那么这个类就是抽象类
//特点：抽象类无法实例化对象
//      子类必须重写抽象类中的纯虚函数，否则也是抽象类
class base4
{
public:
	virtual void func() = 0;   //纯虚函数
};

class son9 :public base4
{
public:
	virtual void func()   //重写纯虚函数，否则也是抽象类
	{
		cout << "func 调用" << endl;
	}
};

void test55()
{
	//base4 b;   //报错 抽象类无法实例化对象
	//son9 s;
	base4* b = new son9;   //父类指针指向子类对象
	b->func();
}

//多态案例2-制作饮品
//抽象饮料
class abstractdrink
{
public:
	virtual void boil() = 0;   //纯虚函数
	virtual void brew() = 0;
	virtual void pourincup() = 0;
	virtual void putsoming() = 0;
	void makedrink()
	{
		boil();
		brew();
		pourincup();
		putsoming();
	}
};

class coffe :public abstractdrink
{
public:
	virtual void boil()
	{
		cout << "煮水" << endl;
	}
	virtual void brew()
	{
		cout << "冲咖啡" << endl;
	}
	virtual void pourincup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void putsoming()
	{
		cout << "加入糖和牛奶" << endl;
	}

};

class tea :public abstractdrink
{
public:
	virtual void boil()
	{
		cout << "煮水" << endl;
	}
	virtual void brew()
	{
		cout << "冲茶" << endl;
	}
	virtual void pourincup()
	{
		cout << "倒入杯中" << endl;
	}
	virtual void putsoming()
	{
		cout << "加入柠檬" << endl;
	}

};

void test56()
{
	abstractdrink* ab = new coffe;  //父类指针指向子类
	ab->makedrink();
	delete ab;

	cout << "----------------------" << endl;
	ab = new tea;
	ab->makedrink();
	delete ab;
}

//虚析构和纯虚析构
class animal1
{
public:
	virtual void speak() = 0;   //纯虚函数
	animal1()
	{
		cout << "animal1 的构造函数" << endl;
	}
	//virtual ~animal1()         //虚析构   解决父类指针释放子类对象的功能
	//{
	//	cout << "animal1 的析构函数" << endl;
	//}

	virtual ~animal1() = 0;   //纯虚析构  内部声明外部实现    解决父类指针释放子类对象的功能
};

//外部定义
animal1::~animal1()
{
	cout << "animal1 的析构函数" << endl;
}

class cat1 :public animal1
{
public:
	string* st;
	cat1(string s)   //构造函数
	{
		cout << "cat1 的构造函数" << endl;
		st = new string(s);  //new返回的是指针
	}
	virtual void speak()     //子类重写纯虚函数
	{
		cout << *st << " " << "cat is speaking" << endl;
	}
	~cat1()   //析构函数 用于释放
	{
		if (st != NULL)
		{
			cout << "cat1 的析构函数" << endl;
			delete st;   //释放 然后置空
			st = NULL;
		}
	}
};

void test57()
{
	animal1* a = new cat1("Tom");    //父类的指针指向子类
	a->speak();
	//父类指针无法调用子类析构 需要在父类析构中加上virtual,将其变为虚析构，这样就可以释放子类了
	//利用纯虚析构也可以实现上述功能，不过对于纯虚析构需要类外进行定义
	delete a;
}

//多态案例3-电脑组装
//抽象cpu
class cpu
{
public:
	virtual void calculate() = 0;   //纯虚函数
};

//抽象gpu
class gpu
{
public:
	virtual void display() = 0;   //纯虚函数
};

//抽象memory
class memory
{
public:
	virtual void storage() = 0;   //纯虚函数
};

class computer
{
public:
	computer(cpu* c1, gpu* g1, memory* m1)  //构造函数
	{
		c = c1;
		g = g1;
		m = m1;
	}
	void dowork()
	{
		c->calculate();   //父类指针调用子类
		g->display();
		m->storage();
	}

	~computer()   //析构函数 释放
	{
		if (c != NULL)
		{
			delete c;
			c = NULL;
		}
		if (g != NULL)
		{
			delete g;
			g = NULL;
		}
		if (m != NULL)
		{
			delete m;
			m = NULL;
		}
	}
private:
	cpu* c;
	gpu* g;
	memory* m;
};

//inter
class intercpu :public cpu
{
public:
	virtual void calculate()   //重写虚函数
	{
		cout << "inter cpu" << endl;
	}
};

class intergpu :public gpu
{
public:
	virtual void display()   //重写虚函数
	{
		cout << "inter gpu" << endl;
	}
};

class intermemory :public memory
{
public:
	virtual void storage()   //重写虚函数
	{
		cout << "inter memory" << endl;
	}
};

//amd
class amdcpu :public cpu
{
public:
	virtual void calculate()   //重写虚函数
	{
		cout << "amd cpu" << endl;
	}
};

class amdgpu :public gpu
{
public:
	virtual void display()   //重写虚函数
	{
		cout << "amd gpu" << endl;
	}
};

class amdmemory :public memory
{
public:
	virtual void storage()   //重写虚函数
	{
		cout << "amd memory" << endl;
	}
};

void test58()
{
	//创建零件
	cpu* c = new intercpu;   //父类指针指向子类
	gpu* g = new intergpu;
	memory* m = new intermemory;

	//创建一个电脑
	computer *cu = new computer(c, g, m);  //返回指针
	cu->dowork();
	delete cu;

	cout << "-------------------------------" << endl;

	//创建零件
	cpu* c1 = new amdcpu;   //父类指针指向子类
	gpu* g1 = new amdgpu;
	memory* m1 = new amdmemory;

	//创建一个电脑
	computer* cu1 = new computer(c1, g1, m1);  //返回指针
	cu1->dowork();
	delete cu1;

	cout << "-------------------------------" << endl;

	//创建零件
	cpu* c2 = new intercpu;   //父类指针指向子类
	gpu* g2 = new amdgpu;
	memory* m2 = new intermemory;

	//创建一个电脑
	computer* cu2 = new computer(c2, g2, m2);  //返回指针
	cu2->dowork();
	delete cu2;

}

//int main()
//{
//	//test51();
//	//test52();
//	//test53();
//	//test54();
//	//test55();
//	//test56();
//	//test57();
//	test58();
//
//	system("pause");
//	return 0;
//}