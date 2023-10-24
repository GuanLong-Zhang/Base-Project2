//点和圆的关系
# include<iostream>
using namespace std;
# include "point.h"
# include"circle.h"

//将定义的俩个class进行分文件编写  .h文件中放声明  .cpp中放功能实现

//class circle
//{
//private:
//	int x;  //圆心
//	int y;
//	int r;  //半径
//public:
//	void set(int a, int b, int c)
//	{
//		x = a;
//		y = b;
//		r = c;
//	}
//	int getx()
//	{
//		return x;
//	}
//	int gety()
//	{
//		return y;
//	}
//	int getr()
//	{
//		return r;
//	}
//};

//class point
//{
//private:
//	int x;   //点的坐标
//	int y;
//public:
//	void set(int a, int b)
//	{
//		x = a;
//		y = b;
//	}
//	int getx()
//	{
//		return x;
//	}
//	int gety()
//	{
//		return y;
//	}
//};

string panduan(circle a, point b)
{
	double juli = sqrt(pow((a.getx() - b.getx()),2) + pow((a.gety() - b.gety()),2));   //pow(3,2)表示3的2次方
	if (a.getr() == juli)
	{
		return "点在圆上";
	}
	else if (a.getr() > juli)
	{
		return "点在圆内";
	}
	else
	{
		return "点在圆外";
	}
}

//int main()
//{
//	circle c;
//	point  p;
//	c.set(0, 0, 5);   //输入圆心 x y 半径r
//	p.set(3, 4);      //输入点的坐标 x y  (1,1) (3,4) (5,5)
//	cout << "圆心坐标为：" << "<"<<c.getx() << "," << c.gety()<<">" << endl;
//	cout << "圆的半径为：" << c.getr() << endl;
//	cout << "点的坐标为：" << "<" << p.getx() << "," << p.gety() << ">" << endl;
//	cout<<"点与圆的关系："<<panduan(c, p)<<endl;
//
//}