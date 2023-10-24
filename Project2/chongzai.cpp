# include<iostream>
using namespace std;

//运算符重载

//加号运算符重载
//左移运算符重载
class car
{
public:
	int m_a;
	int m_b;

	//成员函数重载加号
	//car operator+(car& p)  //car表示返回值的类型
	//{
	//	car temp;
	//	temp.m_a = m_a + p.m_a;
	//	temp.m_b = m_b + p.m_b;
	//	return temp;
	//}

};

//全局函数重载加号
car operator+(car& c1, car& c2)
{
	car temp;
	temp.m_a = c1.m_a + c2.m_a;
	temp.m_b = c1.m_b + c2.m_b;
	return temp;
}

car operator+(car& c1, int num)
{
	car temp;
	temp.m_a = c1.m_a + num;
	temp.m_b = c1.m_b + num;
	return temp;
}

//全局函数重载左移运算符
ostream& operator<<(ostream& cout, car& p)
{
	cout << "m_a=" << p.m_a << endl;
	cout << "m_b=" << p.m_b <<endl;	
	return cout;
}

void test20()
{
	car p1;
	p1.m_a = 10;
	p1.m_b = 20;
	car p2;
	p2.m_a = 30;
	p2.m_b = 40;

	car p3 = p1 + p2; 
	car p4 = p1 + 100;
	//car p3 = p1.operator+(p2);  //成员函数重载+的本质
	//car p3 = operator+(p1, p2); //全局函数重载+的本质

	cout << "p3.m_a=" << p3.m_a << endl;
	cout << "p3.m_b=" << p3.m_b << endl;

	cout << "p4.m_a=" << p4.m_a << endl;
	cout << "p4.m_b=" << p4.m_b << endl;

	cout << p1 << p2;   //左移运算符重载应用
}

//原始递增的操作
void test21()
{
	int a = 10;
	int b = 20;
	cout << ++a << endl;  //11
	cout << a << endl;    //11

	cout << b++ << endl;  //20
	cout << b << endl;    //21

}

//递增运算符重载
class car1
{
	friend ostream& operator<<(ostream& cout, car1& p);
public:
	car1()   //构造函数
	{
		num = 2;
	}
	
	//重载前置++运算符  返回引用是为了一直指向同一个数据进行递增操作
	car1& operator++()
	{
		//先++再运算
		num++;
		return *this;

	}

	//重载后置++运算符 
	car1& operator++(int)   //int为占位参数，为了区分前置++和后置++  后置返回值
	{
		car1 temp = * this;   //*this为本身
		num++;
		return temp;

	}

	//重载前置--运算符
	car1& operator--()
	{
		num--;
		return *this;
	}

	//重载后置--运算符
	car1& operator--(int)
	{
		car1 temp = *this;
		num--;
		return temp;
	}

private:
	int num;
};

ostream& operator<<(ostream& cout, car1& p)   //左移运算符重载
{
	cout << p.num << endl;
	return cout;
}


void test22()
{
	car1 cara;
	cout << ++(++cara);
	cout << cara;
}

void test23()
{
	car1 cara1;
	cout<<cara1++;
	cout << cara1;
}

void test24()
{
	car1 cara2;
	cout << --(--cara2);
	cout << cara2;
}

void test25()
{
	car1 cara2;
	cout << cara2--;
	cout << cara2;
}

//赋值运算符重载
class car2
{
public:
	int* age2;
	car2(int age)  //构造函数
	{
		age2 = new int(age);   //age2存放的是一个地址 利用new开辟的内存返回的是一个指针 ()内的内容是具体的值
	}
	~car2()   //析构函数 释放空间 默认无参
	{
		if (age2 != NULL)
		{
			delete age2;   //释放之后 然后置空
			age2 = NULL;
		}
	}
	car2& operator=(car2& p)  //赋值重载
	{
		if (age2 != NULL)   //先释放空间，再进行开辟新的空间
		{
			delete age2;
			age2 = NULL;
		}
		age2 = new int(*p.age2);  //深拷贝
		return *this;  //利用*this返回本身
	}
};

void test26()
{
	car2 c2(18);   //默认调用构造函数，所以需要进行赋初值的操作，赋值为18
	car2 c3(20);
	car2 c4(30);
	c4 = c3 = c2;   // 浅拷贝 赋值结束后，进行析构的释放，先释放c3 再释放c2,会报错，内存重复释放

	cout << "c2年龄为："<< *c2.age2 << endl;   //要输出值需要加*，进行解引用
	cout << "c3年龄为："<< *c3.age2 << endl;
	cout << "c4年龄为：" << *c4.age2 << endl;

}

//关系运算符重载  ==  !=
class car3
{
public:
	string name;
	int age;
	car3(string a, int b)   //有参构造赋初值
	{
		name = a;
		age = b;
	}
	bool operator==(car3& p)    //重载==
	{
		if (this->name == p.name && this->age == p.age)
		{
			return true;
		}
		return false;
	}
	bool operator!=(car3& p)    //重载!=
	{
		if (this->name == p.name && this->age == p.age)
		{
			return false;
		}
		return true;
	}

};

void test27()
{
	car3 cc("小明", 20);
	car3 cc1("小红", 20);
	//cout << "姓名："<< cc.name << endl;
	//cout << "年龄："<< cc.age << endl;
	if (cc == cc1)
	{
		cout << "两者信息相同" << endl;
	}
	else
	{
		cout << "两者信息不同" << endl;
	}
	if (cc != cc1)
	{
		cout << "两者信息不同" << endl;
	}
	else
	{
		cout << "两者信息相同" << endl;
	}
}

//函数调用重载
class car4
{
public:
	void operator()(string a)   //函数调用重载
	{
		cout << a << endl;
	}

	void operator()(int a, int b)
	{
		cout<< a + b <<endl;
	}
};

void c1(string a)
{
	cout << a << endl;
}

void test28()
{
	car4 c;
	c("hello world!");    //函数调用重载很像函数调用，所以称为仿函数
	c1("hello world!");   //常规函数调用
	c(10, 20);
	//匿名对象  没有显示的去定义对象，而是采用类名()的形式来代替对象
	car4()(20, 30);
}

//int main()
//{
//	//test20();
//	//test21();
//	//test22();
//	//test23();
//	//test24();
//	//test25();
//	//test26();
//	//test27();
//	test28();
//
//	system("pause");
//	return 0;
//}