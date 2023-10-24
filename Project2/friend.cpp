# include<iostream>
using namespace std;

class building;

//类作友元
class goodgay
{
public:
	building * g;
	goodgay();      //类内声明 类外定义
	void visit();
	void visit1();   
};


class building
{
	friend void goodgay::visit1();   //friend修饰成员函数，这样就可以访问私有属性了，但是需要注意goodgay的成员函数必须先定义
	//friend class goodgay;   //friend修饰类的声明，这样就可以访问私有属性了
	friend void goodfirend(building* building);   //friend修饰全局函数的声明，这样就可以访问私有属性了
public:
	string keting;
	building()   //构造函数赋初值
	{
		keting = "客厅";
		woshi = "卧室";
	}
private:
	string woshi;

};

goodgay::goodgay()   //构造函数
{
	g = new building;   //在堆区开辟内存空间
}

void goodgay::visit() //必须放到building之后，不然会显示使用了未定义的building
{
	cout << "好基友类去访问建筑物类中的公共属性：" << g->keting << endl;

	//cout << "好基友类去访问建筑物类中的私有属性：" << g->woshi << endl;     //要访问必须将好基友类变为友元类
}

//成员函数作友元函数
void goodgay::visit1()
{
	cout << "成员函数去访问建筑物类中的公共属性：" << g->keting << endl;

	cout << "成员函数去访问建筑物类中的私有属性：" << g->woshi << endl;
}

//全局函数作友元函数
void goodfirend(building* building)
{
	cout << "全局函数对公共属性进行访问：" << building->keting << endl;

	cout << "全局函数对私有属性进行访问：" << building->woshi<< endl;
}

void test11()
{
	building a;
	goodfirend(&a);
}

void test12()
{
	goodgay b;
	b.visit();
}

void test13()
{
	goodgay c;
	c.visit1();
}

//int main()
//{
//	//test11();
//	//test12();
//	//test13();
//
//	system("pause");
//	return 0;
//}