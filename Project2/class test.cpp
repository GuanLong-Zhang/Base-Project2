# include<iostream>
using namespace std;

//设计一个立方体类
class Cube
{
private:
	int ml;
	int mw;
	int mh;
public:
	void set(int a, int b, int c)
	{
		ml = a;
		mw = b;
		mh = c;
	}
	int getml()
	{
		return ml;
	}
	int getmw()
	{
		return mw;
	}
	int getmh()
	{
		return mh;
	}
	int area()
	{
		return 2 * ml * mw + 2 * ml * mh + 2 * mw * mh;
	}
	int volume()
	{
		return ml * mw * mh;
	}
	string compare(int a, int b)
	{
		if (a == b)
		{
			return "相等" ;
		}
		else
		{
			return "不相等" ;
		}
	}
	//成员函数只需要传递一个参数
	bool iscompare(Cube a)
	{
		if (mh == a.getmh() && ml == a.getml() &&  mw == a.getmw())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

string compare(int a, int b)
{
	if (a == b)
	{
		return "相等";
	}
	else
	{
		return "不相等";
	}
}

//全局函数需要传递两个参数
bool iscompare(Cube a, Cube b)   //判断两个立方体是否相等 就是判断长 宽 高 是否都相等
{
	if (a.getmh() == b.getmh() && a.getml() == b.getml() && a.getmw() == b.getmw())
	{
		return true;
	}
	else
	{
		return false;
	}
}

//int main()
//{
//	Cube a,b;
//	a.set(3, 4, 5);
//	b.set(3, 4, 5);
//	int aa = a.area();
//	int av = a.volume();
//	int ba = b.area();
//	int bv = b.volume();
//	cout<<"a的面积为："<<aa<<endl;
//	cout<<"a的体积为："<<av<<endl;
//	cout << "b的面积为：" <<ba<< endl;
//	cout << "b的体积为：" <<bv<< endl;
//	
//	cout << "全局函数比较" << endl;
//	bool ret = iscompare(a, b);
//	if (ret)
//	{
//		cout << "a和b相等" << endl;
//	}
//	else
//	{
//		cout << "a和b不相等" << endl;
//	}
//	cout << "a和b的面积是否相等:" << compare(aa, ba) << endl;
//	cout << "a和b的体积是否相等:" << compare(av, bv) << endl;
//
//	cout << "成员函数比较" << endl;
//	bool ret1 = a.iscompare(b);
//	if (ret1)
//	{
//		cout << "a和b相等" << endl;
//	}
//	else
//	{
//		cout << "a和b不相等" << endl;
//	}
//	cout << "a和b的面积是否相等:"<< a.compare(aa, ba)<<endl;
//	cout << "a和b的体积是否相等:" << a.compare(av, bv) << endl;
//
//	system("pause");
//	return 0;
//}
